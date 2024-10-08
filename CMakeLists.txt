﻿# CMakeList.txt : CMake project for 3D Colour Space, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("3D Colour Space")

# set(3DColorSpace "3D Colour Space")

# Add source to this project's executable.
add_executable (3DColorSpace "src/main.h" 
	"src/main.cpp"  
	"src/colorSpaces/LinearRGB.cpp" 
	"src/colorSpaces/sRGB.h" 
	"src/maths/Pseudo2DArray.hpp"
	"src/maths/Matrix.cpp" 
	"src/colorSpaces/CIE_XYZ.cpp" 
	"src/colorSpaces/LinearLMS.cpp"
	"src/colorSpaces/LMS.cpp"
	"src/colorSpaces/OkLab.cpp" 
	"src/colorSpaces/ColorSpaces.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 3DColorSpace PROPERTY CXX_STANDARD 20)
endif()
