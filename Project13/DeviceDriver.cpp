#include "DeviceDriver.h"

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware) {
}

int DeviceDriver::read(long address) {
    int tmp;

    for (int i = 0; i < 5; i++)
        tmp = (int)(m_hardware->read(address));

    return tmp;
}

void DeviceDriver::write(long address, int data) {
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}