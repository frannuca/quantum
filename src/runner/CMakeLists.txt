project(runner)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/runner/*.cpp)
message(STATUS "************************************Sources=" ${SOURCES})
include_directories( ${Boost_INCLUDE_DIRS} )
link_directories(${Boost_LIBRARY_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/../include)
include_directories(${CMAKE_SOURCE_DIR}/time/include)

message(STATUS "Resolving runner source path")
message(STATUS ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

#Run through each source
foreach(testSrc ${SOURCES})
        #Extract the filename without an extension (NAME_WE)
        get_filename_component(testName ${testSrc} NAME_WE)
		message(STATUS "------------------------------>testname")
		message(STATUS ${testName})
		message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
        #Add compile target
        add_executable(${testName} ${testSrc})

        #link to Boost libraries AND your targets and dependencies
        target_link_libraries(${testName} ${Boost_LIBRARIES} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/time.lib)
        #I like to move testing binaries into a testBin directory
        set_target_properties(${testName} PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

        #Finally add it to test execution - 
        #Notice the WORKING_DIRECTORY and COMMAND
        add_test(NAME ${testName} 
                 WORKING_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
                 COMMAND ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/${testName} )
		message(STATUS "------------------------------>TEST ADDED")

endforeach(testSrc)