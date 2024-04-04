#include <cmath>

#include "LinearRGB.h"

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

    if (out.m_r <= 0.04045) {
        out.m_r /= 12.92;
    }
    else {
        out.m_r = std::pow((out.m_r + 0.055) / 1.055, 2.4);
    }

    if (out.m_g <= 0.04045) {
        out.m_g /= 12.92;
    }
    else {
        out.m_g = std::pow((out.m_g + 0.055) / 1.055, 2.4);
    }

    if (out.m_b <= 0.04045) {
        out.m_b /= 12.92;
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

    if (r <= 0.0031318) {
        r *= 12.92;
    }
    else {
        r = std::pow(1.055 * r, 1. / 2.4) - 0.055;
    }

    if (g <= 0.0031318) {
        g *= 12.92;
    }
    else {
        g = std::pow(1.055 * g, 1. / 2.4) - 0.055;
    }

    if (b <= 0.0031318) {
        b *= 12.92;
    }
    else {
        b = std::pow(1.055 * b, 1. / 2.4) - 0.055;
    }

    return sRGB(r, g, b);
}
