cmake_minimum_required(VERSION 3.13)
# Project information
project(Leb128
  VERSION 1.0.0
  DESCRIPTION "Little endian base 128 variable-length encoding."
  LANGUAGES CXX
)
# Compile options
add_compile_options(
	$<$<COMPILE_LANGUAGE:CXX>:-std=c++20>
)
# Add the library target
add_library(leb128
	include/leb128/leb128.h
	src/leb128/leb128.cc
)
# Setup include directories 
target_include_directories(leb128 PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

# Example and unit testing if this project is built separately
if (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
	# Add the example target
	add_executable(leb128_example examples/leb128_example.cc)
	# Add the includes
	target_include_directories(leb128_example PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the example target
	target_link_libraries(leb128_example
		PRIVATE 
			leb128
	)
	# Fetch google test
	include(FetchContent)
	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG release-1.10.0
	)
	FetchContent_MakeAvailable(googletest)
	enable_testing()
	include(GoogleTest)
	# Add the test target
	add_executable(leb128_test tests/leb128_test.cc)
	# Add the includes
	target_include_directories(leb128_test PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the test target
	target_link_libraries(leb128_test
		PRIVATE 
			leb128
			gtest_main 
			gtest
			gmock
	)
	# Discover unit tests
	gtest_discover_tests(leb128_test)
endif()
