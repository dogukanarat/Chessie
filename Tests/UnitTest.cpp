#include "UnitTest.h"
#include <iostream>

using namespace Test;

// Tests that the Foo::Bar() method does Abc.
TEST_F(FooTest, MethodBarDoesAbc)
{
    EXPECT_EQ(0, 0);
}

// Tests that Foo does Xyz.
TEST_F(FooTest, DoesXyz)
{
   // Exercises the Xyz feature of Foo.
}

TEST_F(FooTest, InterfaceTest)
{
   Chessie::IAllocator* allocator = new Chessie::DefaultAllocator();
   delete allocator;
}

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
