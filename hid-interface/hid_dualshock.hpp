#include "hid_interface.hpp"
#include <hidapi/hidapi.h>
#include <stdio.h>
/*
#include <gflags/gflags.h>
#include <glog/logging.h>
*/


class hid_dualshock : public hid_interface {
private:
const uint16_t vid = 0x054c;
const uint16_t  pid = 0x09cc;

public:
    void print_name(){
        printf("0x%4x : 0x%4x\r\n",vid,pid);
    };
    HIDError setup_device() override;
    HIDError read_input_report() override;
    HIDError cleanup_device() override;
    Data get_pad_data() override;
};