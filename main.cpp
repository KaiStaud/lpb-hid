#include <iostream>
#include <chrono>
#include <thread>

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <ecal/ecal.h>
#include <ecal/msg/string/publisher.h>

#include <iostream>
#include <sstream>
#include <string>
#include "hid-interface/hid_dualshock.hpp"
/*
Application to read HID Input device.
A updated input will be sent to listening clients
*/

int main(int argc, char **argv) {

    hid_dualshock bedienpad;
    bedienpad.print_name();
    bedienpad.setup_device();

  eCAL::Initialize(argc, argv, "minimal_snd");
  eCAL::string::CPublisher<std::string> pub("Hello");
 
  bedienpad.read_input_report();
    auto r = bedienpad.get_pad_data();
    int cnt = 0;
    while (true) {
   
        bedienpad.read_input_report();
        r = bedienpad.get_pad_data();
        std::cout << "Left Stick X: " << r.x1 << std::endl;
        std::cout << "Left Stick Y: " << r.y1 << std::endl;
        std::stringstream snd_content;
        snd_content <<  r.x1;
        
	pub.Send(snd_content.str(), cnt++);
        eCAL::Process::SleepMS(10);
        
	std::this_thread::sleep_for(std::chrono::milliseconds(50));

    }
    return 0;
}
