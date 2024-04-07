#include "ColorSpaces.h"

OkLab ColorSpaces::sRGBtoOkLab(const sRGB& srgb) {
    return OkLab::LMStoOkLab(
        LMS::LinearLMStoLMS(
            LinearLMS::XYZtoLinearLMS(
                CIE_XYZ::LinearRGBtoXYZ(
                    LinearRGB::sRGBtoLinearRGB(srgb)))));
}
