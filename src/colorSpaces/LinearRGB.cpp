#include <cmath>

#include "LinearRGB.h"

double LinearRGB::Scalar = 387916. / 30017.;
double LinearRGB::ToLinearLimit = 11 / 280;
double LinearRGB::TosRGBLimit = LinearRGB::ToLinearLimit / LinearRGB::Scalar;

LinearRGB::LinearRGB(const double r, const double g, const double b) {
    m_r = r;
    m_g = g;
    m_b = b;
}

LinearRGB::LinearRGB(const LinearRGB& other) {
    m_r = other.m_r;
    m_g = other.m_g;
    m_b = other.m_b;
}

LinearRGB LinearRGB::sRGBtoLinearRGB(const sRGB& srgb) {
    LinearRGB out;

    out.m_r = srgb.GetR();
    out.m_g = srgb.GetG();
    out.m_b = srgb.GetB();

    if (out.m_r <= LinearRGB::ToLinearLimit) {
        out.m_r /= LinearRGB::Scalar;
    }
    else {
        out.m_r = std::pow((out.m_r + 0.055) / 1.055, 2.4);
    }

    if (out.m_g <= LinearRGB::ToLinearLimit) {
        out.m_g /= LinearRGB::Scalar;
    }
    else {
        out.m_g = std::pow((out.m_g + 0.055) / 1.055, 2.4);
    }

    if (out.m_b <= LinearRGB::ToLinearLimit) {
        out.m_b /= LinearRGB::Scalar;
    }
    else {
        out.m_b = std::pow((out.m_b + 0.055) / 1.055, 2.4);
    }

    return out;
}

sRGB LinearRGB::LinearRGBtosRGB(const LinearRGB& lrgb) {
    double r = lrgb.m_r;
    double g = lrgb.m_g;
    double b = lrgb.m_b;

    if (r <= LinearRGB::TosRGBLimit) {
        r *= LinearRGB::Scalar;
    }
    else {
      r = (1.055 * std::pow(r, 1. / 2.4)) - 0.055;
    }

    if (g <= LinearRGB::TosRGBLimit) {
        g *= LinearRGB::Scalar;
    }
    else {
      g = (1.055 * std::pow(g, 1. / 2.4)) - 0.055;
    }

    if (b <= LinearRGB::TosRGBLimit) {
        b *= LinearRGB::Scalar;
    }
    else {
      b = (1.055 * std::pow(b, 1. / 2.4)) - 0.055;
    }

    return sRGB(r, g, b);
}
