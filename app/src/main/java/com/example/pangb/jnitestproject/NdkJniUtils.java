package com.example.pangb.jnitestproject;

/**
 * Created by pangb on 2016/3/15.
 */
public class NdkJniUtils {
    public native String generateKey(String name);

    static
    {
        System.loadLibrary("JniDemo");
    }
}
