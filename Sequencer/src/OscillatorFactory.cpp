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

OscillatorFactory::~OscillatorFactory() {
    QHash<Wavetype, OscillatorBuilder *>::iterator it;

    for( it = m_builders.begin(); it != m_builders.end(); it++ ) {
        delete it.value();
    }
}

Oscillator * OscillatorFactory::buildOscillator( Wavetype wavetype, int sampleRate, float frequency ) {
    return m_builders.value( wavetype )->buildOscillator( sampleRate, frequency );
}
