#############################################################################
# Name:        samples/minimal/CMakeListst.txt
# Purpose:     Sample CMake file to show usage of cmake for wxWidgets users
# Author:      Tobias Taschner
# Created:     2016-10-23
# Copyright:   (c) 2016 wxWidgets development team
# Licence:     wxWindows licence
#############################################################################

#
# This file is just a sample to show using cmake from an application
# If you want to build the minimal and other samples please use the
# wxBUILD_SAMPLES option when using cmake on the library
#

# Declare the minimum required CMake version
cmake_minimum_required(VERSION 3.16.5)

set(CMAKE_OSX_ARCHITECTURES arm64)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Name the project
project(FileRenamer_mac)

# Request the required wxWidgets libs
find_package(wxWidgets 3.1.7 COMPONENTS core base REQUIRED)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

# Define a variable containing a list of source files for the project
set(SRC_FILES
        main.cpp MainFrame.h MainFrame.cpp ListButton.h ListButton.cpp InsertWindow.h InsertWindow.cpp Border.h Border.cpp AddRuleFrame.h AddRuleFrame.cpp DeleteWindow.h DeleteWindow.cpp callback.hpp)
if(WIN32)
    # Include a RC file for windows
    list(APPEND SRC_FILES ../sample.rc)
endif()

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            RESOURCE "../../src/osx/carbon/wxmac.icns"
            MACOSX_BUNDLE_ICON_FILE wxmac.icns
            MACOSX_BUNDLE_COPYRIGHT "Copyright wxWidgets"
            MACOSX_BUNDLE_GUI_IDENTIFIER "org.wxwidgets.minimal"
            )
endif()