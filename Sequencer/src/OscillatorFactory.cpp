#include "include/OscillatorFactory.h"
#include "include/Wavetype.h"
#include "include/SineBuilder.h"
#include "include/FmBuilder.h"
#include "include/TriangleBuilder.h"
#include "include/RisingSawtoothBuilder.h"

OscillatorFactory::OscillatorFactory() {
    m_builders.insert( SINE, new SineBuilder() );
    m_builders.insert( FM, new FmBuilder() );
    m_builders.insert( RSAW, new RisingSawtoothBuilder() );
    m_builders.insert( TRIANGLE, new TriangleBuilder() );
}

Oscillator * OscillatorFactory::buildOscillator( Wavetype wavetype ) {
    return m_builders.value( wavetype );
}
