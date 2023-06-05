#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Project13/DeviceDriver.cpp"

using namespace testing;
class DevMock : public FlashMemoryDevice
{
public:
	MOCK_METHOD(unsigned char, read, (long address), (override));
	MOCK_METHOD(void, write, (long address, unsigned char data), (override));
};

TEST(TestCaseName, TestName) {
	DevMock dev_mock;

	DeviceDriver dd(&dev_mock);
	
}