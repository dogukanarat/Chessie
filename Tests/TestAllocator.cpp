#include "TestAllocator.h"

using namespace UnitTest;

TEST_F(TestAllocator, getBlockStatus)
{
    UInt32 testRegisterUnavailable = 0x1;
    UInt32 testRegisterAvailable = 0x0;

    EXPECT_EQ(1, getBlockStatus(&testRegisterUnavailable));
    EXPECT_EQ(0, getBlockStatus(&testRegisterAvailable));

    UInt32 testMaskRegisterSet = 0xFFFFFFFF; // lsb is set
    UInt32 testMaskRegisterClear = 0xFFFFFFFE; // lsb is clear

    EXPECT_EQ(1, getBlockStatus(&testMaskRegisterSet));
    EXPECT_EQ(0, getBlockStatus(&testMaskRegisterClear));
    
}

TEST_F(TestAllocator, getBlockSize)
{
    UInt32 blockSize = 123;
    UInt32 testRegister = blockSize << 1;

    EXPECT_EQ(blockSize, getBlockSize(&testRegister));
}

TEST_F(TestAllocator, setBlockStatus)
{
    UInt32 testRegister = 0;
    UInt32 blockStatus = Available;

    UInt32 actualHeader = 0;
    UInt32 resultHeader = 0;

    actualHeader = setBlockStatus(&testRegister, blockStatus);
    resultHeader = getBlockStatus(&testRegister) << 0;
    
    EXPECT_EQ(actualHeader, resultHeader);

    blockStatus = Unavailable;

    actualHeader = setBlockStatus(&testRegister, blockStatus);
    resultHeader = getBlockStatus(&testRegister) << 0;
    
    EXPECT_EQ(actualHeader, resultHeader);
}

TEST_F(TestAllocator, setBlockSize)
{
    UInt32 testRegister = 0;
    UInt32 blockSize = 123;

    UInt32 actualHeader = 0;
    UInt32 resultHeader = 0;

    actualHeader = setBlockSize(&testRegister, blockSize);
    resultHeader = getBlockSize(&testRegister) << 1;

    EXPECT_EQ(actualHeader, resultHeader);
}