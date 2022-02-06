add_library(
    ChessieCore
)

target_link_libraries(
    ChessieCore
    PRIVATE
        Qt5::Core   
)

target_sources(
    ChessieCore
    PRIVATE
        ChessieAllocator.cpp
        ChessieContainer.cpp
        ChessieDefaultAllocator.cpp
        ChessieUtilities.cpp
)

target_include_directories(
    ChessieCore 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS ChessieCore
    EXPORT ChessieLibrary-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/ChessieCore/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ChessieCore
)