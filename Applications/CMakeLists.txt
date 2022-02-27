add_subdirectory(Chessie)

install(
    EXPORT Chessie-config
    NAMESPACE Chessie::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)