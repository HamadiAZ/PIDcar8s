void calibratesensors()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CHSV(0, 0, 0);
        FastLED.show();
    }
    for (int i = 0; i < (int)NUM_LEDS / 2; i++)
    {
        leds[i] = CHSV(160, 255, 255);
        leds[NUM_LEDS - i - 1] = CHSV(160, 255, 150);
        FastLED.show();
        delay(500);
    }
    leds[2] = CHSV(160, 255, 150);
    FastLED.show();
    delay(400);
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CHSV(0, 0, 0);
        FastLED.show();
    }
    Serial.println("starting calibration");
    int hue = 1;
    for (uint8_t i = 0; i < NUM_LEDS; i++)
    {
        for (uint8_t j = 0; j < 5; j++) // 30 PRESQUE TEMP BECH Y3ML CALIBRATE
        {
            qtr.calibrate();
            delay(10);
        }
        leds[i] = CHSV(100, 255, 190);
        FastLED.show();
    }
    Serial.println("calibration DONE");
    for (uint8_t i = 0; i < SensorCount; i++)
    {
        Serial.print(qtr.calibrationOn.minimum[i]);
        Serial.print(' ');
    }
    Serial.println();

    // print the calibration maximum values measured when emitters were on
    for (uint8_t i = 0; i < SensorCount; i++)
    {
        Serial.print(qtr.calibrationOn.maximum[i]);
        Serial.print(' ');
    }
    Serial.println(" ***********************************************************");
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < NUM_LEDS; i++)
        {
            leds[i] = CHSV(100, 255, 255);
        }
        FastLED.show();
        delay(200);
        for (int i = 0; i < NUM_LEDS; i++)
        {
            leds[i] = CHSV(100, 0, 0);
        }
        FastLED.show();
        delay(200);
    }
}
void calibratE()
{

    Serial.println("starting calibration");
    for (uint8_t i = 0; i < 150; i++)
    {
        qtr.calibrate();
        delay(10);
    }

    Serial.println("calibration DONE");
    // print the calibration minimum values measured when emitters were on
    for (uint8_t i = 0; i < SensorCount; i++)
    {
        Serial.print(qtr.calibrationOn.minimum[i]);
        Serial.print(' ');
    }
    Serial.println();
    // print the calibration maximum values measured when emitters were on
    for (uint8_t i = 0; i < SensorCount; i++)
    {
        Serial.print(qtr.calibrationOn.maximum[i]);
        Serial.print(' ');
    }
    Serial.println(" ***********************************************************");
}
