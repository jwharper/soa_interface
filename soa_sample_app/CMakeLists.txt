cmake_minimum_required(VERSION 2.8)

project (SOA)
cmake_policy(SET CMP0015 OLD)

include(FindProtobuf)
find_package(Protobuf REQUIRED)

# C++11 Standard flag check, source: http://www.guyrutenberg.com/2014/01/05/enabling-c11-c0x-in-cmake/
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC" )
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC" )
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fPIC")

set(BEXE $ENV{BUILD_EXE})
set(PTHREAD_LIBRARY ${PTHREAD_ROOT}pthread${PTHREAD_LIB_POSTFIX})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

IF( NOT ARCH )
    if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
        set( ARCH 64 )
        MESSAGE(STATUS Detecting\ architecture\ —\ 64-bit)
    else( CMAKE_SIZEOF_VOID_P EQUAL 8 )
        set( ARCH 32 )
        MESSAGE(STATUS Detecting\ architecture\ —\ 32-bit)
    endif( CMAKE_SIZEOF_VOID_P EQUAL 8 )

ELSE ( NOT ARCH )
    MESSAGE(STATUS Detecting\ architecture\ —\ ${ARCH}-bit)
ENDIF ( NOT ARCH )

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    #Mac OS X
    set(SYSTEM_DIR MacOS)
    MESSAGE(STATUS Checking\ OS:\ “${CMAKE_SYSTEM_NAME}”\ —\ Mac\ OSX)
    find_library(corefoundation_lib CoreFoundation)
    find_library(cfnetwork_lib CFNetwork)
    set(frameworks ${cfnetwork_lib} ${corefoundation_lib})

ELSE(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(SYSTEM_DIR Linux)
    LINK_DIRECTORIES(/usr/lib/i386-linux-gnu)
    MESSAGE(STATUS Checking\ OS:\ “${CMAKE_SYSTEM_NAME}”\ —\ Linux)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

LINK_DIRECTORIES(../lib/${SYSTEM_DIR})

INCLUDE_DIRECTORIES(usr/local/include)
INCLUDE_DIRECTORIES(proto_buff/include)
INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(src)

FILE(GLOB_RECURSE SRC src/*.cpp)

add_executable(SampleAutonomy ${SRC})
TARGET_LINK_LIBRARIES(SampleAutonomy wdm ${PROTOBUF_LIBRARY} ${frameworks} ${PTHREAD_LIBRARY})
