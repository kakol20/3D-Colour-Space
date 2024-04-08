#include "OkLab.h"

class ColorSpaces {
public:
    ColorSpaces() {};
    ~ColorSpaces() {};

    static void Initialise();

    static CIE_XYZ sRGBtoXYZ(const sRGB& srgb);
    static LinearLMS sRGBtoLinearLMS(const sRGB& srgb);
    static LMS sRGBtoLMS(const sRGB& srgb);
    static OkLab sRGBtoOkLab(const sRGB& srgb);
};