set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(
    ChessieSyntaxObject
)

target_link_libraries(
    ChessieSyntaxObject
    PUBLIC
        Qt5::Core
        Qt5::Widgets
        ChessieCore
)

target_sources(
    ChessieSyntaxObject
    PRIVATE
        ChessieSyntaxObject.cpp
        ChessieSyntaxObject/ChessieSyntaxObject.h
)

target_include_directories(
    ChessieSyntaxObject 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS ChessieSyntaxObject
    EXPORT ChessieObjects-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ChessieSyntaxObject/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ChessieSyntaxObject
)
