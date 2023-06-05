#include "DeviceDriver.h"
#include <exception>

using namespace std;

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware) {
}

int DeviceDriver::read(long address) {
    int result = (int)(m_hardware->read(address));

    for (int i = 1; i < readTryCnt; i++) {
	    if (result != (int)m_hardware->read(address))
                throw exception("Exception!!!!");        
    }

    return result;
}

void DeviceDriver::write(long address, int data) {
    int tmp = (int)m_hardware->read(address);
    if (tmp != emptyCode)
        throw exception("[Exception] Write failed!!!");

    m_hardware->write(address, (unsigned char)data);
}