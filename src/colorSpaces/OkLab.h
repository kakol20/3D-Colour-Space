#pragma once

#include "LMS.h"

/// <summary>
/// https://bottosson.github.io/posts/oklab/
/// </summary>
class OkLab {
public:
	OkLab(const double l = 0, const double a = 0, const double b = 0);
	OkLab(const OkLab& other);
	~OkLab() {};

	// ----- ASSIGNMENT OPERATOR -----

	inline OkLab& operator=(const OkLab& other) {
		if (this == &other) return *this;
		m_l = other.m_l;
		m_a = other.m_a;
		m_b = other.m_b;
		return *this;
	}

	// ----- OTHER -----

	static Matrix ToOkLabMat;
	static Matrix ToLMSMat;

	inline double GetL() const { return m_l; };
	inline double GetA() const { return m_a; };
	inline double GetB() const { return m_b; };

	inline std::string Output() const { return std::to_string(m_a) + " " + std::to_string(m_b) + " " + std::to_string(m_l); };

	/// <summary>
	/// Convert LMS to OkLab
	/// </summary>
	/// <param name="lms"></param>
	/// <returns></returns>
	static OkLab LMStoOkLab(const LMS& lms);

	/// <summary>
	/// Convert LMS
	/// </summary>
	/// <param name="lab"></param>
	/// <returns></returns>
	static LMS OkLabtoLMS(const OkLab& lab);

private:
	double m_l, m_a, m_b;
};