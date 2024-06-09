cmake_minimum_required(VERSION 3.8)
project(learn_cpp)

###########
## Build ##
###########

if(CMAKE_VERSION VERSION_LESS "3.1")
    if(CMAKE_COMPILER_IS_GNUCXX)
      include(CheckCXXCompilerFlag)
      check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
      check_cxx_compiler_flag("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
      if(COMPILER_SUPPORTS_CXX11)
	add_definitions("-std=c++11")
      elseif(COMPILER_SUPPORTS_CXX0X)
	add_definitions("-std=c++0x")
      else()
	message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support.")
      endif()
    endif()
  else()
    set(CMAKE_CXX_STANDARD 11)
endif()

if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 8.0)
    set (CMAKE_CXX_STANDARD 17)
else()
    set (CMAKE_CXX_STANDARD 11)
endif()

add_subdirectory(src)
