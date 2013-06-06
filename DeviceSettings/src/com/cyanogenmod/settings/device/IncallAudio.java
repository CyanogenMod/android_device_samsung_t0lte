/*
 * Copyright (C) 2012 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.cyanogenmod.settings.device;

import java.io.IOException;
import android.content.Context;
import android.util.AttributeSet;
import android.content.SharedPreferences;
import android.preference.Preference;
import android.preference.ListPreference;
import android.preference.Preference.OnPreferenceChangeListener;
import android.preference.PreferenceManager;

public class IncallAudio extends ListPreference implements OnPreferenceChangeListener {

    public IncallAudio(Context context, AttributeSet attrs) {
        super(context, attrs);
        this.setOnPreferenceChangeListener(this);
    }

    private static String INCALL_HEADSET_FILE = "/data/t0lte_audio/incall_headset";
    private static String INCALL_HEADPHONE_FILE = "/data/t0lte_audio/incall_headphone";
    private static String INCALL_SPEAKER_FILE = "/data/t0lte_audio/incall_speaker";
    private static String INCALL_BT_FILE = "/data/t0lte_audio/incall_bt";

    private enum Device {
        headset,
        headphone,
        speaker,
        bt
    }

    public static boolean isSupported(String output) {
        String FILE = null;
        Device outputDevice = Device.valueOf(output);

        switch(outputDevice) {
            case headset:
                FILE = INCALL_HEADSET_FILE;
            case headphone:
                FILE = INCALL_HEADPHONE_FILE;
            case speaker:
                FILE = INCALL_SPEAKER_FILE;
            case bt:
                FILE = INCALL_BT_FILE;
        }
        return Utils.fileExists(FILE);
    }

    /**
     * Restore Incall Audio settings from SharedPreferences.
     * @param context       The context to read the SharedPreferences from
     */
    public static void restore(Context context) {
        SharedPreferences sharedPrefs = PreferenceManager.getDefaultSharedPreferences(context);

        if (isSupported("headset"))
            Utils.writeValue(INCALL_HEADSET_FILE, sharedPrefs.getString(DeviceSettings.KEY_INCALL_HEADSET, "5"));
        if (isSupported("headphone"))
            Utils.writeValue(INCALL_HEADPHONE_FILE, sharedPrefs.getString(DeviceSettings.KEY_INCALL_HEADPHONE, "5"));
        if (isSupported("speaker"))
            Utils.writeValue(INCALL_SPEAKER_FILE, sharedPrefs.getString(DeviceSettings.KEY_INCALL_SPEAKER, "5"));
        if (isSupported("bt"))
            Utils.writeValue(INCALL_BT_FILE, sharedPrefs.getString(DeviceSettings.KEY_INCALL_BT, "5"));     
    }

    public boolean onPreferenceChange(Preference preference, Object newValue) {
        String key = preference.getKey();

        if(key.equals(DeviceSettings.KEY_INCALL_HEADSET))
             Utils.writeValue(INCALL_HEADSET_FILE, (String) newValue);
        else if(key.equals(DeviceSettings.KEY_INCALL_HEADPHONE))
             Utils.writeValue(INCALL_HEADPHONE_FILE, (String) newValue);
        else if(key.equals(DeviceSettings.KEY_INCALL_SPEAKER))
             Utils.writeValue(INCALL_SPEAKER_FILE, (String) newValue);
        else if(key.equals(DeviceSettings.KEY_INCALL_BT))
             Utils.writeValue(INCALL_BT_FILE, (String) newValue);

        return true;
    }

}
