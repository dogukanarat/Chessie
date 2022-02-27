add_subdirectory(ChessieSyntaxObject)
add_subdirectory(ChessiePendulum)

install(
    EXPORT ChessieObjects-config
    NAMESPACE ChessieObjects::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
