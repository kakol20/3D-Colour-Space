#include "LinearLMS.h"

//Matrix LinearLMS::ToLLMSMat({
//  0.8189330101, 0.3618667424, -0.1288597137,
//  0.0329845436, 0.9293118715, 0.0361456387,
//  0.0482003018, 0.2643662691, 0.633851707
//  }, 3, 3);
Matrix LinearLMS::ToLLMSMat({
  0.786454787007, 0.347515399073, -0.133970186080,
  0.033036011929, 0.930761948541, 0.036202039530,
  0.050929174685, 0.279333435621, 0.669737389694
  }, 3, 3);
Matrix LinearLMS::ToXYZMat(LinearLMS::ToLLMSMat);

LinearLMS::LinearLMS(const double l, const double m, const double s) {
  m_l = l;
  m_m = m;
  m_s = s;
}

LinearLMS::LinearLMS(const LinearLMS& other) {
  m_l = other.m_l;
  m_m = other.m_m;
  m_s = other.m_s;
}

LinearLMS LinearLMS::XYZtoLinearLMS(const CIE_XYZ& xyz) {
  Matrix out({ xyz.GetX(), xyz.GetY(), xyz.GetZ() }, 1, 3);
  out = LinearLMS::ToLLMSMat * out;
  return LinearLMS(out.GetValue(0, 0), out.GetValue(0, 1), out.GetValue(0, 2));
}

CIE_XYZ LinearLMS::LinearLMStoXYZ(const LinearLMS& lms) {
  Matrix out({ lms.GetL(), lms.GetM(), lms.GetS() }, 1, 3);
  out = LinearLMS::ToXYZMat * out;
  return CIE_XYZ(out.GetValue(0, 0), out.GetValue(0, 1), out.GetValue(0, 2));
}