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
// jusqua generateur
//const int pathDistances[] = {0,10,500,0,30,180,0,0,50,0,4,0}; 
//const char path[] = "BfVLDVLEFDFE";  
// men generateur lel finish
//const int pathDistances[] = {0,10,0,0,2,40,2,0,40,0,40}; 
//const char path[] = "BCCFRRFDrEs";  

// BESTTT                    B  f  V  L  D  V  L E  C   F D F E C C F R  R  F  D r  E  s
//const int pathDistances[] = {0,25,361,0,25,130,0,0,131,20,0,7,0,0,0,0,14,68,10,0,57,20,50}; 
//const char path[] = "BfVLDVLECFDFECCFRRFDrEs";  

// test
// cercle ratio 1.23
// hghjghjg                 B f    V L D  V   L E  C   F D F E C C F R  R  F  D r  E  s
const int pathDistances[] ={0,25,361,0,25,130,0,0,131,20,0,7,0,0,0,0,14,68,10,0,57,20,50}; 
const char path[] = "BfVLDVLECFDFECCFRRFDrEs";


//  String lezm tabda b B or W !!!!!
//  path turns of 90 degrees si 90 degre safya : mahech T or X : ekteb r el l bech idourha bel pid
// R= RIGHT    ;     L left : B  mode black  ;    W mode WHITE
// F forward tawwalii ;     S stop  ; C other conditions like distance based ones
// EXEMPLE "BRLWLRLRFBCLFCWRRRs"
// ********************************************* IMPORTANT PATH STRING : *************************************************************************

// vars
int pathTimes[sizeof(pathDistances)/sizeof(pathDistances[0])];
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
 int otherconditionsCounter = 0;
char Prevc = 0, mode = 'S', currentLineColor;
long pos = 0, sv = 0;
uint16_t position;
double Taction = 0;
boolean BLOCKMOVEMENT = false;
boolean autoRightAndLeft = true;
int pathSteps = 0;
boolean isPathTimesArrayCorrect = true;
boolean isPathArrayCorrect = true;
boolean stillWaiting = false;
boolean RUNROBOT = false; 
int SetPoint = 3500; // 2000
// colors 
int lineColor = 0;
int nextMoveColor = 0;
