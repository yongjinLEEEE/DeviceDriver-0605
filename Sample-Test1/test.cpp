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

TEST(TestCaseName, read5th) {
	DevMock dev_mock;

	EXPECT_CALL(dev_mock, read)
		.Times(5);

	DeviceDriver dd(&dev_mock);
	dd.read(0xaaa);
}