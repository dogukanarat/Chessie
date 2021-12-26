add_executable(
    chessie
)

target_sources(
    chessie 
        PRIVATE
            Source/App.cpp
            Source/Main.cpp
)

target_link_libraries(
    chessie
        PRIVATE
            chessiecommon
    )
    