#include "sRGB.h"

std::string sRGB::Output() {
	return std::to_string(m_r) + " " + std::to_string(m_g) + " " + std::to_string(m_b);
}