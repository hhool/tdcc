package com.gshx.camera.tiandi;

public class NativeTiandi {
    private long nativePtr = 0;

    static {
        try {
            if (NativeLoader.load()) {
                System.out.println("Successfully loaded Tiandi_jni.");
            }
        } catch (Exception e) {
            // TODO(hhool): Auto-generated catch block
            e.printStackTrace();
        }
    }

    public NativeTiandi() {
        nativePtr = nativeCreateInstance();
    }

    public void DestroyInstance() {
        nativeDestroyInstance(nativePtr);
    }


    private native long nativeCreateInstance();
    private native void nativeDestroyInstance(long ptr);
}
