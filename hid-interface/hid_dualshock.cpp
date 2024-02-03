#include "hid_dualshock.hpp"
#include <hidapi/hidapi.h>

HIDError hid_dualshock::setup_device(){
        // Initialize the HIDAPI library
    if (hid_init() != 0) {
        return HIDError::EInit;
    }

    // Open the DualShock 4 device (Update VID and PID with the correct values)
    device = hid_open(vid, pid, nullptr);
    if (!device) {

        if(hid_exit() == -1)
        {
            return HIDError::EExit;
        }
        else{
            return HIDError::EOpen;
        }
    }

    // Set blocking mode for reading reports
    if(hid_set_nonblocking(device, 0) == -1){
        return HIDError::EMode;
    }
    return HIDError::ENoError;
}

HIDError hid_dualshock::read_input_report(){
        if (hid_read(device, buffer, sizeof(buffer)) < 0) {
        return HIDError::ERead;
        }

        data.x1 = buffer[1];
        data.y1 = buffer[2];
        data.x2 = buffer[3];
        data.y2 = buffer[4];
return HIDError::ENoError;
}

HIDError hid_dualshock::cleanup_device(){
    hid_close(device);
    if(hid_exit() == -1)
    {
        return HIDError::EExit;
    }
return HIDError::ENoError;
}

Data hid_dualshock::get_pad_data(){

    auto e = read_input_report();
    return data; 
}