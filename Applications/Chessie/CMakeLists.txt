add_executable(
    Chessie
)

target_sources(
    Chessie 
        PRIVATE
            Source/App.cpp
            Source/Main.cpp
)

target_link_libraries(
    Chessie
        PRIVATE
            ChessieCore
)
    