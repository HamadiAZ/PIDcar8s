/* void wallfollow(int offset = 14, char wall = 'R', boolean autoTurn = true) // offset : distance to the wall
{
    int derivative = 0;
    int Tp = 150;
    int Kp2 = 6;
    int Kd2 = 30;
    // Kp2 = 6; CCV //Kd2 = 30; BBEST
    // Kp2 = 8; CCV //Kd2 = 30;
    int error = 0, lasterror, Turn, powerR, powerL;
    int r, l;
    distanceF = ultrasonicF.read();
    distanceL = ultrasonicL.read(); // Serial.print("distance left : "); Serial.println(distanceL);Serial.println("*************");
    distanceR = ultrasonicR.read(); // Serial.print("distance right : "); Serial.println(distanceR);Serial.println("*******************************************");
    // distanceL=10;
    int enteringLoopTime;
    if (distanceR <= 3) // KI YOD5LL F 7IT IMIN MEL 50° JSUQA 30°// CBN
    {
        enteringLoopTime = millis();
        while (1) // idour ISAR jusqa YARJA3 PARALLEL LEL 7IT LIMIN
        {
            distanceR = ultrasonicR.read();
            Serial.print("distance right : ");
            Serial.println(distanceR);
            Serial.println("*******************************************");
            delay(10);
            back(70, 170);
            if (distanceR >= 5 || millis() - enteringLoopTime > 1000)
            {
                break;
            };
        }
        delay(10);
        right(80, 80); // bech y7abes eddoran bel inertie
        delay(40);     // bech y7abes eddoran bel inertie
        stope();       // bech y7abes
    }
    else if (distanceL <= 3) // KI YOD5L F 7IT lisar // CBN
    {

        delay(10);
        back(170, 70);
        delay(250);
        left(80, 80); // bech y7abes eddoran bel inertie
        delay(40);    // bech y7abes eddoran bel inertie
        stope();      // bech y7abes
    }
    else if ((distanceF < 3) && (wall == 'R'))
    {
        enteringLoopTime = millis();
        while (1) // idour ISAR jusqa YARJA3 PARALLEL LEL 7IT LIMIN
        {
            distanceF = ultrasonicF.read();
            Serial.println(distanceF);
            delay(10);
            back(50, 190);
            if (distanceF >= 10 || millis() - enteringLoopTime > 1000)
            {
                forward(200, 80);
                delay(200);
                break;
            };
        }
    }
    else if ((distanceF < 3) && (wall == 'L'))
    {
        enteringLoopTime = millis();
        while (1) // idour imin jusqa YARJA3 PARALLEL LEL 7IT lisar
        {
            distanceF = ultrasonicF.read();
            Serial.println(distanceF);
            delay(10);
            back(190, 50);
            if (distanceF >= 10 || millis() - enteringLoopTime > 1000)
            {
                forward(80, 200);
                delay(200);
                break;
            };
        }
    }
    else
    { // PID FOLLOW
        if (wall == 'R')
        { // right wall follow
            error = distanceR - offset;
            int localKd2;
            if (abs(error) > 40)
                localKd2 = 300;
            else
                localKd2 = Kd2;

            if ((abs(error) < offset * 1.2) && (distanceF < 20) && (distanceL > 50) && (autoTurn == true))
            {
                enteringLoopTime = millis();
                while (1) // idour ISAR jusqa YARJA3 PARALLEL LEL 7IT LIMIN
                {
                    distanceF = ultrasonicF.read();
                    Serial.print("distance right : ");
                    Serial.println(distanceR);
                    Serial.println("*******************************************");
                    delay(10);
                    left(150, 70);
                    if (distanceF >= 80 || millis() - enteringLoopTime > 1000)
                    {
                        break;
                    };
                }
                delay(30);
                right(80, 80); // bech y7abes eddoran bel inertie
                delay(40);     // bech y7abes eddoran bel inertie
                stope();       // bech y7abes
            }
            derivative = error - lasterror;
            Turn = Kp2 * error + Kd2 * derivative;
            r = Tp - Turn;
            l = Tp + Turn;
            r = constrain(r, 0, 255);
            l = constrain(l, 0, 220);
            // r = map(r, -160, 160, 40, 130);  // 40 OUTMIN ET 110 OUT MAX
            // l = map(l, -2*Tp, 2*Tp, 0 , 170); //BESTTTT + KP 12 0 0
            // l = map(l, -255, 255, 0 , 140);
            lasterror = error;
        }
        else
        { // left wall follow
            Serial.println("IM HERE");
            error = distanceL - offset;
            int localKd2;
            if (abs(error) > 40)
                localKd2 = 300;
            else
                localKd2 = Kd2;
            if ((abs(error) < offset * 1) && (distanceF < 25) && (distanceR > 50) && autoTurn == true)
            {
                enteringLoopTime = millis();
                while (1) // idour ISAR jusqa YARJA3 PARALLEL LEL 7IT LIMIN
                {
                    distanceF = ultrasonicF.read();
                    Serial.print("distance right : ");
                    Serial.println(distanceR);
                    Serial.println("*******************************************");
                    delay(10);
                    right(70, 150);
                    if (distanceF >= 80 || millis() - enteringLoopTime > 1000)
                    {
                        break;
                    };
                }
                delay(30);
                left(80, 80); // bech y7abes eddoran bel inertie
                delay(40);    // bech y7abes eddoran bel inertie
                stope();      // bech y7abes
            }
            derivative = error - lasterror;
            Turn = Kp2 * error + Kd2 * derivative;
            r = Tp + Turn;
            l = Tp - Turn;
            l = constrain(l, 0, 255);
            r = constrain(r, 0, 190);
            // r = map(r, -160, 160, 40, 130);  // 40 OUTMIN ET 110 OUT MAX
            // l = map(l, -2*Tp, 2*Tp, 0 , 170); //BESTTTT + KP 12 0 0
            // l = map(l, -255, 255, 0 , 140);
            lasterror = error;
        }

        forward(r, l);
        Serial.print("wall PID SPEEDS R,L ");
        Serial.print(r);
        Serial.print(" , ");
        Serial.println(l);
        // lel integrale
    }
} */