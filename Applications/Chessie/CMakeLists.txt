set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(
    Chessie
)

set(CUSTOM_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/GeneratedHeader.h")

execute_process(
    COMMAND python ${CRESSIE_SCRIPT_DIR}/HelloWorld.py ${CUSTOM_HEADER}
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

target_sources(
    Chessie 
    PRIVATE
        MainWindow.cpp
        Main.cpp
        MainWindow.ui
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
        ChessieBaseWidget
        ChessieGraphicWidget
        DubinsCurve
)

install(
    TARGETS Chessie
    EXPORT Chessie-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})


