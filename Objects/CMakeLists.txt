add_subdirectory(ChessieSyntaxObject)
add_subdirectory(ChessieBaseScene)
add_subdirectory(ChessiePendulum)
add_subdirectory(ChessiePathPlanner)

install(
    EXPORT ChessieObjects-config
    NAMESPACE ChessieObjects::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
