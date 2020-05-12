#
# Copyright (C) 2014 The CyanogenMod Project
#           (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# inherit from common trlte
-include device/samsung/trlte-common/BoardConfigCommon.mk

TARGET_OTA_ASSERT_DEVICE := trltexx,trltedt

# Kernel
TARGET_KERNEL_VARIANT_CONFIG := apq8084_sec_trlte_eur_defconfig

# Camera
TARGET_FIXUP_PREVIEW := true

# Init
TARGET_INIT_VENDOR_LIB := libinit_apq8084
TARGET_LIBINIT_APQ8084_DEFINES_FILE := device/samsung/trltexx/init/init_trlte.cpp

# Partitions
BOARD_FLASH_BLOCK_SIZE := 262144
BOARD_BOOTIMAGE_PARTITION_SIZE := 17825792
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 19932160
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 3774873600
BOARD_USERDATAIMAGE_PARTITION_SIZE := 27040657408

# inherit from the proprietary version
-include vendor/samsung/trltexx/BoardConfigVendor.mk
