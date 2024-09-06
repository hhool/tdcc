import org.junit.Test;

import com.gshx.camera.tiandi.NVSDKClient;

public class TestNativeStruct {
    @Test
    public void test() {
        System.out.println("Test");
    }

    @Test
    public void test2() {
        NVSDKClient client = new NVSDKClient();

        client.TestSDK();

        client.Dispose();
        client = null;
    }
}
