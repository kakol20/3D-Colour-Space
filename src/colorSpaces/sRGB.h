#pragma once

#include <string>

class sRGB {
public:
	sRGB(const double r, const double g, const double b) {
		m_r = r;
		m_g = g;
		m_b = b;
	}
	~sRGB() {};

	std::string Output();

private:
	double m_r, m_g, m_b;
};