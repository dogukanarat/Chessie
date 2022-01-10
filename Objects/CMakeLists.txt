add_subdirectory(ChessieSyntaxObject)

install(
    EXPORT ChessieObjects-config
    NAMESPACE chessieobjects::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)