# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("quantum")
message(STATUS "Setting MSVC flags")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")

set(BOOST_LIBRARYDIR "C:/Boost/lib")
set(BOOST_ROOT "C:/Boost/include/boost-1_68")
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

#Setup CMake to run tests
enable_testing()

find_package(Boost 1.68 COMPONENTS system filesystem unit_test_framework date_time REQUIRED)

if(NOT Boost_FOUND)
	error("BOOST LIBS not found")
endif()

message(STATUS "Boost_INCLUDE_DIRS")
message(STATUS ${Boost_INCLUDE_DIRS})

message(STATUS "Boost_LIBRARIES")
message(STATUS ${Boost_LIBRARIES})

message(STATUS "Boost_LIBRARY_DIRS")
message(STATUS ${Boost_LIBRARY_DIRS})


# Include sub-projects.

add_subdirectory ("time")

add_subdirectory("runner")

#add_dependencies(runner time)


set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT runner)