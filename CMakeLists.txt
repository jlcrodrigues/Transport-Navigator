cmake_minimum_required(VERSION 3.10)
project(transport-navigator)

set(CMAKE_CXX_STANDARD 11)

set(CREATE_EXE TRUE)

set(SOURCE_FILES
		src/App.h
		src/graph.h
		src/Navigator.h
		src/Position.h
		src/Stop.h

		src/App.cpp
		src/graph.cpp
		src/Navigator.cpp
		src/Position.cpp
		src/Stop.cpp
		)

set(TEST_FILES
		tests/GraphTest.cpp
		tests/PositionTest.cpp
		tests/StopTest.cpp
		)

include_directories(src)

if(CMAKE_BUILD_TYPE MATCHES Debug)
	add_subdirectory(tests/googletest)
	include_directories(tests/googletest/googletest/include)
	include_directories(tests/googletest/googlemock/include)

	add_executable(${CMAKE_PROJECT_NAME}_run mainTest.cpp ${TEST_FILES} ${SOURCE_FILES})

	target_link_libraries(${CMAKE_PROJECT_NAME}_run gtest gtest_main)
	message("Debug mode")
endif()

if (CMAKE_BUILD_TYPE MATCHES Release)
	add_executable(${CMAKE_PROJECT_NAME}_run main.cpp ${SOURCE_FILES})
	message("Release mode")
endif()
