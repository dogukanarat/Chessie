add_subdirectory(ChessieCore)
add_subdirectory(ChessieEthernet)

install(
    EXPORT ChessieLibrary-config
    NAMESPACE chessielib::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
