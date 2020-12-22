#include "mainwindow.h"

#include <QApplication>
#include "microstripline.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
//    MicrostripLine msl = MicrostripLine(9.6, 50, 5, 0.5, 0.96, 0.396);
//    std::cout << "Conductor width: " << msl.width() << " mm\n";
//    std::cout << "Effective permittivity (with dispersion): " <<
//                 msl.epsilon_eff() << '\n';
//    std::cout << "Wave length: " << msl.waveLength() << " m\n";
//    std::cout << "Conductor loss: " << msl.conductorLoss() << " dB/m\n";
//    std::cout << "Q-factor: " << msl.qfactor(110) << '\n';
//    std::cout << "Limit frequency: " << msl.limFrequency() << " GHz\n";

    return 0;
}
