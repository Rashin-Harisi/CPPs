#include "Point.hpp"


void get_cordinations(double cor[2], Point const &t)
{
    const double scale = 256.0;
    cor[0] = static_cast<double>(t.getX().getRawBits()) / scale;
    cor[1] = static_cast<double>(t.getY().getRawBits()) / scale;;
}

double cross_calculation(const double u[2], const double v[2])
{
    return (u[0]*v[1] - u[1]*v[0]);
}

void vecotr_creation(double result[2],const double n[2], const double m[2])
{
    result[0] = m[0] - n[0];
    result[1] = m[1] - n[1];
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    double a_cor[2];
    double b_cor[2];
    double c_cor[2];
    double p_cor[2];

    get_cordinations(a_cor, a);
    get_cordinations(b_cor, b);
    get_cordinations(c_cor, c);
    get_cordinations(p_cor, point);

    double ab_vector[2];
    double ap_vector[2];
    double bc_vector[2];
    double bp_vector[2];
    double ca_vector[2];
    double cp_vector[2];

    vecotr_creation(ab_vector, a_cor, b_cor);
    vecotr_creation(ap_vector, a_cor, p_cor);
    vecotr_creation(bc_vector, b_cor, c_cor);
    vecotr_creation(bp_vector, b_cor, p_cor);
    vecotr_creation(ca_vector, c_cor, a_cor);
    vecotr_creation(cp_vector, c_cor, p_cor);

    double d1_cross = cross_calculation(ab_vector, ap_vector);
    double d2_cross = cross_calculation(bc_vector, bp_vector);
    double d3_cross = cross_calculation(ca_vector,cp_vector);

    if ((d1_cross < 0 && d2_cross < 0 && d3_cross < 0) ||
        (d1_cross > 0 && d2_cross > 0 && d3_cross > 0))
        return (true);
    return (false);
}