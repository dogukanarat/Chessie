set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(
    ChessieBaseScene
)

target_link_libraries(
    ChessieBaseScene
    PUBLIC
        Qt5::Core
        Qt5::Widgets
        ChessieCore
)

target_sources(
    ChessieBaseScene
    PRIVATE
        ChessieBaseScene.cpp
        ChessieBaseScene/ChessieBaseScene.h
)

target_include_directories(
    ChessieBaseScene 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS ChessieBaseScene
    EXPORT ChessieObjects-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ChessieBaseScene/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ChessieBaseScene
)
