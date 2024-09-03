package com.gshx.camera.tiandi;

import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.security.DigestInputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class NativeLoader {
    private static synchronized boolean loadNativeLibrary(String path, String name) {
        File libPath = new File(path, name);
        if (libPath.exists()) {
            try {
                System.load(new File(path, name).getAbsolutePath());
                return true;
            } catch (UnsatisfiedLinkError e) {
                System.err.println(e);
                return false;
            }

        } else
            return false;
    }

    private static boolean extractResourceFiles(String dbrNativeLibraryPath, String dbrNativeLibraryName,
            String tempFolder) throws IOException {
        String[] filenames = null;
        if (Utils.isWindows()) {
            filenames = new String[] {"OsCore.dll", "DOME_PLUS.dll", "DOME_PELCO_P.dll", "DOME_PELCO_D.dll", "PTZ_PELCO_D.dll", "PTZ_PELCO_P.dll", "PTZ_TC615_P.dll", "pthreadVC2.dll", "tiandi_jni.dll", "NVDSDK.dll", "NetAdmin.dll"};
        }
        else if (Utils.isLinux()) {
            filenames = new String[] {"libnvdsdk.so", "libossdk.so", "libtiandi_jni.so"};
        }
        else {
            throw new IOException("Unsupported OS.");
        }
        
        boolean ret = true;
        
        for (String file : filenames) {
            ret &= extractAndLoadLibraryFile(dbrNativeLibraryPath, file, tempFolder);
        }
        
        return ret;
    }

    public static boolean load() throws Exception {

        // Load the os-dependent library from the jar file
        String dbrNativeLibraryName = System.mapLibraryName("tiandi_jni");

        String dbrNativeLibraryPath = "/com/gshx/camera/tiandi/native";
        if (Utils.isWindows()) {
            dbrNativeLibraryPath = "/com/gshx/camera/tiandi/native/win64";
        }
        else if (Utils.isLinux()) {
            dbrNativeLibraryPath = "/com/gshx/camera/tiandi/native/linux64";
        } else {
            throw new Exception("Unsupported OS.");
        }
        if (NVSDKClient.class.getResource(dbrNativeLibraryPath + "/" + dbrNativeLibraryName) == null) {
            throw new Exception("Error loading native library: " + dbrNativeLibraryPath + "/" + dbrNativeLibraryName);
        }

        // Temporary library folder
        String tempFolder = new File(System.getProperty("java.io.tmpdir")).getAbsolutePath();

        // Extract resource files
        return extractResourceFiles(dbrNativeLibraryPath, dbrNativeLibraryName, tempFolder);
    }

    static String md5sum(InputStream input) throws IOException {
        BufferedInputStream in = new BufferedInputStream(input);

        try {
            MessageDigest digest = java.security.MessageDigest.getInstance("MD5");
            DigestInputStream digestInputStream = new DigestInputStream(in, digest);
            for (; digestInputStream.read() >= 0;) {

            }
            ByteArrayOutputStream md5out = new ByteArrayOutputStream();
            md5out.write(digest.digest());
            return md5out.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new IllegalStateException("MD5 algorithm is not available: " + e);
        } finally {
            in.close();
        }
    }

    private static boolean extractAndLoadLibraryFile(String libFolderForCurrentOS, String libraryFileName,
            String targetFolder) {
        String nativeLibraryFilePath = libFolderForCurrentOS + "/" + libraryFileName;

        String extractedLibFileName = libraryFileName;
        File extractedLibFile = new File(targetFolder, extractedLibFileName);

        try {
            if (extractedLibFile.exists()) {
                // test md5sum value
                String md5sum1 = md5sum(NVSDKClient.class.getResourceAsStream(nativeLibraryFilePath));
                String md5sum2 = md5sum(new FileInputStream(extractedLibFile));

                if (md5sum1.equals(md5sum2)) {
                    return loadNativeLibrary(targetFolder, extractedLibFileName);
                } else {
                    // remove old native library file
                    boolean deletionSucceeded = extractedLibFile.delete();
                    if (!deletionSucceeded) {
                        throw new IOException(
                                "failed to remove existing native library file: " + extractedLibFile.getAbsolutePath());
                    }
                }
            }

            // Extract file into the current directory
            InputStream reader = NVSDKClient.class.getResourceAsStream(nativeLibraryFilePath);
            FileOutputStream writer = new FileOutputStream(extractedLibFile);
            byte[] buffer = new byte[1024];
            int bytesRead = 0;
            while ((bytesRead = reader.read(buffer)) != -1) {
                writer.write(buffer, 0, bytesRead);
            }

            writer.close();
            reader.close();

            if (!System.getProperty("os.name").contains("Windows")) {
                try {
                    Runtime.getRuntime().exec(new String[] { "chmod", "755", extractedLibFile.getAbsolutePath() })
                            .waitFor();
                } catch (Throwable e) {
                }
            }

            return loadNativeLibrary(targetFolder, extractedLibFileName);
        } catch (IOException e) {
            System.err.println(e.getMessage());
            return false;
        }

    }
}
