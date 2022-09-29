
void Run_Robot(char C = 'A')
{ // C color : A AUTO COLOR FROM String path B black W white
    // be carefull , if COLOR GIVEN , IT WILL BE IGNORED FROM THE PATH READINGS!!!!!
    // if AUTO A IS given , lezm Tabta l path b COLOR !!
    int tempsInterval = 200; // TEMPS DE DIFFERENCE ENTRE CHANGEMENT DE VALEURS DE CAPTEURS , utilise dans changement de mode
    int r;
    int delayBetweenEachAction = 200;
    if (pathSteps != 0 && isPathTimesArrayCorrect == true)
        delayBetweenEachAction = pathTimes[pathSteps - 1];
    if (C == 'A')
        autoColorChooser();
    else
        updatesensors(C);

    if (path[pathSteps] == 'C')
    {
        conditions_manager();
    } // capteurs couleur , capteur distance
    else if (millis() - Taction > delayBetweenEachAction)
    {
        /*5 POSIBILITIES The Robo Will encounter
        1 1 1 1 1     =>  START: F OR "CROSS + " or " T " SUIVANT la String path ye3ref
              => possible : F , R , L , S : STOP
        1 1 x 0 0    =>  -| T intersection left turn OR F
        0 0 x 1 1    =>  |- T intersection right turn OR F
        0 0 0 0 0    =>  OUT OF THE LINE : STOP  S or
        1 x 0 x 1    => changement de mode
        ELSE  == The Robo is on the line,
        */
        if (compare(IntDsensors, "111xx") || compare(IntDsensors, "xx111"))
            case_111xx_xx111();
        /*
        else if(compare(IntDsensors,"111x0")) case_111x0();
        else if(compare(IntDsensors,"0x111")) case_0x111();
        */
        else if (compare(IntDsensors, "110x1") || compare(IntDsensors, "1x011"))
            case_110x1_1x011(tempsInterval);
        else if (CountLines() == 2)
            case_2_lines();
        else
        {           // pid follow
            ELSE(); // THIS ONE Serial.print(" ELSE PID WORKING ");
        }
    }
    else
    { // pid follow // else oof millis-Taction<Tempdifferenceminimum
        ELSE();
        Serial.println(" HE DIDNT READ A PATH STRRING DUE TO TIME RESTRICTION , PID WORKING ");
    }
    // THIS ONE Serial.print("path(searching for:) :");Serial.print(path[pathSteps]);Serial.print(" step: ");Serial.print(pathSteps);Serial.print(" ");
}
