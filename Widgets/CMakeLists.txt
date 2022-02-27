add_subdirectory(ChessieBaseWidget)
add_subdirectory(ChessieGraphicWidget)

install(
    EXPORT ChessieWidgets-config
    NAMESPACE ChessieWidgets::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
