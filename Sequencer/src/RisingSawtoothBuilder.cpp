#include "include/RisingSawtoothBuilder.h"
#include "include/RisingSawtoothOscillator.h"

Oscillator * RisingSawtoothBuilder::buildOscillator(int sampleRate, float frequency) {
    return new RisingSawtoothOscillator( sampleRate, frequency );
}
