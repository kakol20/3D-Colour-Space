#include "LinearLMS.h"

Matrix LinearLMS::ToLLMSMat({
    { 0.8189330101, 0.0329845436, 0.0482003018 },
    { 0.3618667424, 0.9293118715, 0.2643662691 },
    { -0.1288597137, 0.0361456387, 0.6338517070 }
    });
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
    Matrix out({ { xyz.GetX(), xyz.GetY(), xyz.GetZ()} });
    out = LinearLMS::ToLLMSMat * out;
    return LinearLMS(out.GetValue(0, 0), out.GetValue(0, 1), out.GetValue(0, 2));
}

CIE_XYZ LinearLMS::LinearLMStoXYZ(const LinearLMS& lms) {
    Matrix out({ {lms.GetL(), lms.GetM(), lms.GetS()} });
    out = LinearLMS::ToXYZMat * out;
    return CIE_XYZ(out.GetValue(0, 0), out.GetValue(0, 1), out.GetValue(0, 2));
}
