#include "OkLab.h"

class ColorSpaces {
public:
    ColorSpaces() {};
    ~ColorSpaces() {};

    static OkLab sRGBtoOkLab(const sRGB& srgb);
};