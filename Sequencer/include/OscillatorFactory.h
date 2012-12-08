#ifndef OSCILLATORFACTORY_H
#define OSCILLATORFACTORY_H

#include <QHash>
#include "include/Oscillator.h"
#include "include/Wavetype.h"
#include "include/OscillatorBuilder.h"

class OscillatorFactory {
public:
    OscillatorFactory();
    Oscillator * buildOscillator( Wavetype wavetype );
private:
    QHash<Wavetype, OscillatorBuilder *> m_builders;
};

#endif // OSCILLATORFACTORY_H
