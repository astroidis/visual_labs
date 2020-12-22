#ifndef MICROSTRIPLINE_H
#define MICROSTRIPLINE_H


class MicrostripLine
{
public:
    double eps;  // диэлектрическая постоянная
    double rho;  // волновое сопротивление, Ом
    double f;  // рабочая частота, ГГц
    double h;  // толщина диэлектрика, мм
    double w;  // ширина линии, мм
    double w_h;  // относительная ширина проводника
    double v_c;  // относительная скорость распространения волны
    double qf_norm;  // нормализованная добротность

    MicrostripLine();
    MicrostripLine(double eps, double rho, double f, double h,
                   double w_h, double v_c, double qf);

    double waveLength();
    double conductorLoss();
    double qfactor();  // добротность
    double limFrequency();
    double epsilon_e0();
    double epsilon_eff();
    double resistance();
    double width();
};

#endif // MICROSTRIPLINE_H
