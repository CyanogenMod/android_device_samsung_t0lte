/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void gsm_properties(char lteongsm[], char default_network[]);

void cdma_properties(char cdma_subscription[],
                     char default_network[],
                     char operator_numeric[],
                     char operator_alpha[],
                     char sms_pseudo_multipart[]);

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "I317M")) {
        /* t0ltecan */
        gsm_properties("1", "9");
        property_set("ro.build.fingerprint", "samsung/t0ltevl/t0ltecan:4.1.1/JRO03C/I317MVLALJ2:user/release-keys");
        property_set("ro.build.description", "t0ltevl-user 4.1.1 JRO03C I317MVLALJ2 release-keys");
        property_set("ro.product.model", "SGH-I317M");
        property_set("ro.product.device", "t0ltecan");
        property_set("ro.telephony.ril_class", "SamsungQualcommRIL");
    } else if (strstr(bootloader, "I317")) {
        /* t0lteatt */
        gsm_properties("1", "9");
        property_set("ro.build.fingerprint", "samsung/t0lteatt/t0lteatt:4.1.2/JZO54K/I317UCAMA4:user/release-keys");
        property_set("ro.build.description", "t0lteatt-user 4.1.2 JZO54K I317UCAMA4 release-keys");
        property_set("ro.product.model", "SGH-I317");
        property_set("ro.product.device", "t0lteatt");
        property_set("ro.telephony.ril_class", "SamsungQualcommRIL");
    } else if (strstr(bootloader, "L900")) {
        /* t0ltespr */
        cdma_properties("1", "8", "310120", "Sprint", "1");
        property_set("ro.build.fingerprint", "samsung/t0ltespr/t0ltespr:4.3/JSS15J/L900VPUBMK4:user/release-keys");
        property_set("ro.build.description", "t0ltespr-user 4.3 JSS15J L900VPUBMK4 release-keys");
        property_set("ro.product.model", "SPH-L900");
        property_set("ro.product.device", "t0ltespr");
        property_set("ro.telephony.ril_class", "SamsungQualcommRIL");
    } else if (strstr(bootloader, "T889")) {
        /* t0ltetmo */
        gsm_properties("1", "9");
        property_set("ro.build.fingerprint", "samsung/t0ltetmo/t0ltetmo:4.1.2/JZO54K/T889UVBMB4:user/release-keys");
        property_set("ro.build.description", "t0ltetmo-user 4.1.2 JZO54K T889UVBMB4 release-keys");
        property_set("ro.product.model", "SGH-T889");
        property_set("ro.product.device", "t0ltetmo");
        property_set("ro.telephony.ril_class", "SamsungQualcommRIL");
    } else if (strstr(bootloader, "R950")) {
        /* t0lteusc */
        cdma_properties("0", "8", "311220", "U.S. Cellular", "1");
        property_set("ro.build.fingerprint", "samsung/t0lteusc/t0lteusc:4.3/JSS15J/R950VXUBMK3:user/release-keys");
        property_set("ro.build.description", "t0lteusc-user 4.3 JSS15J R950VXUBMK3 release-keys");
        property_set("ro.product.model", "SCH-R950");
        property_set("ro.product.device", "t0lteusc");
        property_set("ro.telephony.ril_class", "SamsungQualcommRIL");
    } else if (strstr(bootloader, "I605")) {
        /* t0ltevzw */
        cdma_properties("0", "10", "310004", "Verizon", "0");
        property_set("ro.build.fingerprint", "Verizon/t0ltevzw/t0ltevzw:4.1.2/JZO54K/I605VRAMC3:user/release-keys");
        property_set("ro.build.description", "t0ltevzw-user 4.1.2 JZO54K I605VRAMC3 release-keys");
        property_set("ro.product.model", "SCH-I605");
        property_set("ro.product.device", "t0ltevzw");
        property_set("ro.telephony.call_ring.multiple", "0");
        property_set("persist.radio.no_wait_for_card", "1");
        property_set("ro.telephony.ril_class", "SamsungQualcommRIL");
    } else if (strstr(bootloader, "N7100")) {
        /* t03gxx */
        gsm_properties("0", "3");
        property_set("ro.build.fingerprint", "samsung/t03gxx/t03g:4.1.1/JRO03C/N7100XXALJ3:user/release-keys");
        property_set("ro.build.description", "t03gxx-user 4.1.1 JRO03C N7100XXALJ3 release-keys");
        property_set("ro.product.model", "GT-N7100");
        property_set("ro.product.device", "t03gxx");
        property_set("ro.telephony.default_network", "9");
        property_set("ro.telephony.ril_class", "SamsungExynos4RIL");
    } else if (strstr(bootloader, "N7105")) {
        /* t0ltexx */
        gsm_properties("1", "9");
        property_set("ro.build.fingerprint", "samsung/t0ltexx/t0lte:4.1.2/JZO54K/N7105XXDLL4:user/release-keys");
        property_set("ro.build.description", "t0ltexx-user 4.1.2 JZO54K N7105XXDLL4 release-keys");
        property_set("ro.product.model", "GT-N7105");
        property_set("ro.product.device", "t0ltexx");
        property_set("ro.telephony.ril_class", "SamsungExynos4RIL");
    }

    property_get("ro.product.device", device);
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, device);

}

void gsm_properties(char lteongsm[], char default_network[])
{
    property_set("telephony.lteOnGsmDevice", lteongsm);
    property_set("ro.telephony.default_network", default_network);
}

void cdma_properties(char default_cdma_sub[], char default_network[],
                     char operator_numeric[], char operator_alpha[],
                     char sms_pseudo_multipart[])
{
    property_set("ro.telephony.default_cdma_sub", default_cdma_sub);
    property_set("ro.telephony.default_network", default_network);
    property_set("ro.cdma.home.operator.numeric", operator_numeric);
    property_set("ro.cdma.home.operator.alpha", operator_alpha);
    property_set("telephony.sms.pseudo_multipart", sms_pseudo_multipart);

    property_set("telephony.lteOnCdmaDevice", "1");
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("ro.cdma.subscribe_on_ruim_ready", "true");
    property_set("ro.ril.svdo", "true");
    property_set("ro.config.qc_lte_network_modes", "true");
}
