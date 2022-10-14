void case_11111()
{ // compare (readings , string elli feha les X lezm tkoun 2eme parameter)
    if (path[pathSteps] == 'F')
    {
        ////Serial.println("FORWARD : PATH F : ");
        myledwhiteon();
        pathSteps++;
        forward();
        Taction = millis();
        delay(100);
    }
    else if (path[pathSteps] == 'R')
    {
        ////Serial.println("90° RIGHT : PATH R : ");
        pathSteps++;
        myledwhiteon();
        right(140, 180);
        delay(150);
        while (1)
        {
            right(100, 120); // ////Serial.println("right");
            updatesensors(currentLineColor);
            if ((IntDsensors[4] == 1) && (IntDsensors[0] == 0))
                break;
        }
        Taction = millis();
    }
    else if (path[pathSteps] == 'L')
    {
        ////Serial.println("90° LEFT : PATH L : ");
        pathSteps++;
        myledwhiteon();
        left(180, 140);
        delay(150);
        while (1)
        {

            left(120, 100); // ////Serial.println("left");
            updatesensors(currentLineColor);
            if ((IntDsensors[6] == 1) && (IntDsensors[0] == 0))
                break;
        }
        Taction = millis();
    }
    else if (path[pathSteps] == 'l')
    {
        ////Serial.print("left 90 safya with pid");
        int t = millis();
        myledwhiteon();
        while ((millis() - t) < 500)
        {
            updatesensors(currentLineColor);
            ELSE();
        }
        pathSteps++;
    }
    else if (path[pathSteps] == 'r')
    {
        ////Serial.print("right 90 safya with pid");
        int t = millis();
        myledwhiteon();
        while ((millis() - t) < 500)
        {
            updatesensors(currentLineColor);
            ELSE();
        }
        pathSteps++;
    }
    else if (path[pathSteps] == 's')
    {
        ////Serial.println("DEAD STOP , PATHSTRING : s DONE");
        stope();
        myledwhiteon();
        delay(100000);
    }
    else
    { // ERREUR DANS PATHSTRING GO FOR PID SAFER
        // Y3NI LGUEE DOURA OR INTERSECTION W MALGUECH 7AJA S7I7A FEL PATHSTRING EXEMPLE 00X11 W YALGA LEFT L
        // pathSteps++;
        ELSE();
        ////Serial.println("SENT TO PID FROM 11111 CONDITION");
        // goto jump; // INAGGEZ L ADD PATH , if needed remove the comment above
    }
    // jump:;
}

void case_110x1_1x011(int tempsInterval)
{ // CHANGEMENT DE mode : point of changing found so stop using the mode variable
    // Taction=millis();
    //  time checking first !
    boolean check = true;
    for (int i = 0; i < 5; i += 2)
    {
        if ((millis() - lastIntDsensorstimes[i]) > tempsInterval)
            check = false;
    }
    ////Serial.print("CHECK = ");
    ////Serial.print(check);
    if (path[pathSteps] == 'V')
    {
        pathSteps++; // BECH INAGGEZ EL "V" w ychof V YDOUR M3AHA  L wale R
        if ((path[pathSteps] == 'L') || (path[pathSteps] == 'l'))
        {
            ////Serial.print("left 45° angle V");
            myledwhiteon();
            while (CountLines() == 2)
            {
                updatesensors(currentLineColor);
                left(120, 40);
            }
            pathSteps++;
        }
        else if ((path[pathSteps] == 'R') || (path[pathSteps] == 'r'))
        {
            ////Serial.print("right 45° angle V");
            myledwhiteon();
            while (CountLines() == 2)
            {
                updatesensors(currentLineColor);
                right(40, 120);
            }
            pathSteps++;
        }
        else
        {
            ELSE();
            ////Serial.print("SENT TO PID FROM CountLines()==2 CONDITION INSIDE compare 110x1 1x011");
        }
    }

    // if ((check==true)&& ((path[pathSteps]=='B')||(path[pathSteps]=='W'))){
    else if (check == true)
    {

        if (mode == 'W')
        {
            Taction = millis();
            Prevc = 'W';
            ////Serial.println("SWITCHED TO WHITE LINE : PATH W: ");
            pathSteps++;
            myledwhiteon();
            mode == 'N';
            currentLineColor = 'W';
        }
        else if (mode == 'B')
        {
            Taction = millis();
            Prevc = 'B';
            ////Serial.println("SWITCHED TO BLACK LINE : PATH W: ");
            pathSteps++;
            myledwhiteon();
            currentLineColor = 'B';
            mode == 'N'; // normal mode ,cad : NO SEARCHING for linecolor switching ,  now Normal line following
        }
        else
        {
            // ERREUR DANS PATHSTRING GO FOR PID SAFER MAYBE
            // or maybe error reading so just follow line with else()
            // enable either A or B mech EZZOUZ

            // pathSteps++;   solution A
            ELSE();

            /* or may we try to correct it automatically here ? if no disable it !! SOLUTION B
              the code will change linefollowing color without looking to the PATHSTRING
              IT MAYBE JUST A FRACTION OF SECOND READING ERROR , so this correction  CAN CAUSE A HUGE PROBLEM*/

            // solution B
            //							if (currentLineColor=='W') Prevc='B';
            //							else Prevc='W';
            //							mode=='N'; // normal mode ,cad : NO SEARCHING for linecolor switching ,  now Normal line following
            // fin solution B
        }
    }
    else
    {
        ELSE();
        ////Serial.print("SENT TO PID FROM 1x0x1 CONDITION");
    }
}

void case_2_lines()
{
    if (path[pathSteps] == 'V')
    {
        pathSteps++; // BECH INAGGEZ EL "V" w ychof V YDOUR M3AHA  L wale R
        if ((path[pathSteps] == 'L') || (path[pathSteps] == 'l'))
        {
            ////Serial.print("left 45° angle V");
            myledwhiteon();
            left(210, 0);
            delay(100);
            while (true)
            {
                updatesensors(currentLineColor);
                left(210, 100);
                if ((IntDsensors[0] == 0) && (IntDsensors[1] == 0)&& (IntDsensors[5] == 1)&& (IntDsensors[7] == 0)) break;
            }
            Taction = millis();
            pathSteps++;
        }
        else if ((path[pathSteps] == 'R') || (path[pathSteps] == 'r'))
        {
            ////Serial.print("right 45° angle V");
            myledwhiteon();
            while (CountLines() == 2)
            {
                updatesensors(currentLineColor);
                right(40, 190);
            }
            Taction = millis();
            pathSteps++;
        }
        else
        {
            ELSE();
            ////Serial.print("SENT TO PID FROM CountLines()==2 CONDITION");
        }
    }
    else
    {
        ELSE();
        ////Serial.print("SENT TO PID FROM CountLines()==2 CONDITION");
    }
}

void case_111x0()
{ //  left or f
    
    if (path[pathSteps] == 'f')
    {
        ////Serial.println("FORWARD : PATH F : ");
        pathSteps++;
        myledwhiteon();
        forward(200,200);
        delay(100);
        Taction = millis();
    }
    else if (path[pathSteps] == 'L')
    {
        ////Serial.println("90° LEFT : PATH L : ");
        pathSteps++;
        myledwhiteon();
        delay(50);
        while (1)
        {

            left(200, 100); // ////Serial.println("left");
            updatesensors(currentLineColor);
            if (IntDsensors[0] == 1)
                break;
        }
        Taction = millis();
    }
    else if (path[pathSteps] == 'l')
    {
        ////Serial.print("left 90 safya with pid");
        int t = millis();
        myledwhiteon();
        while ((millis() - t) < 2000)
        {
            updatesensors(currentLineColor);
            ELSE();
        }
        pathSteps++;
    }
    else
    { // ERREUR DANS PATHSTRING GO FOR PID SAFER
        ELSE();
        //////Serial.print("SENT TO PID FROM 11x00 CONDITION");
    }
}

void case_0x111()
{ //  right or f //
    //////Serial.print("debugging ENTER LOOP  ");
    //////Serial.println(path[pathSteps]);
    if (path[pathSteps] == 'f')
    {
        Taction = millis();
        myledwhiteon();
       // ////Serial.println("FORWARD : PATH F : ");
        pathSteps++;
        forward();
        delay(100);
        Taction = millis();
    }
    else if (path[pathSteps] == 'R')
    {
        //////Serial.println("90° RIGHT : PATH R : ");
        pathSteps++;
        myledwhiteon();
        delay(50);
        while (1)
        {
            right(100, 200); // ////Serial.println("right");
            updatesensors(currentLineColor);
            if (IntDsensors[7] == 1)
                break;
        }
        Taction = millis();
    }
    else
    { // ERREUR DANS PATHSTRING GO FOR PID SAFER
        // pathSteps++; ZA3MA KEN Y8LAT AMA 5IR N5ALLOH IZID PATH WALE LE ???
        ELSE();
        //////Serial.println("SENT TO PID FROM 00x11 CONDITION");
    }
}
