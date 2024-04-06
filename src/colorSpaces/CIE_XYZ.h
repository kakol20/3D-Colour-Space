#pragma once

#include "../maths/Matrix.h"
#include "LinearRGB.h"

class CIE_XYZ {
public:
    CIE_XYZ(const double x = 0, const double y = 0, const double z = 0);
    CIE_XYZ(const CIE_XYZ& xyz);
    ~CIE_XYZ() {};

    // ----- ASSIGNMENT OPERATOR -----

    inline CIE_XYZ& operator=(const CIE_XYZ& xyz) {
        if (this == &xyz) return *this;
        m_x = xyz.m_x;
        m_y = xyz.m_y;
        m_z = xyz.m_z;
        return *this;
    };

    // ----- OTHER -----

    /// <summary>
    /// Converts Linear RGB to CIE XYZ
    /// </summary>
    /// <param name="rgb"></param>
    /// <returns></returns>
    static CIE_XYZ LinearRGBtoXYZ(const LinearRGB& rgb);

    /// <summary>
    /// Converts CIE XYZ to Linear RGB
    /// </summary>
    /// <param name="xyz"></param>
    /// <returns></returns>
    static LinearRGB XYZtoLinearRGB(const CIE_XYZ& xyz);

    inline double GetX() const { return m_x; };
    inline double GetY() const { return m_y; };
    inline double GetZ() const { return m_z; };

    inline std::string Output() const { return std::to_string(m_x) + " " + std::to_string(m_y) + " " + std::to_string(m_z); };

    static Matrix ToXYZMat;
    static Matrix ToRGBMat;

private:
    double m_x, m_y, m_z;
};