##############################################################################################

add_library(
    ChessieCore
)

target_sources(
    ChessieCore
    PRIVATE
        ChessieCore/ChessieContainer.cpp
        ChessieCore/ChessieAllocator.cpp
        ChessieCore/ChessieDefaultAllocator.cpp
)

target_include_directories(
    ChessieCore 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/ChessieCore/Include>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(
    TARGETS ChessieCore
    EXPORT ChessieLibrary-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ChessieCore/Include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ChessieCore)

##############################################################################################

add_library(ChessieEthernet)

target_sources(ChessieEthernet PRIVATE ChessieEthernet/ChessieEthernet.cpp)

target_include_directories(
    ChessieEthernet
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/ChessieEthernet/Include>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(
    TARGETS ChessieEthernet
    EXPORT ChessieLibrary-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ChessieEthernet/Include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ChessieEthernet)

##############################################################################################

install(
    EXPORT ChessieLibrary-config
    NAMESPACE chessielib::
    DESTINATION ${PROJECT_SOURCE_DIR}/cmake)

##############################################################################################