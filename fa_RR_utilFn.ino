void autoColorChooser()
{ // mode partie black et partie white bel map ye3rf
    if (pathSteps == 0)
    {
        char c = path[pathSteps++]; // Serial.println(pathSteps);
        if (isPathArrayCorrect == false)
            c = 'B';
        Serial.print("PATH[0] LINE COLOR INITIALISED : ");
        Serial.println(c);
        Prevc = c;
        updatesensors(Prevc);
        for (int i = 0; i < SensorCount; i++)
        {
            lastIntDsensors[i] = IntDsensors[i];
        }
    }
    else if (path[pathSteps] == 'B')
    {
        if (Prevc == 'W')
        {
            updatesensors('W'); // TW Y3ML UPDATE BEL W AMA MODE B Y3NI YSTANA FI CIONDITION BECH YBADDEL LEL LINE BLACK
            mode = 'B';         // mode S start ; W switch from BtoW LINE; B WtoB ;
        }
    }
    else if (path[pathSteps] == 'W')
    {
        if (Prevc == 'B')
        {
            updatesensors('B');
            mode = 'W'; // mode S start ; W switch from BtoW LINE; B WtoB ;
        }
    }
    else
    {
        updatesensors(Prevc); // Serial.println(" debugging 1 ");
        mode = 'N';           // ANYTHING EXCEPT FOR B AND W
    }
    // ========================================== affichage du path dans les led ============================================
    // next move : ( following the line until the robot find it )
    // right : red in the top right led , left inverse ..
    // forward : middle red led
    // change color : top right and top left red led
    // STOP : ALL RED
    // PathColorSettings contain colors AS number from :
    // https://camo.githubusercontent.com/2f40c83acc6756da11aed2a7109bade069a48e032f16db23e4fd282aca865c37/68747470733a2f2f7261772e6769746875622e636f6d2f466173744c45442f466173744c45442f67682d70616765732f696d616765732f4853562d7261696e626f772d776974682d646573632e6a7067
    // EXCEPT FOR RED DONT MAKE 0 : MAKE 1 !!
    // 0 = no color !!

    if ((path[pathSteps] == 'R') || (path[pathSteps] == 'r'))
    {
        PathColorSettings[NUM_LEDS - 1] = 255;
        for (int i = 0; i < NUM_LEDS - 1; i++)
        {
            PathColorSettings[i] = 0;
        }
    }
    else if ((path[pathSteps] == 'L') || (path[pathSteps] == 'l'))
    {
        PathColorSettings[0] = 255;
        for (int i = 1; i < NUM_LEDS; i++)
        {
            PathColorSettings[i] = 0;
        }
    }
    else if (path[pathSteps] == 'F')
    {
        for (int i = 0; i < NUM_LEDS; i++)
        {
            PathColorSettings[i] = 0;
        }
        PathColorSettings[2] = 255; // 5 led : 2 wastanya
                                    // PathColorSettings[3]=255; // 8 led : 3 ET 4 MIDDLE
                                    // PathColorSettings[4]=255; // 8 led : 3 ET 4 MIDDLE
    }
    // else if((path[pathSteps]=='W')||(path[pathSteps]=='B'))
    else if ((mode == 'W') || (mode == 'B')) // TEST THIS
    {
        PathColorSettings[0] = 255;
        PathColorSettings[NUM_LEDS - 1] = 255;
        for (int i = 1; i < NUM_LEDS - 1; i++)
        {
            PathColorSettings[i] = 0;
        }
    }
    else if (path[pathSteps] == 's')
    {
        for (int i = 0; i < NUM_LEDS; i++)
        {
            PathColorSettings[i] = 255;
        }
    }
    // ========================================== fin affichage dans les led ====================================================
}

void ELSE()
{
    pidfollow(0); // 0 to disable internal readsensors fn of PID cuz we already updated in Run_Robot
}