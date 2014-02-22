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

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "I317M")) {
        /* t0ltecan */
        property_set("ro.build.fingerprint", "samsung/t0ltevl/t0ltecan:4.1.1/JRO03C/I317MVLALJ2:user/release-keys");
        property_set("ro.build.description", "t0ltevl-user 4.1.1 JRO03C I317MVLALJ2 release-keys");
        property_set("ro.product.model", "SGH-I317M");
        property_set("ro.product.device", "t0ltecan");
        property_set("telephony.lteOnGsmDevice", "1");
        property_set("ro.telephony.default_network", "9");
    } else if (strstr(bootloader, "I317")) {
        /* t0lteatt */
        property_set("ro.build.fingerprint", "samsung/t0lteatt/t0lteatt:4.1.2/JZO54K/I317UCAMA4:user/release-keys");
        property_set("ro.build.description", "t0lteatt-user 4.1.2 JZO54K I317UCAMA4 release-keys");
        property_set("ro.product.model", "SGH-I317");
        property_set("ro.product.device", "t0lteatt");
        property_set("telephony.lteOnGsmDevice", "1");
        property_set("ro.telephony.default_network", "9");
    } else if (strstr(bootloader, "L900")) {
        /* t0ltespr */
        property_set("ro.build.fingerprint", "samsung/t0ltespr/t0ltespr:4.3/JSS15J/L900VPUBMK4:user/release-keys");
        property_set("ro.build.description", "t0ltespr-user 4.3 JSS15J L900VPUBMK4 release-keys");
        property_set("ro.product.model", "SPH-L900");
        property_set("ro.product.device", "t0ltespr");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("ro.telephony.default_network", "8");
    } else if (strstr(bootloader, "T889")) {
        /* t0ltetmo */
        property_set("ro.build.fingerprint", "samsung/t0ltetmo/t0ltetmo:4.1.2/JZO54K/T889UVBMB4:user/release-keys");
        property_set("ro.build.description", "t0ltetmo-user 4.1.2 JZO54K T889UVBMB4 release-keys");
        property_set("ro.product.model", "SGH-T889");
        property_set("ro.product.device", "t0ltetmo");
        property_set("telephony.lteOnGsmDevice", "1");
        property_set("ro.telephony.default_network", "9");
    } else if (strstr(bootloader, "R950")) {
        /* t0lteusc */
        property_set("ro.build.fingerprint", "samsung/t0lteusc/t0lteusc:4.3/JSS15J/R950VXUBMK3:user/release-keys");
        property_set("ro.build.description", "t0lteusc-user 4.3 JSS15J R950VXUBMK3 release-keys");
        property_set("ro.product.model", "SCH-R950");
        property_set("ro.product.device", "t0lteusc");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("ro.telephony.default_network", "8");
    } else if (strstr(bootloader, "I605")) {
        /* t0ltevzw */
        property_set("ro.build.fingerprint", "Verizon/t0ltevzw/t0ltevzw:4.1.2/JZO54K/I605VRAMC3:user/release-keys");
        property_set("ro.build.description", "t0ltevzw-user 4.1.2 JZO54K I605VRAMC3 release-keys");
        property_set("ro.product.model", "SCH-I605");
        property_set("ro.product.device", "t0ltevzw");
        property_set("ro.cdma.home.operator.alpha", "Verizon");
        property_set("ro.cdma.home.operator.numeric", "310004");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("ro.telephony.default_network", "10");
    } else if (strstr(bootloader, "I7100")) {
        /* n7100 */
        property_set("ro.build.fingerprint", "samsung/t03gxx/t03g:4.1.1/JRO03C/N7100XXALJ3:user/release-keys");
        property_set("ro.build.description", "t03gxx-user 4.1.1 JRO03C N7100XXALJ3 release-keys");
        property_set("ro.product.model", "GT-N7100");
        property_set("ro.product.device", "n7100");
        property_set("telephony.lteOnGsmDevice", "1");
        property_set("ro.telephony.default_network", "9");
    } else if (strstr(bootloader, "I7105")) {
        /* n7105 */
        property_set("ro.build.fingerprint", "samsung/t03gxx/t03g:4.1.1/JRO03C/N7100XXALJ3:user/release-keys");
        property_set("ro.build.description", "t03gxx-user 4.1.1 JRO03C N7100XXALJ3 release-keys");
        property_set("ro.product.model", "GT-N7105");
        property_set("ro.product.device", "n7100");
        property_set("telephony.lteOnGsmDevice", "1");
        property_set("ro.telephony.default_network", "9");
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}
