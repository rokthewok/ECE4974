#include "include/SineBuilder.h"
#include "include/Oscillator.h"
#include "include/SineOscillator.h"

Oscillator * SineBuilder::buildOscillator( int sampleRate, float frequency ) {
    return new SineOscillator( sampleRate, frequency );
}
