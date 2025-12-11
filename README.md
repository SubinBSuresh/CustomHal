/vendor/dutch/hardware/interfaces/custom_hal/
dutch - my vendor name

source build/envsetup.sh
lunch sdk_car_x86_64-trunk_staging-userdebug



//clean the intermediates
rm -rf out/soong/.intermediates/vendor/dutch/hardware/interfaces/custom_hal/aidl/com.dutch.heartbeat_interface/

//udpate api
m com.dutch.heartbeat-update-api


//make 
m vendor.dutch.heartbeat 

//check if binary is generate
subin@exlino:~/AOSP15$ ls -l out/target/product/emulator_car64_x86_64/vendor/bin/hw/vendor.dutch.heartbeat



//start hal
adb root
adb shell start vendor.dutch.heartbeat


// to see if hal is up
adb shell service list | grep heartbeat
