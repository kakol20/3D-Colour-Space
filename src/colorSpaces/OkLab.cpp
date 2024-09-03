#include "OkLab.h"

//Matrix OkLab::ToOkLabMat({
//  0.2104542553, 0.7936177850, -0.0040720468,
//  1.9779984951, -2.4285922050, 0.4505937099,
//  0.0259040371, 0.7827717662, -0.8086757660
//  }, 3, 3);
Matrix OkLab::ToOkLabMat({
  0.210454256657, 0.793617790117, -0.004072046774,
  1.977998495100, -2.428592205000, 0.450593709900,
  0.025904036503, 0.782771748147, -0.808675784650
  }, 3, 3);
Matrix OkLab::ToLMSMat(OkLab::ToOkLabMat);

OkLab::OkLab(const double l, const double a, const double b) {
  m_l = l;
  m_a = a;
  m_b = b;
}

OkLab::OkLab(const OkLab& other) {
  m_l = other.m_l;
  m_a = other.m_a;
  m_b = other.m_b;
}

OkLab OkLab::LMStoOkLab(const LMS& lms) {
  Matrix out({ lms.GetL(), lms.GetM(), lms.GetS() }, 1, 3);
  out = OkLab::ToOkLabMat * out;
  return OkLab(out.GetValue(0, 0), out.GetValue(0, 1), out.GetValue(0, 2));
}

LMS OkLab::OkLabtoLMS(const OkLab& lab) {
  Matrix out({ lab.GetL(), lab.GetA(), lab.GetB() }, 1, 3);
  out = OkLab::ToLMSMat * out;
  return LMS(out.GetValue(0, 0), out.GetValue(0, 1), out.GetValue(0, 2));
}