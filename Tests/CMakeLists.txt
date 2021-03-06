include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

option(INSTALL_GTEST "Enable installation of googletest." OFF)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(
    ChessieUnitTest
    Main.cpp
    TestAllocator.cpp
)

target_compile_definitions(ChessieUnitTest PUBLIC CTEST)

target_link_libraries(
  ChessieUnitTest
    gtest_main
    ChessieCore
)

gtest_discover_tests(ChessieUnitTest
    PROPERTIES
      LABELS "unit"
    DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
      240
    )
