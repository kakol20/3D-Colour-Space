#pragma once

#include <string>

class sRGB {
public:
	sRGB(const double r = 0, const double g = 0, const double b = 0) {
		m_r = r;
		m_g = g;
		m_b = b;
	}
	~sRGB() {};

	// ----- ASSINGMENT OPERATOR -----

	inline sRGB& operator=(const sRGB& other) {
		if (this == &other) return *this;
		m_r = other.m_r;
		m_g = other.m_g;
		m_b = other.m_b;
		return *this;
	};

	// ----- OTHER -----

	inline std::string Output() const { return std::to_string(m_r) + " " + std::to_string(m_g) + " " + std::to_string(m_b); };

	inline double GetR() const { return m_r; };
	inline double GetG() const { return m_g; };
	inline double GetB() const { return m_b; };

private:
	double m_r, m_g, m_b;
};