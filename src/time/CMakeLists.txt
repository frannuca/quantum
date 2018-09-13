project(time)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/time/src/*.cpp)
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/time/include/*.h)

include_directories( ${Boost_INCLUDE_DIRS} )
link_directories(${Boost_LIBRARY_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/time/src)
include_directories(${CMAKE_SOURCE_DIR}/time/include)
include_directories( ${Boost_INCLUDE_DIRS} )
include_directories(${CMAKE_SOURCE_DIR}/../include)
add_definitions(-DEXPMODULE)

add_library(time SHARED ${SOURCES} ${HEADERS})


target_link_libraries (time ${Boost_LIBRARIES})