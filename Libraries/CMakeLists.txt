##############################################################################################

add_library(chessiecommon)

target_sources(chessiecommon PRIVATE ChessieCommon/ChessieContainer.cpp)

target_include_directories(
    chessiecommon 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/ChessieCommon/Include>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(
    TARGETS chessiecommon
    EXPORT chessielib-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ChessieCommon/Include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ChessieCommon)

##############################################################################################

add_library(chessieethernet)

target_sources(chessieethernet PRIVATE ChessieEthernet/ChessieEthernet.cpp)

target_include_directories(
    chessieethernet
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/ChessieEthernet/Include>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(
    TARGETS chessieethernet
    EXPORT chessielib-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ChessieEthernet/Include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ChessieEthernet)

##############################################################################################

install(
    EXPORT chessielib-config
    NAMESPACE chessielib::
    DESTINATION ${PROJECT_SOURCE_DIR}/cmake)

##############################################################################################