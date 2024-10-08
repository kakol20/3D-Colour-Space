﻿// main.h : Include file for standard system include files,
// or project specific include files.

#ifndef MAIN_H
#define MAIN_H

//#define USE_MAP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <map>
#include <unordered_map>

#include "maths/Matrix.h"

#include "colorSpaces/sRGB.h"
#include "colorSpaces/LinearRGB.h"
#include "colorSpaces/CIE_XYZ.h"
#include "colorSpaces/LinearLMS.h"
#include "colorSpaces/LMS.h"
#include "colorSpaces/OkLab.h"
#include "colorSpaces/ColorSpaces.h"

enum OutputOption {
  LINEAR_RGB_O, CIE_XYZ_O, LINEAR_LMS_O, LMS_O, LAB_O
};
OutputOption option;

void GenerateOBJs();

void GenerateCSV();

void FindMaxValue();

#endif // !MAIN_H
