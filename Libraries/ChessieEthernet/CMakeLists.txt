add_library(ChessieEthernet)

target_sources(
    ChessieEthernet
        PRIVATE
            ChessieEthernet.cpp)

target_include_directories(
    ChessieEthernet
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(
    TARGETS ChessieEthernet
    EXPORT ChessieLibrary-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ChessieEthernet/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ChessieEthernet)