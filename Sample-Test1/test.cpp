#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Project13/DeviceDriver.cpp"

using namespace testing;
using namespace std;
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

TEST(TestCaseName, exception) {
	DevMock dev_mock;

	EXPECT_CALL(dev_mock, read(0xaaa))
		.WillOnce(Return(0xa))
		.WillOnce(Return(0xa))
		.WillOnce(Return(0xa))
		.WillOnce(Return(0xa))
		.WillOnce(Return(0x1));

	DeviceDriver dd(&dev_mock);
	EXPECT_THROW(dd.read(0xaaa), exception);
}

TEST(TestCaseName, memCheckForWrite1) {
	DevMock dev_mock;

	EXPECT_CALL(dev_mock, read(_))
		.Times(1)
		.WillOnce(Return(0xFF));

	DeviceDriver dd(&dev_mock);
	dd.write(0xaa, 0xa);
}

TEST(TestCaseName, memCheckForWrite2) {
	DevMock dev_mock;

	EXPECT_CALL(dev_mock, read(_))
		.Times(1)
		.WillOnce(Return(0x2));

	DeviceDriver dd(&dev_mock);

	EXPECT_THROW(dd.write(0xaa, 0xa), exception);
}