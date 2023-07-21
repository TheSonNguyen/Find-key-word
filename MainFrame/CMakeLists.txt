cmake_minimum_required(VERSION 3.26.4)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

#include - subproject
add_library(libmainFrame MainFrame.cpp)

