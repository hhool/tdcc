package com.gshx.camera;

import java.sql.Date;
import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Scanner;

import com.gshx.camera.tiandi.IDecComRecvNotify;
import com.gshx.camera.tiandi.ITDPostMessageNotify;
import com.gshx.camera.tiandi.NVSDKClient;
import com.gshx.camera.tiandi.TNVSItemEx;

public class Main {
    public class PostMessageNotify implements ITDPostMessageNotify {
        private Object lock;
        private NVSDKClient client;
        private int iLoginID = -1;
        private int Result = -1;

        public PostMessageNotify(NVSDKClient client, Object lock) {
            this.lock = lock;
        }

        public int getResult() {
            return Result;
        }

        @Override
        public int OnTDPostMessageNotify(long hwndContext, int iMsg, int iWparamHi, int iWparamLo, int iLParam) {
            System.out.println("callback thread id:" + Thread.currentThread().getId());
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
    };

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

    public static void main(String[] args) {
        System.out.println("main thread id:" + Thread.currentThread().getId());
        Object lock = new Object();
        NVSDKClient client = new NVSDKClient();
        Main mainInstance = new Main();
        PostMessageNotify mPostMessageNotify = mainInstance.new PostMessageNotify(client, lock);
        client.ClientSetMsgCallback(mPostMessageNotify);
        client.ClientStartup(90000);
        client.ClientSetComRecvNotify(new IDecComRecvNotify() {
            @Override
            public void OnDecComRecvNotify(long uId, byte[] pBuf) {
                System.out.println("OnDecComRecvNotify");
            }
        });

        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入解码器IP:");
        String decoderIP = scanner.nextLine();

        System.out.println("请输入解码器端口号:");
        String decoderPort = scanner.nextLine();

        System.out.println("请输入解码器用户名:");
        String decoderUser = scanner.nextLine();
        System.out.println("请输入解码器密码:");
        String decoderPassword = scanner.nextLine();

        System.out.println("IP:" + decoderIP + "  port:" + decoderPort + "  user:" + decoderUser + "  " + "  password:"
                + decoderPassword);

        int iLoginID = client.ClientLogin(decoderIP, Integer.parseInt(decoderPort), decoderUser, decoderPassword);
        System.out.println("登录成功id:" + iLoginID);

        System.out.println("请输入解码器ID:");
        int iId = scanner.nextInt();

        System.out.println("请输入通道号:");
        int iChannel = scanner.nextInt();

        System.out.println("请输入iPos:");
        int iPos = scanner.nextInt();

        int iStaus = client.ClientGetLoopStatus(iId, iChannel, iPos);
        System.out.println("iStaus结果:" + iStaus);

        int iCount = client.ClientGetLoopItemCount(iId, iChannel, iPos);
        System.out.println("iCount结果:" + iCount);

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
        System.out.println("输入list size:" + list.size());
        int iIndex = scanner.nextInt();
        TNVSItemEx item_ex = list.get(iIndex);
        System.out.println("itemEx:" + nvItem2String(item_ex));
        int ret = client.ClientStartViewEx(iId, iChannel, iPos, item_ex);
        System.out.println("上墙结果:" + ret);

        System.out.println("输入任意数字停止上墙:");
        scanner.nextInt();

        client.ClientStopView(iId, iChannel, iPos, false);
        System.out.println("输入任意数字退出:");
        scanner.nextInt();

        client.ClientSetComRecvNotify(null);
        client.ClientSetMsgCallback(null);
        client.ClientCleanup();
        client.Dispose();
        client = null;

    }

    public static void test() {
        System.out.println("Test");
    }
}