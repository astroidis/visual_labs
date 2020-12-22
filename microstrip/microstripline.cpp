#include "microstripline.h"

#include <cmath>

MicrostripLine::MicrostripLine()
{
    this->eps = -1;
    this->rho = -1;
    this->f = -1;
    this->h = -1;
    this->w_h = -1;
    this->v_c = -1;
    this->qf_norm = -1;
}

MicrostripLine::MicrostripLine(double eps, double rho, double f, double h,
                               double w_h, double v_c, double qf)
{
    this->eps = eps;
    this->rho = rho;
    this->f = f;
    this->h = h;
    this->w_h = w_h;
    this->v_c = v_c;
    this->qf_norm = qf;
}

double MicrostripLine::width()
{
    return h * w_h;
}

double MicrostripLine::waveLength()
{
    return 0.3 / ( f * std::sqrt(epsilon_e0()) );
}

double MicrostripLine::conductorLoss()
{
    // ширина проводника в метрах, домножается на 10^(-3)
    return 0.0715 * std::sqrt(f) / (rho * width() * 0.001);
}

/* вычисление добротности по значению
 * нормализованной добротности qf_norm
 */
double MicrostripLine::qfactor()
{
    // высота диэлектрика в метрах, домножается на 10^(-3)
    return ( qf_norm*h*0.001*std::sqrt(f) ) / 0.0008;
}

/* эффективная диэлектрическая постоянная, эпсилон_э
 * без учета дисперсии
**/
double MicrostripLine::epsilon_e0()
{
    return 1 / std::pow(v_c, 2);
}

/* эффективная диэлектрическая проницаемость
 * с учетом диcперсии
 */
double MicrostripLine::epsilon_eff()
{
    double F = 2.51 * h * f / rho;
    double G = 0.6 + 0.009 * rho;
    double e_eff0 = epsilon_e0();
    return e_eff0 + (eps-e_eff0) * (G*std::pow(F, 2)) / (1 + G*std::pow(F, 2));
}


double MicrostripLine::limFrequency()
{
    return 106 / (h * std::sqrt(eps));
}

