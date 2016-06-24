# Copyright (C) 2016, Canonical Ltd.
# All rights reserved.

# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.

cmake_minimum_required(VERSION 2.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

find_package(Qt5Core REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Multimedia REQUIRED)

set(
  SRC
  src/plugin.cpp
  src/reactsoundmanager.cpp
)

add_library(
  soundmanager MODULE
  ${SRC}
)

target_compile_definitions(soundmanager PRIVATE DQT_PLUGIN)
set_target_properties(
  soundmanager
  PROPERTIES LIBRARY_OUTPUT_DIRECTORY $ENV{URN_OUTPUT_DIR}
)
qt5_use_modules(soundmanager Core Qml Quick Multimedia)

