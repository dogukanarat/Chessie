add_library(
    ChessieBaseWidget
)

target_link_libraries(
    ChessieBaseWidget
    PUBLIC
        Qt5::Core
        Qt5::Widgets
        ChessieCore
)

target_sources(
    ChessieBaseWidget
    PRIVATE
        ChessieBaseWidget.cpp
        ChessieBaseWidget/ChessieBaseWidget.h
)

target_include_directories(
    ChessieBaseWidget 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS ChessieBaseWidget
    EXPORT ChessieWidgets-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ChessieBaseWidget/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ChessieBaseWidget
)