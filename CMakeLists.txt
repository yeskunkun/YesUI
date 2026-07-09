cmake_minimum_required(VERSION 3.20)

if(NOT WIN32) # 判断是不是Windows平台
message(FATAL_ERROR "YesUI 仅支持Windows平台编译")
endif()

project(YesUI)

option(YESUI_BUILD_STATIC "Build YesUI as a static library" ON)
if(YESUI_BUILD_STATIC)
add_library(YesUI STATIC WindowsUILibrary/WindowsUILibrary.cpp) # 静态库
else()
add_library(YesUI SHARED WindowsUILibrary/WindowsUILibrary.cpp) # 动态库
endif()

set_property(TARGET YesUI PROPERTY CXX_STANDARD 14)
set_property(TARGET YesUI PROPERTY CXX_STANDARD_REQUIRED ON)
