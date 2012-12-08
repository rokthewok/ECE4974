#include "include/TriangleBuilder.h"
#include "include/TriangleOscillator.h"

Oscillator * TriangleBuilder::buildOscillator(int sampleRate, float frequency) {
    return new TriangleOscillator( sampleRate, frequency );
}
