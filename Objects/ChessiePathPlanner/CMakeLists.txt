set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(
    ChessiePathPlanner
)

target_link_libraries(
    ChessiePathPlanner
    PUBLIC
        Qt5::Core
        Qt5::Widgets
        ChessieCore
        ChessieBaseScene
        DubinsPath
)

target_sources(
    ChessiePathPlanner
    PRIVATE
        ChessiePathPlanner.cpp
        ChessiePathPlanner/ChessiePathPlanner.h
)

target_include_directories(
    ChessiePathPlanner 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS ChessiePathPlanner
    EXPORT ChessieObjects-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ChessiePathPlanner/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ChessiePathPlanner
)
