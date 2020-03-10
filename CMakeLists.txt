cmake_minimum_required(VERSION 2.8)
project(sockat CXX)

find_package(wxWidgets REQUIRED COMPONENTS net core base stc)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/MainFrame.hpp
	src/MainFrame.cpp
	src/Sockat.hpp
	src/Sockat.cpp
	src/Editors/HtmlEditor.hpp
	src/Editors/HtmlEditor.cpp
)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

add_custom_target(
  run
  COMMAND ${PROJECT_NAME}
  DEPENDS ${PROJECT_NAME}
  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
