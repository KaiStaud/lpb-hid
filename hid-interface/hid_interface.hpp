/*
Abstract away gamepad type.
*/

#include <stdint.h>
#include <tuple>
#include <hidapi/hidapi.h>

enum Direction : uint8_t {
    North = 0,
    NorthEast,
    East,
    SouthEast,
    South,
    SouthWest,
    West,
    NorthWest,
    None = 8
};

enum class HIDError{
    ENoError,
    EInit,
    EOpen,
    EExit,
    EMode,
    ERead

};

enum class HIDUpdate{
    IUpdated,
    INoUpdate,
    EUpdate    
};

struct Data{
    int x1,y1;
    int x2,y2;
    bool a,r,d,b;
    Direction direction; 
};

class hid_interface{

    public:
    virtual HIDError setup_device() = 0;
    virtual HIDError read_input_report() = 0;
    virtual HIDError cleanup_device() = 0;
    virtual Data get_pad_data() = 0; 
    virtual ~hid_interface(){};
    
    protected:
    unsigned char buffer[64];
    hid_device* device;
    Data data;
};