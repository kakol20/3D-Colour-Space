#include "ColorSpaces.h"

void ColorSpaces::Initialise() {
    // ----- CALCULATE CORRECTION -----

    sRGB white(1.0, 1.0, 1.0);

    CIE_XYZ white_xyz = ColorSpaces::sRGBtoXYZ(white);
    const CIE_XYZ o_xyz = white_xyz;
    const CIE_XYZ c_xyz(1. / o_xyz.GetX(), 1. / o_xyz.GetY(), 1. / o_xyz.GetZ());
    Matrix c_xyz_m({
        {c_xyz.GetX(), 0., 0.},
        {0., c_xyz.GetY(), 0.},
        {0., 0., c_xyz.GetZ()}
    });
    c_xyz_m *= CIE_XYZ::ToXYZMat;

    LinearLMS white_llms = ColorSpaces::sRGBtoLinearLMS(white);
    const LinearLMS o_llms = white_llms;
    const LinearLMS c_llms(1. / o_llms.GetL(), 1. / o_llms.GetM(), 1. / o_llms.GetS());
    Matrix c1_llms_m({
        {o_xyz.GetX(), 0., 0.},
        {0., o_xyz.GetY(), 0.},
        {0., 0., o_xyz.GetZ()}
    });
    Matrix c2_llms_m({
        {c_llms.GetL(), 0., 0.},
        {0., c_llms.GetM(), 0.},
        {0., 0., c_llms.GetS()}
    });
    c2_llms_m = c2_llms_m * LinearLMS::ToLLMSMat * c1_llms_m;

    LMS white_lms = ColorSpaces::sRGBtoLMS(white);
    Matrix c_lms_m({
        {white_llms.GetL(), 0., 0.},
        {0., white_llms.GetM(), 0.},
        {0., 0., white_llms.GetS()}
    });

    OkLab white_lab = ColorSpaces::sRGBtoOkLab(white);
    const OkLab o_lab = white_lab;
    const OkLab c_lab(1. / white_lab.GetL(), 1, 1);
    Matrix c_lab_m({
        {c_lab.GetL(), 0., 0.},
        {0., 1., 0.},
        {0., 0., 1.}
    });
    c_lab_m = c_lab_m * OkLab::ToOkLabMat * c_lms_m;

    // ----- APPLY CORRECTION -----

    CIE_XYZ::ToXYZMat = c_xyz_m;
    white_xyz = ColorSpaces::sRGBtoXYZ(white);

    LinearLMS::ToLLMSMat = c2_llms_m;
    white_llms = ColorSpaces::sRGBtoLinearLMS(white);

    white_lms = ColorSpaces::sRGBtoLMS(white);

    OkLab::ToOkLabMat = c_lab_m;
    white_lab = ColorSpaces::sRGBtoOkLab(white);

    const double t1 = o_lab.GetL();
    const double t2 = white_lab.GetL();

    // ----- INVERSION -----

    CIE_XYZ::ToRGBMat = CIE_XYZ::ToXYZMat;
    CIE_XYZ::ToRGBMat.Invert3x3();

    LinearLMS::ToXYZMat = LinearLMS::ToLLMSMat;
    LinearLMS::ToXYZMat.Invert3x3();

    OkLab::ToLMSMat = OkLab::ToOkLabMat;
    OkLab::ToLMSMat.Invert3x3();
}

CIE_XYZ ColorSpaces::sRGBtoXYZ(const sRGB& srgb) {
    return CIE_XYZ::LinearRGBtoXYZ(LinearRGB::sRGBtoLinearRGB(srgb));
}

LinearLMS ColorSpaces::sRGBtoLinearLMS(const sRGB& srgb) {
    return LinearLMS::XYZtoLinearLMS(ColorSpaces::sRGBtoXYZ(srgb));
}

LMS ColorSpaces::sRGBtoLMS(const sRGB& srgb) {
    return LMS::LinearLMStoLMS(ColorSpaces::sRGBtoLinearLMS(srgb));
}

OkLab ColorSpaces::sRGBtoOkLab(const sRGB& srgb) {
    return OkLab::LMStoOkLab(ColorSpaces::sRGBtoLMS(srgb));
}
