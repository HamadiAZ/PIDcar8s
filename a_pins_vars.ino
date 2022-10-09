#include <Ultrasonic.h>
#include <QTRSensors.h>
#include <FastLED.h>

const PROGMEM uint8_t IN1 = 7; // left
const PROGMEM uint8_t ENA = 6; // left
const PROGMEM uint8_t IN2 = 5; // left

const PROGMEM uint8_t IN3 = 4; // right
const PROGMEM uint8_t ENB = 3; // right
const PROGMEM uint8_t IN4 = 2; // right

// Ultrasonic ultrasonicR(31, 30); // trig echo
// Ultrasonic ultrasonicF(A7, A6); // trig echo
// Ultrasonic ultrasonicL(A5, A4); // trig echo

const PROGMEM uint8_t LED_PIN = 12;
const PROGMEM uint8_t NUM_LEDS = 8;

const uint8_t SensorCount = 8;
static uint8_t PathColorSettings[] = {0, 0, 0, 0, 0, 0, 0, 0}; // fill it with number of sensors
static int lastIntDsensors[] = {0, 0, 0, 0, 0, 0, 0, 0};       // fill it with number of sensors
static const uint8_t analog_pins[] = {A7, A6, A5, A4, A3, A2, A1, A0};

// ********************************************* IMPORTANT PATH STRING : *************************************************************************
const int defaultTime = 300;
const int pathDistances[] = {0, 30, 50, 20}; // start with 0,distance en cm
const char path[] = "BRLs";                  // stope with s
// const char path[] ="BRWBRrs"; // stope with s
//  String lezm tabda b B or W !!!!!
//  path turns of 90 degrees si 90 degre safya : mahech T or X : ekteb r el l bech idourha bel pid
// R= RIGHT    ;     L left : B  mode black  ;    W mode WHITE
// F forward tawwalii ;     S stop  ; C other conditions like distance based ones
// EXEMPLE "BRLWLRLRFBCLFCWRRRs"
// ********************************************* IMPORTANT PATH STRING : *************************************************************************

// vars
int pathTimes[sizeof(pathDistances)];
int distanceL, distanceR, distanceF;
int prev_i = 0, prev_error = 0;
QTRSensors qtr;
CRGB leds[NUM_LEDS];
uint8_t hue = 0;
long ledactiontime = 0;

uint16_t sensors[SensorCount];
char Dsensors[SensorCount]; // Dsensors : W B , IntDsensors 1 line 0 background que ce soit B or W mode
static int IntDsensors[SensorCount];

double lastIntDsensorstimes[SensorCount];
uint8_t otherconditionsCounter = 0;
char Prevc = 0, mode = 'S', currentLineColor;
long pos = 0, sv = 0;
uint16_t position;
int Taction = 0;
boolean BLOCKMOVEMENT = false;
int pathSteps = 0;
boolean isPathTimesArrayCorrect = true;
boolean isPathArrayCorrect = true;
boolean stillWaiting = false;

// colors
int lineColor = 0;
int nextMoveColor = 0;
