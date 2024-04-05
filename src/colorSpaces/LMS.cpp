#include "LMS.h"

#include <cmath>

LMS::LMS(const double l, const double m, const double s) {
    m_l = l;
    m_m = m;
    m_s = s;
}

LMS::LMS(const LMS& other) {
    m_l = other.m_l;
    m_m = other.m_m;
    m_s = other.m_s;
}

LMS LMS::LinearLMStoLMS(const LinearLMS& lms) {
    return LMS(std::cbrt(lms.GetL()), std::cbrt(lms.GetM()), std::cbrt(lms.GetS()));
}

LinearLMS LMS::LMStoLinearLMS(const LMS& lms) {
    return LinearLMS(std::pow(lms.GetL(), 3.), std::pow(lms.GetM(), 3.), std::pow(lms.GetS(), 3.));
}
