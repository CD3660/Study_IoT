package com.example.my52_iotesp8266.Common;

import android.content.Context;
import android.net.ConnectivityManager;

public class CommonMethod {

    /*public static String  ipConfig = "http://192.168.200.151:8989";*/
    public static String  ipConfig = "http://192.168.0.200:8989";
    //public static String  ipConfig = "http://121.148.239.200:80";

    // 네트워크에 연결되어 있는가
    public static boolean isNetworkConnected(Context context) {
        ConnectivityManager cm = (ConnectivityManager)
                context.getSystemService( Context.CONNECTIVITY_SERVICE );

        return cm.getActiveNetworkInfo() != null;
    }



}
