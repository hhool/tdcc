package com.gshx.camera;

import com.gshx.camera.tiandi.NVSDKClient;

public class Main {
    private static NVSDKClient NVSDKClient = new NVSDKClient();
    public static void main(String[] args) {
        System.out.println("Hello world!");
        NVSDKClient.Dispose();
        NVSDKClient = null;
    }

    public static void test() {
        System.out.println("Test");
    }
}