# ********************************************************************
# CMakeLists for tiandi_java project. jni for tiandi c/c++ sdk wrapper for windows and linux. 
# file: CMakeLists.txt
# author: hhool
# date: 2024-07-16
# ********************************************************************

cmake_minimum_required(VERSION 3.0)

project(tiandi_jni)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
MESSAGE( STATUS "JAVA_INCLUDE: " ${JAVA_INCLUDE})

# Check platforms
if (CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif(CMAKE_HOST_UNIX)
    set(LINUX 1)
endif()

# Build type
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Check system
if (LINUX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fPIC")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fPIC")
endif()

if (WINDOWS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
endif()

# Add Header files
if (WINDOWS)
    include_directories(${CMAKE_SOURCE_DIR}/platform/windows/CH-NVSDK_64/include)
elseif(LINUX)
    include_directories(${CMAKE_SOURCE_DIR}/platform/linux/CH-NVSDK_64/include)
endif()

set(COMMON_SRC_FILES
    ${CMAKE_SOURCE_DIR}/common/logger.cc
    ${CMAKE_SOURCE_DIR}/common/logger.h
    ${CMAKE_SOURCE_DIR}/common/time_utils.cc
    ${CMAKE_SOURCE_DIR}/common/time_utils.h)
add_library(common STATIC ${COMMON_SRC_FILES})

# Add source files
set(SRC_FILES
    CLS_NVDSDKHelper.cpp
    CLS_NVDSDKHelper.h
    common.h
    native_tiandi_jni_test.cc
    native_tiandi_jni.cc
    native_tiandi_jni.h
    nvsdk_struct_utils.cc
    nvsdk_struct_utils.h
    nvsdk_wrapper.cc
    nvsdk_wrapper.h)
if (WINDOWS)
elseif (LINUX)
    set(SRC_FILES ${SRC_FILES}
    CLS_NVDSDKHelper.cpp
    CLS_NVDSDKHelper.h)
endif()
# Add library
add_library(tiandi_jni SHARED ${SRC_FILES})
target_link_libraries(tiandi_jni common)

# Include directories
target_include_directories(tiandi_jni PRIVATE
    ${CMAKE_SOURCE_DIR})

# Add Jni library
message(STATUS "JNI_LIBRARIES: ${JNI_LIBRARIES}")
if (WINDOWS)
    target_link_libraries(tiandi_jni ${JNI_LIBRARIES})
elseif(LINUX)
    target_link_libraries(tiandi_jni ${JNI_LIBRARIES})
endif()


# Set output name
if (WINDOWS)
    set_target_properties(tiandi_jni PROPERTIES
        OUTPUT_NAME tiandi_jni)
elseif(LINUX)
    set_target_properties(tiandi_jni PROPERTIES
        OUTPUT_NAME libtiandi_jni)
endif()

# Set output suffix
if (WINDOWS)
    set_target_properties(tiandi_jni PROPERTIES
        SUFFIX ".dll")
elseif(LINUX)
    set_target_properties(tiandi_jni PROPERTIES
        SUFFIX ".so")
endif()

# Set output prefix
set_target_properties(tiandi_jni PROPERTIES
    PREFIX "")

# Set output install name
if(WINDOWS)
    set_target_properties(tiandi_jni PROPERTIES
        INSTALL_NAME "libtiandi_jni.dll")
elseif(LINUX)
    set_target_properties(tiandi_jni PROPERTIES
        INSTALL_NAME "libtiandi_jni.so")
endif()

# Set installation directory
set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/../src/main/")
set(MAVEN_PATH "resources/com/gshx/camera/tiandi/native")

# Install target
if(WINDOWS)
    install (DIRECTORY "${PROJECT_SOURCE_DIR}/platform/windows/CH-NVSDK_64/lib/" DESTINATION "${CMAKE_INSTALL_PREFIX}${MAVEN_PATH}/win64" FILES_MATCHING PATTERN "*.dll")
    install (TARGETS tiandi_jni DESTINATION "${CMAKE_INSTALL_PREFIX}${MAVEN_PATH}/win64")
elseif(LINUX)
    install (DIRECTORY "${PROJECT_SOURCE_DIR}/platform/linux/CH-NVSDK_64/lib/" DESTINATION "${CMAKE_INSTALL_PREFIX}${MAVEN_PATH}/linux64" FILES_MATCHING PATTERN "*.so")
    install (TARGETS tiandi_jni DESTINATION "${CMAKE_INSTALL_PREFIX}${MAVEN_PATH}/linux64")
endif()



