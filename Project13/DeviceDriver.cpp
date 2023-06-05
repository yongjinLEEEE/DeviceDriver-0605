#include "DeviceDriver.h"
#include <exception>

using namespace std;

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware) {
}

int DeviceDriver::read(long address) {
    int result = (int)(m_hardware->read(address));    

    for (int i = 1; i < 5; i++) {
        int tmp = (int)(m_hardware->read(address));
            if (result != tmp)
                throw exception("Exception!!!!");        
    }

    return result;
}

void DeviceDriver::write(long address, int data) {
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}