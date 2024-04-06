#pragma once

#include "sRGB.h"

class LinearRGB {
public:
    LinearRGB(const double r = 0, const double g = 0, const double b = 0);
    LinearRGB(const LinearRGB& other);
    ~LinearRGB() {};

    // ----- ASSIGNMENT OPERATOR -----

    inline LinearRGB& operator=(const LinearRGB& other) {
        if (this == &other) return *this;
        m_r = other.m_r;
        m_g = other.m_g;
        m_b = other.m_b;
        return *this;
    }

    // ----- OTHER -----

    /// <summary>
    /// Convert sRGB to Linear RGB
    /// </summary>
    /// <param name="srgb"></param>
    /// <returns></returns>
    static LinearRGB sRGBtoLinearRGB(const sRGB& srgb);

    /// <summary>
    /// Convert Linear RGB to sRGB
    /// </summary>
    /// <param name="lrgb"></param>
    /// <returns></returns>
    static sRGB LinearRGBtosRGB(const LinearRGB& lrgb);

    inline double GetR() const { return m_r; };
    inline double GetG() const { return m_g; };
    inline double GetB() const { return m_b; };

    inline std::string Output() const { return std::to_string(m_r) + " " + std::to_string(m_b) + " " + std::to_string(m_g); };

private:
    double m_r, m_g, m_b;
};