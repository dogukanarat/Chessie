add_subdirectory(Source)

add_executable(
    Chessie
)

target_sources(
    Chessie 
    PRIVATE
        Source/MainWindow.cpp
        Source/Main.cpp
        Source/MainWindow.ui
)

target_link_libraries(
    Chessie
    PRIVATE
        ChessieCore
        ChessieSyntaxObject
        Qt5::Widgets
)
    