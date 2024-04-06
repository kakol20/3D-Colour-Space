#pragma once

#include "LinearLMS.h"

class LMS {
public:
    LMS(const double l = 0, const double m = 0, const double s = 0);
    LMS(const LMS& other);
    ~LMS() {};

    // ----- ASSIGNMENT OPERATOR -----

    inline LMS& operator=(const LMS& other) {
        if (this == &other) return *this;
        m_l = other.m_l;
        m_m = other.m_m;
        m_s = other.m_s;
        return *this;
    }

    // ----- OTHER -----

    /// <summary>
    /// Convert Linear LMS to non-linear LMS
    /// </summary>
    /// <param name="lms"></param>
    /// <returns></returns>
    static LMS LinearLMStoLMS(const LinearLMS& lms);

    /// <summary>
    /// Convert non-linear LMS to Linear LMS
    /// </summary>
    /// <param name="lms"></param>
    /// <returns></returns>
    static LinearLMS LMStoLinearLMS(const LMS& lms);

    inline double GetL() const { return m_l; };
    inline double GetM() const { return m_m; };
    inline double GetS() const { return m_s; };

    inline std::string Output() const { return std::to_string(m_l) + " " + std::to_string(m_s) + " " + std::to_string(m_m); };

private:

    double m_l, m_m, m_s;
};