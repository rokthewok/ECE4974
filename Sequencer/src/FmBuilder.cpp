#include "include/FmBuilder.h"
#include "include/FmOscillator.h"

Oscillator * FmBuilder::buildOscillator(int sampleRate, float frequency) {
    return new FmOscillator( sampleRate, frequency, 1.0f, 1.0f );
}
