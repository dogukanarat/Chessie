add_subdirectory(Source)

add_executable(
    Chessie
)

set(CUSTOM_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/Source/GeneratedHeader.h")

execute_process(
    COMMAND python ${CRESSIE_SCRIPT_DIR}/HelloWorld.py ${CUSTOM_HEADER}
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

target_sources(
    Chessie 
    PRIVATE
        Source/MainWindow.cpp
        Source/Main.cpp
        Source/MainWindow.ui
        ${CUSTOM_HEADER}
)

add_dependencies(Chessie ChessieSyntaxObject)

target_link_libraries(
    Chessie
    PUBLIC
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        ChessieCore
        ChessieSyntaxObject
)
    