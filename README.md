tried making a custom hal in aosp15 :)


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




for the time being it just starts and logs, the impl is not called, so actually functionality is not chechedk, will do that later!!
//how to verify

subin@exlino:~$ adb logcat | grep  -i "dutch"
12-11 13:17:53.303     0     0 I init    : Parsing file /vendor/etc/init/vendor.dutch.heartbeat.rc...
12-11 13:18:39.783     0     0 I init    : starting service 'vendor.dutch.heartbeat'...
12-11 13:18:39.804     0     0 I init    : ... started service 'vendor.dutch.heartbeat' has pid 2666
12-11 13:18:39.804     0     0 I init    : Control message: Processed ctl.start for 'vendor.dutch.heartbeat' from pid: 2664 (start vendor.dutch.heartbeat)
12-11 13:18:39.760  2666  2666 I vendor.dutch.heartbeat: Heartbeat HAL service started: com.dutch.heartbeat.IHeartbeat/default
12-11 13:18:39.815     0     0 I servicemanager: Caller(pid=2666,uid=1000,sid=u:r:vendor_dutch_heartbeat:s0) Found com.dutch.heartbeat.IHeartbeat/default in device VINTF manifest.
12-11 13:29:12.952  2681  2681 W service : Thread Pool max thread count is 0. Cannot cache binder as linkToDeath cannot be implemented. serviceName: com.dutch.heartbeat.IHeartbeat/default

