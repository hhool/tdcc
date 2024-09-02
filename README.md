# JAVA Jni Wrapper for Tiandi Camera SDK

## Introduction

This is a Java JNI wrapper for the Tiandi Camera SDK. It provides a Java interface to the Tiandi Camera SDK.

Target platform: Windows x64 and Linux x64 (centos 7.8)

## Prerequisites

- JDK 1.8 latest version [Download](https://www.oracle.com/java/technologies/javase-jdk8-downloads.html)
- Maven latest version [Download](https://dlcdn.apache.org/maven/maven-3/3.9.9/binaries/apache-maven-3.9.9-bin.zip)
- CMake 3.22.0 or later [Download](https://cmake.org/download/)
- Visual Studio 2015 (Windows) [Download](https://visualstudio.microsoft.com/downloads/)
- GCC (Linux)
- VSCODE [Download](https://code.visualstudio.com/)
- Maven for Java [Download](https://maven.apache.org/download.cgi)
- -Extension Pack for Java [Download](https://marketplace.visualstudio.com/items?itemName=vscjava.vscode-java-pack)

## Build

### Windows

1. Open a command prompt and navigate to the project directory.

2. Build native library
   Run the following commands to build the project:

   ```shell
   cmake -S .\jni -B .\out -G "Visual Studio 14 2015 Win64" -DCMAKE_BUILD_TYPE="Release"
   cmake --build .\out --config Release --target install
   ```

   The native library is located in the `out` directory.

3. Package the native library into a JAR file
   Run the following commands to package the native library into a JAR file:

   ```shell
   mvn clean package
   ```

   The JAR file is located in the `target` directory.

### Linux

1. Open a terminal and navigate to the project directory.

2. Build native library.
   Run the following command to build the project:

   ```shell
   cmake -S .\jni -B .\out -G "Unix Makefiles" -DCMAKE_BUILD_TYPE="Release"
   cmake --build .\out --config Release --target install
   ```

3. Package the native library into a JAR file
   Run the following commands to package the native library into a JAR file:

   ```shell
   mvn clean package
   ```

   The build output is located in the `target` directory.

## Gnereate JNI Header File

1. Open a terminal and navigate to the project directory.
2. Run the following command to generate the JNI header file:

   ```shell
   cd src\main\java
   javah -jni -d ..\..\..\jni -encoding utf-8 com.gshx.camera.tiandi.NativeTiandi
   ```

   or

   ```shell
   cd jni
   javah -cp ..\target\classes -o native_tiandi_jni.h -encoding utf-8  com.gshx.camera.tiandi.NativeTiandi
   ```

   The JNI header file is located in the `jni\` directory.

## Usage

1. Add the following dependency to your Maven project:

   ```xml
   <dependency>
       <groupId>com.gshx.camera</groupId>
       <artifactId>tdcc</artifactId>
       <version>1.0-SNAPSHOT</version>
   </dependency>
   ```

2. Load the library in your Java code:

   ```java
    System.loadLibrary("tiandi");
    ```

3. Use the Tiandi Camera SDK in your Java code:

   ```java
   TiandiCamera camera = new TiandiCamera();
   camera.init();
   camera.open();
   camera.start();
   camera.stop();
   camera.close();
   camera.release();
   ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

[How to Package JNI Shared Library into Jar File](https://www.dynamsoft.com/codepool/package-jni-shared-library-jar-file.html)