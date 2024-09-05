package com.gshx.camera;

import com.gshx.camera.tiandi.NVSDKClient;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        NVSDKClient client = new NVSDKClient();
        client.Dispose();
        client = null;
    }

    public static void test() {
        System.out.println("Test");
    }
}