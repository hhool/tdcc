package com.gshx.camera;

import com.gshx.camera.tiandi.NativeTiandi;

public class Main {
    private static NativeTiandi nativeTiandi = new NativeTiandi();
    public static void main(String[] args) {
        System.out.println("Hello world!");
        nativeTiandi.DestroyInstance();
        nativeTiandi = null;
    }

    public static void test() {
        System.out.println("Test");
    }
}