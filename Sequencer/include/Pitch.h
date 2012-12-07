#ifndef PITCH_H
#define PITCH_H

#define F_C0        16.35
#define F_CSHARP0   17.32
#define F_DFLAT0    F_CSHARP0
#define F_D0        18.35
#define F_DSHARP0   19.45
#define F_EFLAT0    F_DSHARP0
#define F_E0        20.60
#define F_F0        21.83
#define F_FSHARP0   21.83
#define F_GFLAT0    23.12
#define F_G0        24.50
#define F_GSHARP0   25.96
#define F_AFLAT0    F_GSHARP0
#define F_A0        27.50
#define F_ASHARP0   29.14
#define F_BFLAT0    F_ASHARP0
#define F_B0        30.87

#define F_C1        2 * F_C0
#define F_CSHARP1   2 * F_CSHARP0
#define F_DFLAT1    F_CSHARP1
#define F_D1        2 * F_D0
#define F_DSHARP1   2 * F_DSHARP0
#define F_EFLAT1    F_DSHARP1
#define F_E1        2 * F_E0
#define F_F1        2 * F_F0
#define F_FSHARP1   2 * F_FSHARP0
#define F_GFLAT1    F_FSHARP1
#define F_G1        2 * F_G0
#define F_GSHARP1   2 * F_GSHARP0
#define F_AFLAT1    F_GSHARP1
#define F_A1        2 * F_A0
#define F_ASHARP1   2 * F_ASHARP0
#define F_BFLAT1    F_ASHARP1
#define F_B1        2 * F_B0

#define F_C2        2 * F_C1
#define F_CSHARP2   2 * F_CSHARP1
#define F_DFLAT2    F_CSHARP2
#define F_D2        2 * F_D1
#define F_DSHARP2   2 * F_DSHARP1
#define F_EFLAT2    F_DSHARP2
#define F_E2        2 * F_E1
#define F_F2        2 * F_F1
#define F_FSHARP2   2 * F_FSHARP1
#define F_GFLAT2    F_FSHARP2
#define F_G2        2 * F_G1
#define F_GSHARP2   2 * F_GSHARP1
#define F_AFLAT2    F_GSHARP2
#define F_A2        2 * F_A1
#define F_ASHARP2   2 * F_ASHARP1
#define F_BFLAT2    F_ASHARP2
#define F_B2        2 * F_B1

#define F_C3        2 * F_C2
#define F_CSHARP3   2 * F_CSHARP2
#define F_DFLAT3    F_CSHARP3
#define F_D3        2 * F_D2
#define F_DSHARP3   2 * F_DSHARP2
#define F_EFLAT3    F_DSHARP3
#define F_E3        2 * F_E2
#define F_F3        2 * F_F2
#define F_FSHARP3   2 * F_FSHARP2
#define F_GFLAT3    F_FSHARP3
#define F_G3        2 * F_G2
#define F_GSHARP3   2 * F_GSHARP2
#define F_AFLAT3    F_GSHARP3
#define F_A3        2 * F_A2
#define F_ASHARP3   2 * F_ASHARP2
#define F_BFLAT3    F_ASHARP3
#define F_B3        2 * F_B2

#define F_C4        2 * F_C3
#define F_CSHARP4   2 * F_CSHARP3
#define F_DFLAT4    F_CSHARP4
#define F_D4        2 * F_D3
#define F_DSHARP4   2 * F_DSHARP3
#define F_EFLAT4    F_DSHARP4
#define F_E4        2 * F_E3
#define F_F4        2 * F_F3
#define F_FSHARP4   2 * F_FSHARP3
#define F_GFLAT4    F_FSHARP4
#define F_G4        2 * F_G3
#define F_GSHARP4   2 * F_GSHARP3
#define F_AFLAT4    F_GSHARP4
#define F_A4        2 * F_A3
#define F_ASHARP4   2 * F_ASHARP3
#define F_BFLAT4    F_ASHARP4
#define F_B4        2 * F_B3

#define F_C5        2 * F_C4
#define F_CSHARP5   2 * F_CSHARP4
#define F_DFLAT5    F_CSHARP5
#define F_D5        2 * F_D4
#define F_DSHARP5   2 * F_DSHARP4
#define F_EFLAT5    F_DSHARP5
#define F_E5        2 * F_E4
#define F_F5        2 * F_F4
#define F_FSHARP5   2 * F_FSHARP4
#define F_GFLAT5    F_FSHARP5
#define F_G5        2 * F_G4
#define F_GSHARP5   2 * F_GSHARP4
#define F_AFLAT5    F_GSHARP5
#define F_A5        2 * F_A4
#define F_ASHARP5   2 * F_ASHARP4
#define F_BFLAT5    F_ASHARP5
#define F_B5        2 * F_B4

//#define F_C6        2 * F_C0
//#define F_CSHARP6
//#define F_DFLAT6
//#define F_D6
//#define F_DSHARP6
//#define F_EFLAT6
//#define F_E6
//#define F_F6
//#define F_FSHARP6
//#define F_GFLAT6
//#define F_G6
//#define F_GSHARP6
//#define F_AFLAT6
//#define F_A6
//#define F_ASHARP6
//#define F_BFLAT6
//#define F_B6

//#define F_C7        2 * F_C0
//#define F_CSHARP7
//#define F_DFLAT7
//#define F_D7
//#define F_DSHARP7
//#define F_EFLAT7
//#define F_E7
//#define F_F7
//#define F_FSHARP7
//#define F_GFLAT7
//#define F_G7
//#define F_GSHARP7
//#define F_AFLAT7
//#define F_A7
//#define F_ASHARP7
//#define F_BFLAT7
//#define F_B7

float midiToFrequency( int midi );
int frequencyToMidi( float frequency );

#endif // PITCH_H
