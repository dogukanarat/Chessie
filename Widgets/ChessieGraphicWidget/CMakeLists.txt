add_library(
    ChessieGraphicWidget
)

target_link_libraries(
    ChessieGraphicWidget
    PUBLIC
        Qt5::Core
        Qt5::Widgets
        ChessieBaseWidget
        ChessieBaseScene
        ChessiePendulum
        ChessiePathPlanner
)

target_sources(
    ChessieGraphicWidget
    PRIVATE
        ChessieGraphicWidget.ui
        ChessieGraphicWidget.cpp
        ChessieGraphicWidget/ChessieGraphicWidget.h
)

target_include_directories(
    ChessieGraphicWidget 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS ChessieGraphicWidget
    EXPORT ChessieWidgets-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ChessieGraphicWidget/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ChessieGraphicWidget
)