/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2018, The LineageOS Project. All rights reserved.

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
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "property_service.h"
#include "vendor_init.h"

#include "init_apq8084.h"

using android::base::GetProperty;
using android::init::property_set;

void gsm_properties()
{
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.telephony.default_network", "9");
}

void cdma_properties(char const *operator_alpha,
                     char const *operator_numeric,
                     char const *cdma_sub)
{
    /* Dynamic CDMA Properties */
    property_set("ro.cdma.home.operator.alpha", operator_alpha);
    property_set("ro.cdma.home.operator.numeric", operator_numeric);
    property_set("ro.telephony.default_cdma_sub", cdma_sub);

    /* Static CDMA Properties */
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("ro.telephony.default_network", "10");
    property_set("telephony.lteOnCdmaDevice", "1");
}

void init_target_properties()
{
    std::string platform = GetProperty("ro.board.platform", "");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("N910F") == 0) {
        /* trltexx */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/trltexx/trlte:6.0.1/MMB29M/N910FXXU1DRD1:user/release-keys");
        property_override("ro.build.description", "trltexx-user 6.0.1 MMB29M N910FXXU1DRD1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-N910F");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "trlte");
        property_override_dual("ro.product.name", "ro.vendor.product.name", "trltexx");
        gsm_properties();
    } else if (bootloader.find("N910G") == 0) {
        /* trltedt */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/trltedt/trlte:6.0.1/MMB29M/N910GDTU1DRD1:user/release-keys");
        property_override("ro.build.description", "trltedt-user 6.0.1 MMB29M N910GDTU1DRD1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-N910G");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "trlte");
        property_override_dual("ro.product.name", "ro.vendor.product.name", "trltedt");
        gsm_properties();
    } else if (bootloader.find("N910P") == 0) {
        /* trltespr */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/trltespr/trltespr:6.0.1/MMB29M/N910PVPU5DQI5:user/release-keys");
        property_override("ro.build.description", "trltespr-user 6.0.1 MMB29M N910PVPU5DQI5 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-N910P");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "trltespr");
        property_override_dual("ro.product.name", "ro.vendor.product.name", "trltespr");
        cdma_properties("Sprint", "310120", "1");
    } else if (bootloader.find("N910R4") == 0) {
        /* trlteusc */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/trlteusc/trlteusc:6.0.1/MMB29M/N910R4TYS1CQC1:user/release-keys");
        property_override("ro.build.description", "trlteusc-user 6.0.1 MMB29M N910R4TYS1CQC1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-N910R4");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "trlteusc");
        property_override_dual("ro.product.name", "ro.vendor.product.name", "trlteusc");
        cdma_properties("U.S. Cellular", "311580", "0");
    } else if (bootloader.find("N910T") == 0) {
        /* trltetmo */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/trltetmo/trltetmo:6.0.1/MMB29M/N910TUVU2EQI2:user/release-keys");
        property_override("ro.build.description", "trltetmo-user 6.0.1 MMB29M N910TUVU2EQI2 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-N910T");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "trltetmo");
        property_override_dual("ro.product.name", "ro.vendor.product.name", "trltetmo");
        gsm_properties();
    } else if (bootloader.find("N910V") == 0) {
        /* trltevzw */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "Verizon/trltevzw/trltevzw:6.0.1/MMB29M/N910VVRU2CQL1:user/release-keys");
        property_override("ro.build.description", "trltevzw-user 6.0.1 MMB29M N910VVRU2CQL1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-N910V");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "trltevzw");
        property_override_dual("ro.product.name", "ro.vendor.product.name", "trltevzw");
        cdma_properties("Verizon", "311480", "0");
    } else if (bootloader.find("N910W8") == 0) {
        /* trltecan */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/trltecan/trltecan:6.0.1/MMB29M/N910W8VLS1DQH2:user/release-keys");
        property_override("ro.build.description", "trltecan-user 6.0.1 MMB29M N910W8VLS1DQH2 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-N910W8");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "trltecan");
        property_override_dual("ro.product.name", "ro.vendor.product.name", "trltecan");
        gsm_properties();
    } else {
        gsm_properties();
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader << " setting build properties for " << device << " device" << std::endl;
}
