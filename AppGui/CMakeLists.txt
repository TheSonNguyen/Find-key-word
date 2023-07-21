cmake_minimum_required(VERSION 3.26.4)

set(Sources appgui.cpp)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

add_executable(${PROJECT_NAME} WIN32 ${Sources})

target_include_directories(${PROJECT_NAME} PUBLIC
                          "${PROJECT_SOURCE_DIR}/MainFrame"
						  "${PROJECT_SOURCE_DIR}/HandingFile"
                          )
						  
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} libmainFrame libhandingFile)