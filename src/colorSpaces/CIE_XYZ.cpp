#include "CIE_XYZ.h"

//Matrix CIE_XYZ::ToXYZMat({
//    0.4124564, 0.3575761, 0.1804375,
//    0.2126729, 0.7151522, 0.0721750,
//    0.0193339, 0.1191920, 0.9503041
//  }, 3, 3);

Matrix CIE_XYZ::ToXYZMat({
  0.433949940556, 0.376209769903, 0.189840289541,
  0.212672878733, 0.715152128484, 0.072174992783,
  0.017756582754, 0.109467961022, 0.872775456224
  }, 3, 3);

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
  Matrix out({ rgb.GetR(), rgb.GetG(), rgb.GetB() }, 1, 3);
  out = CIE_XYZ::ToXYZMat * out;

  return CIE_XYZ(out.GetValue(0, 0), out.GetValue(0, 1), out.GetValue(0, 2));
}

LinearRGB CIE_XYZ::XYZtoLinearRGB(const CIE_XYZ& xyz) {
  Matrix out({ xyz.GetX(), xyz.GetY(), xyz.GetZ() }, 1, 3);
  out = CIE_XYZ::ToRGBMat * out;

  return LinearRGB(out.GetValue(0, 0), out.GetValue(0, 1), out.GetValue(0, 2));
}