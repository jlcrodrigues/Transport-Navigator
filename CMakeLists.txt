cmake_minimum_required(VERSION 3.10)
project(transport-navigator)

set(CMAKE_CXX_STANDARD 11)

set(CREATE_EXE TRUE)

set(SOURCE_FILES
		src/Menu/App.h
		src/Menu/ChooseStartState.h
		src/Menu/ChooseStopState.h
		src/Menu/CoordsState.h
		src/Menu/InitialState.h
		src/Menu/PathState.h
		src/Menu/SettingsState.h
		src/Menu/State.h
		src/Navigator/graph.h
		src/Navigator/Navigator.h
		src/Navigator/Position.h
		src/Navigator/Stop.h
		src/Navigator/minHeap.h

		src/Menu/App.cpp
		src/Menu/ChooseStartState.cpp
		src/Menu/ChooseStopState.cpp
		src/Menu/CoordsState.cpp
		src/Menu/InitialState.cpp
		src/Menu/PathState.cpp
		src/Menu/SettingsState.cpp
		src/Menu/State.cpp
		src/Navigator/graph.cpp
		src/Navigator/Navigator.cpp
		src/Navigator/Position.cpp
		src/Navigator/Stop.cpp)

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
