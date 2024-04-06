#pragma once

#include "../maths/Matrix.h"
#include "CIE_XYZ.h"

class LinearLMS {
public:
    LinearLMS(const double l = 0, const double m = 0, const double s = 0);
    LinearLMS(const LinearLMS& other);
    ~LinearLMS() {};

    // ----- ASSIGNMENT OPERATOR -----

    inline LinearLMS& operator=(const LinearLMS& lms) {
        if (this == &lms) return *this;
        m_l = lms.m_l;
        m_m = lms.m_m;
        m_s = lms.m_s;
        return *this;
    };

    // ----- OTHER -----

    /// <summary>
    /// Convert CIE XYZ to Linear LMS
    /// </summary>
    /// <param name="xyz"></param>
    /// <returns></returns>
    static LinearLMS XYZtoLinearLMS(const CIE_XYZ& xyz);

    /// <summary>
    /// Convert Linear LMS to CIE XYZ
    /// </summary>
    /// <param name="lms"></param>
    /// <returns></returns>
    static CIE_XYZ LinearLMStoXYZ(const LinearLMS& lms);

    static Matrix ToLLMSMat;
    static Matrix ToXYZMat;

    inline double GetL() const { return m_l; };
    inline double GetM() const { return m_m; };
    inline double GetS() const { return m_s; };

    inline std::string Output() const { return std::to_string(m_l) + " " + std::to_string(m_s) + " " + std::to_string(m_m); };

private:
    double m_l, m_m, m_s;
};