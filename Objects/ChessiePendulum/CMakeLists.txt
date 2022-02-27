set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(
    ChessiePendulum
)

target_link_libraries(
    ChessiePendulum
    PUBLIC
        Qt5::Core
        Qt5::Widgets
        ChessieCore
)

target_sources(
    ChessiePendulum
    PRIVATE
        ChessiePendulum.cpp
        ChessiePendulum/ChessiePendulum.h
)

target_include_directories(
    ChessiePendulum 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS ChessiePendulum
    EXPORT ChessieObjects-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ChessiePendulum/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ChessiePendulum
)
