void setup()
{
    initialCheck();
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(80);
    stope();
    qtr.emittersOff();
    qtr.setTypeAnalog(); // or setTypeAnalog()
    qtr.setSensorPins(analog_pins, SensorCount);

    // PathColorSettings[]={255,255,0,0,0};

    //// *********************************************************
     Serial.begin(9600); //  //// DONT FORGOT TO DISABLE THIS BEFORE STARTING THE ROBOT *********************************************************

    calibratesensors();
     BLOCKMOVEMENT = true;
}
