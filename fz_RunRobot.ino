
void Run_Robot(char C = 'A')
{ // C color : A AUTO COLOR FROM String path B black W white
    RUNROBOT = true;
    // be carefull , if COLOR GIVEN , IT WILL BE IGNORED FROM THE PATH READINGS!!!!!
    // if AUTO A IS given , lezm Tabta l path b COLOR !!
    int tempsInterval = 200; // TEMPS DE DIFFERENCE ENTRE CHANGEMENT DE VALEURS DE CAPTEURS , utilise dans changement de mode
    int r;
    int delayBetweenEachAction = 200;
    if (pathSteps != 0 && isPathTimesArrayCorrect == true)
        delayBetweenEachAction = pathTimes[pathSteps];
    if (C == 'A')
        autoColorChooser();
    else
    {
        if (pathSteps == 0 && (path[0] == 'W' || path[0] == 'B') && C != 'W' && C != 'B')
        {
            updatesensors(path[0], WhichLineToFollow::AUTO, autoRightAndLeft);
            pathSteps++;
            Taction = millis();
        }
        else
            updatesensors(C, WhichLineToFollow::AUTO, autoRightAndLeft);
    }

    // capteurs couleur , capteur distance
    if (millis() - Taction > delayBetweenEachAction)
    {
        if (path[pathSteps] == 'D')
        {
            autoRightAndLeft = false;
            pathSteps++;
            myledwhiteon();
            Taction=millis();
        }
        else if (path[pathSteps] == 'E')
        {
            autoRightAndLeft = true;
            pathSteps++;
            myledwhiteon();
            Taction=millis();
        }
        else if (path[pathSteps] == 'C')
        {
            conditions_manager();
        }
        /*5 POSIBILITIES The Robo Will encounter
        x 1 1 1 1 1 1 x    =>  START: F OR "CROSS + " or " T " SUIVANT la String path ye3ref
              => possible : F , R , L , S : STOP
        1 1 1 1 x x 0 0    =>  -|  intersection left turn OR F
        0 0 x x 1 1 1 1    =>  |-  intersection right turn OR F
        0 0 0 0 0 0 0 0    =>  OUT OF THE LINE : STOP  S or
        1 1 x 0 0 x 1 1  => changement de mode
        ELSE  == The Robo is on the line,
        */
        else if (compare(IntDsensors, "x111111x") || compare(IntDsensors, "xx111111") || compare(IntDsensors, "111111xx"))
            case_11111();
        else if (compare(IntDsensors, "111xxx00") || compare(IntDsensors, "xx111100") || compare(IntDsensors, "x1111x00"))
            case_111x0();
        else if (compare(IntDsensors, "00xx1111"))
            case_0x111();
//        else if (compare(IntDsensors, "11xx0x11") || compare(IntDsensors, "11x0xx11"))
//            case_110x1_1x011(tempsInterval);
        else if (compare(IntDsensors, "1x0x1x00") || compare(IntDsensors, "10xx1x00"))
            case_2_lines();
        else
            ELSE(); // pid follow
    }
    else
    { // pid follow // else oof millis-Taction<Tempdifferenceminimum
        ELSE();
        Serial.println(" TIME RESTRICTION ,PID WORKING");
    }
    // THIS ONE Serial.print("path(searching for:) :");Serial.print(path[pathSteps]);Serial.print(" step: ");Serial.print(pathSteps);Serial.print(" ");
}
