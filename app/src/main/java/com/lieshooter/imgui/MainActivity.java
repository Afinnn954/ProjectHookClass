package com.lieshooter.imgui;
 
import android.app.Activity;
import android.os.Bundle;
import android.content.Context;

public class MainActivity extends Activity { 

    public String GameActivity = "com.dts.freefireth.FFMainActivity";

    public static native void Toast(Context context);

    static {
        System.loadLibrary("FadliMod");
        try {
            System.loadLibrary("libRazor.so");
        } catch (UnsatisfiedLinkError e) {
            UnsatisfiedLinkError unsatisfiedLinkError = e;
        }
    }
     
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
    }
	
} 