#include "CIE_XYZ.h"

Matrix CIE_XYZ::ToXYZMat({
    {0.4124564, 0.2126729, 0.0193339},
    {0.3575761, 0.7151522, 0.1191920},
    {0.1804375, 0.0721750, 0.9503041}
});

Matrix CIE_XYZ::ToRGBMat(CIE_XYZ::ToXYZMat);

//CIE_XYZ::CIE_XYZ() {
//    m_x = 0;
//    m_y = 0;
//    m_z = 0;
//}

CIE_XYZ::CIE_XYZ(const double x, const double y, const double z) {
    m_x = x;
    m_y = y;
    m_z = z;
}

CIE_XYZ::CIE_XYZ(const CIE_XYZ& xyz) {
    m_x = xyz.m_x;
    m_y = xyz.m_y;
    m_z = xyz.m_z;
}

CIE_XYZ CIE_XYZ::LinearRGBtoXYZ(const LinearRGB& rgb) {
    Matrix outMatrix({ {rgb.GetR(), rgb.GetG(), rgb.GetB()} });
    outMatrix = CIE_XYZ::ToXYZMat * outMatrix;

    return CIE_XYZ(outMatrix.GetValue(0, 0), outMatrix.GetValue(0, 1), outMatrix.GetValue(0, 2));
}
