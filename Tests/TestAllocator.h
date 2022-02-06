#include <gtest/gtest.h>
#include "ChessieCore/ChessieCommon.h"
#include "ChessieCore/ChessieAllocator.h"

using namespace Chessie;

namespace UnitTest
{
    class TestAllocator : public ::testing::Test, public Chessie::Allocator
    {
    protected:

        static constexpr Size BufferSize = 512;
        static constexpr Size PaddingSize = 4;

        TestAllocator()
            : Allocator(m_buffer, BufferSize, PaddingSize)
        {
        }

        ~TestAllocator() override
        {
        }

        void SetUp() override
        {
        }

        void TearDown() override
        {
        }

        UInt8 m_buffer[BufferSize];
    };
}
