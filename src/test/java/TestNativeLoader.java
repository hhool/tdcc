import java.sql.Date;
import java.text.SimpleDateFormat;
import java.util.List;

import org.junit.Test;
import com.gshx.camera.tiandi.IDecComRecvNotify;
import com.gshx.camera.tiandi.ITDPostMessageNotify;
import com.gshx.camera.tiandi.NVSDKClient;
import com.gshx.camera.tiandi.TNVSItemEx;

public class TestNativeLoader {
    @Test
    public void test() {
        System.out.println("Test");
    }

    @Test
    public void test2() {
        NVSDKClient client = new NVSDKClient();
        client.Dispose();
        client = null;
    }

    @Test
    public void test3() {
        NVSDKClient client = new NVSDKClient();
        client.ClientStartup(90000);
        client.ClientCleanup();
        client.Dispose();
        client = null;
    }

    @Test
    public void test4() {
        NVSDKClient client = new NVSDKClient();
        client.ClientStartup(90000);
        client.ClientSetComRecvNotify(new IDecComRecvNotify() {
            @Override
            public void OnDecComRecvNotify(long uId, byte[] pBuf) {
                System.out.println("OnDecComRecvNotify");
            }
        });
        client.ClientSetMsgCallback(new ITDPostMessageNotify() {
            @Override
            public int OnTDPostMessageNotify(long hwndContext, int uiMsg, int iWparamHi, int iWparamLo, int iLParam) {
                int wParHi = iWparamHi;
                int wParLo = iWparamLo;
                int iMsg = wParLo;
                int iId = iLParam;
                System.out.println("OnTDPostMessageNotify hwndContext:" + hwndContext + ", uiMsg:" + uiMsg
                        + ", iWparamLo:" + iWparamLo + ", iWparamHi:" + iWparamHi + ", iLParam:" + iLParam + ", iMsg:"
                        + iMsg + ", iId:" + iId);
                if (iMsg == NVSDKClient.MsgType.DEC_WCM_DEC_LOGON.getValue()) {
                    int iLogonState = wParHi;
                    if (iLogonState == NVSDKClient.LoginState.DEC_LOGON_SUCCESS.getValue()) {
                        System.out.println("DEC_LOGON_SUCCESS");
                    } else if (iLogonState == NVSDKClient.LoginState.DEC_LOGON_FAILED.getValue()) {
                        System.out.println("DEC_LOGON_FAILED");
                    } else if (iLogonState == NVSDKClient.LoginState.DEC_LOGON_TIMEOUT.getValue()) {
                        System.out.println("DEC_LOGON_TIMEOUT");
                    }
                    System.out.println("DEC_WCM_DEC_LOGON:" + iLogonState + ", iId:" + iId);
                } else if (iMsg == NVSDKClient.MsgType.DEC_WCM_NVS_STARTVIEW.getValue()) {
                    System.out.println("DEC_WCM_DEC_START_VIEW:" + ", iId:" + iId);
                } else if (iMsg == NVSDKClient.MsgType.DEC_WCM_NVS_STOPVIEW.getValue()) {
                    System.out.println("DEC_WCM_DEC_STOP_VIEW:" + ", iId:" + iId);
                } else {
                    System.out.println("OnTDPostMessageNotify hwndContext:" + hwndContext + ", uiMsg:" + uiMsg
                            + ", iWparamLo:" + iWparamLo + ", iWparamHi:" + iWparamHi + ", iLParam:" + iLParam
                            + ", iMsg:"
                            + iMsg + ", iId:" + iId);
                }
                return 0;
            }
        });
        client.ClientCleanup();
        client.Dispose();
        client = null;
    }

    @Test
    public void test5() {
        NVSDKClient client = new NVSDKClient();
        client.ClientStartup(90000);
        client.ClientSetComRecvNotify(new IDecComRecvNotify() {
            @Override
            public void OnDecComRecvNotify(long uId, byte[] pBuf) {
                System.out.println("OnDecComRecvNotify");
            }
        });
        client.ClientSetMsgCallback(new ITDPostMessageNotify() {
            @Override
            public int OnTDPostMessageNotify(long hwndContext, int uiMsg, int iWparamHi, int iWparamLo, int iLParam) {
                int wParHi = iWparamHi;
                int wParLo = iWparamLo;
                int iMsg = wParLo;
                int iId = iLParam;
                System.out.println("OnTDPostMessageNotify hwndContext:" + hwndContext + ", uiMsg:" + uiMsg
                        + ", iWparamLo:" + iWparamLo + ", iWparamHi:" + iWparamHi + ", iLParam:" + iLParam + ", iMsg:"
                        + iMsg + ", iId:" + iId);
                if (iMsg == NVSDKClient.MsgType.DEC_WCM_DEC_LOGON.getValue()) {
                    int iLogonState = wParHi;
                    if (iLogonState == NVSDKClient.LoginState.DEC_LOGON_SUCCESS.getValue()) {
                        System.out.println("DEC_LOGON_SUCCESS");
                    } else if (iLogonState == NVSDKClient.LoginState.DEC_LOGON_FAILED.getValue()) {
                        System.out.println("DEC_LOGON_FAILED");
                    } else if (iLogonState == NVSDKClient.LoginState.DEC_LOGON_TIMEOUT.getValue()) {
                        System.out.println("DEC_LOGON_TIMEOUT");
                    }
                    System.out.println("DEC_WCM_DEC_LOGON:" + iLogonState + ", iId:" + iId);
                } else if (iMsg == NVSDKClient.MsgType.DEC_WCM_NVS_STARTVIEW.getValue()) {
                    System.out.println("DEC_WCM_DEC_START_VIEW:" + ", iId:" + iId);
                } else if (iMsg == NVSDKClient.MsgType.DEC_WCM_NVS_STOPVIEW.getValue()) {
                    System.out.println("DEC_WCM_DEC_STOP_VIEW:" + ", iId:" + iId);
                } else {
                    System.out.println("OnTDPostMessageNotify hwndContext:" + hwndContext + ", uiMsg:" + uiMsg
                            + ", iWparamLo:" + iWparamLo + ", iWparamHi:" + iWparamHi + ", iLParam:" + iLParam
                            + ", iMsg:"
                            + iMsg + ", iId:" + iId);
                }
                return 0;
            }
        });
        client.ClientLogin("172.27.100.145", 3000, "Admin", "1111");
        // sleep 6 seconds
        try {
            Thread.sleep(6000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        client.ClientCleanup();
        client.Dispose();
        client = null;
    }

    public class DecComRecvNotify implements IDecComRecvNotify {

        @Override
        public void OnDecComRecvNotify(long uId, byte[] pBuf) {
            System.out.println("OnDecComRecvNotify");
        }
    }

    public class PostMessageNotify implements ITDPostMessageNotify {

        private Object lock;
        private NVSDKClient client;
        private int iLoginID = -1;
        private int Result = -1;

        public PostMessageNotify(NVSDKClient client, Object lock) {
            this.client = client;
            this.lock = lock;
        }

        @Override
        public int OnTDPostMessageNotify(long hwndContext, int iMsg, int iWparamHi, int iWparamLo, int iLParam) {
            int wParHi = iWparamHi;
            int wParLo = iWparamLo;
            int iMsgType = wParLo;
            int iId = iLParam;
            // system output with current time for debugging
            SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd 'at' HH:mm:ss z");
            Date date = new Date(System.currentTimeMillis());
            System.out.println(formatter.format(date));
            if (iMsgType == NVSDKClient.MsgType.DEC_WCM_DEC_LOGON.getValue()) {
                int iLogonState = wParHi;
                if (iLogonState == NVSDKClient.LoginState.DEC_LOGON_SUCCESS.getValue()) {
                    System.out.println("DEC_LOGON_SUCCESS");
                } else if (iLogonState == NVSDKClient.LoginState.DEC_LOGON_FAILED.getValue()) {
                    System.out.println("DEC_LOGON_FAILED");
                } else if (iLogonState == NVSDKClient.LoginState.DEC_LOGON_TIMEOUT.getValue()) {
                    System.out.println("DEC_LOGON_TIMEOUT");
                }
                System.out.println("DEC_WCM_DEC_LOGON:" + iLogonState + ", iId:" + iId);
            } else if (iMsgType == NVSDKClient.MsgType.DEC_WCM_NVS_STARTVIEW.getValue()) {
                int iChannel = (wParHi & 0xF0) >> 4;
                int iPos = (wParHi & 0x0F);
                System.out.println("DEC_WCM_NVS_STARTVIEW:" + ", iId:" + iId + ", iChannel:" + iChannel + ", iPos:"
                        + iPos);
            } else if (iMsgType == NVSDKClient.MsgType.DEC_WCM_NVS_STOPVIEW.getValue()) {
                int iChannel = (wParHi & 0xF0) >> 4;
                int iPos = (wParHi & 0x0F);
                System.out.println("DEC_WCM_DEC_STOP_VIEW:" + ", iId:" + iId + ", iChannel:" + iChannel + ", iPos:"
                        + iPos);
            } else if (iMsgType == NVSDKClient.MsgType.DEC_WCM_DEC_PARASET.getValue()) {
                System.out.println("DEC_WCM_DEC_PARASET:" + ", iId:" + iId);
            } else if (iMsgType == NVSDKClient.MsgType.DEC_WCM_ERR_ORDER.getValue()) {
                System.out.println("DEC_WCM_ERR_ORDER:" + ", iId:" + iId);
            } else if (iMsgType == NVSDKClient.MsgType.DEC_WCM_ALARM_NOTIFY.getValue()) {
                System.out.println("DEC_WCM_ALARM_NOTIFY:" + ", iId:" + iId);
            } else if (iMsgType == NVSDKClient.MsgType.DEC_WCM_DETECT_CHANN_STATE.getValue()) {
                System.out.println("DEC_WCM_DETECT_CHANN_STATE:" + ", iId:" + iId);
            } else {
                System.out.println("OnTDPostMessageNotify hwndContext:" + hwndContext + ", uiMsg:" + iMsgType
                        + ", iWparamLo:" + iWparamLo + ", iWparamHi:" + iWparamHi + ", iLParam:" + iLParam
                        + ", iMsg:"
                        + iMsg + ", iId:" + iId);
            }
            return 0;
        }
    }
    public static String nvItem2String(TNVSItemEx item) {
        return "\n cEncyptPWD:" + item.cEncyptPWD + "\n iDevPlatType:" + item.iDevPlatType + "\n cMultIP:"
                + item.cMultIP
                + "\n iMultPort:" + item.iMultPort + "\n isavecfg:" + item.isavecfg
                + "\n TNVSItem.rtspUrl:" + item.stOldItem.rtspUrl + "\n TNVSItem.serverName:"
                + item.stOldItem.serverName
                + "\n TNVSItem.serverIP:" + item.stOldItem.serverIP + "\n TNVSItem.serverProxy:"
                + item.stOldItem.serverProxy
                + "\n TNVSItem.serverChan:" + item.stOldItem.serverChan + "\n TNVSItem.serverStream:"
                + item.stOldItem.serverStream
                + "\n TNVSItem.serverNetmode:" + item.stOldItem.serverNetmode + "\n TNVSItem.useddns:"
                + item.stOldItem.useddns
                + "\n TNVSItem.serverPort:" + item.stOldItem.serverPort + "\n TNVSItem.isView:" + item.stOldItem.isView
                + "\n TNVSItem.username:" + item.stOldItem.username + "\n TNVSItem.password:" + item.stOldItem.password
                + "\n TNVSItem.holdtime:" + item.stOldItem.holdtime + "\n TNVSItem.deviceType:"
                + item.stOldItem.deviceType
                + "\n TNVSItem.iAddress:" + item.stOldItem.iAddress;
    }
    @SuppressWarnings("static-access")
    @Test
    public void test6() {
        Object lock = new Object();
        NVSDKClient client = new NVSDKClient();
        PostMessageNotify postMessageNotify = new PostMessageNotify(client, lock);
        DecComRecvNotify decComRecvNotify = new DecComRecvNotify();
        client.ClientStartup(90000);
        client.ClientSetComRecvNotify(decComRecvNotify);
        client.ClientSetMsgCallback(postMessageNotify);

        int iLoginID = client.ClientLogin("172.27.100.145", 3000, "Admin", "1111");

        // wait for 1 second and loop 6 times
        int n = 0;
        while (n < 6) {
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            n++;
        }
        // get nvs list
        int iId = 0;
        int iChannel = 0;
        int iPos = 0;
        int iStaus = client.ClientGetLoopStatus(iId, iChannel, iPos);
        if (iStaus != 0) {
            System.out.println("ClientGetLoopStatus failed");
            return;
        }
        int iCount = client.ClientGetLoopItemCount(iId, iChannel, iPos);
        List<TNVSItemEx> list = new java.util.ArrayList<TNVSItemEx>();
        if (iCount > 0) {
            for (int i = 0; i < iCount; i++) {
                TNVSItemEx item = client.ClientGetLoopItemEx(iId, i, iChannel, iPos);
                item.stOldItem.serverName = item.stOldItem.rtspUrl;
                item.stOldItem.serverIP = item.stOldItem.rtspUrl;
                System.out.println("itemEx:" + nvItem2String(item));
                list.add(item);
            }
        }
        /// start view
        if (list.size() > 0) {
            TNVSItemEx item = list.get(0);
            client.ClientStartViewEx(iId, iChannel, iPos, item);
            System.out.println("item:" + nvItem2String(item));
            // sleep 16 seconds
            try {
                Thread.sleep(16000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        client.ClientSetComRecvNotify(null);
        client.ClientSetMsgCallback(null);
        client.ClientCleanup();
        client.Dispose();
        client = null;
    }
}
