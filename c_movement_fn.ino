
void stope(int br = 0)
{
    if (br == 0)
    {
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        if (BLOCKMOVEMENT == false);
            //Serial.println("stop without BRAKE");
    }
    else
    {
        digitalWrite(ENA, 1);
        digitalWrite(ENB, 1);
        digitalWrite(IN1, 1);
        digitalWrite(IN2, 1);
        digitalWrite(IN3, 1);
        digitalWrite(IN4, 1);
        if (BLOCKMOVEMENT == false);
            //Serial.println("BRAAAKE !!!");
    }
}

void forward(int r = 120, int l = 120)
{
    if (BLOCKMOVEMENT == true)
    {
        return stope();
    }

    analogWrite(ENA, l);
    analogWrite(ENB, r);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    // Serial.print("forward");
}
void right(int r = 120, int l = 120)
{ // THE SPEED OF FORWARD OF RIGHT THEN LEFT WHEEL
    if (BLOCKMOVEMENT == true)
    {
        stope();
    }
    else
    {
        analogWrite(ENA, l);
        analogWrite(ENB, r);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        // Serial.print("right");
    }
}

void left(int r = 120, int l = 120)
{ // THE SPEED OF FORWARD OF RIGHT THEN LEFT WHEEL
    if (BLOCKMOVEMENT == true)
    {
        stope();
    }
    else
    {
        analogWrite(ENA, l);
        analogWrite(ENB, r);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        // Serial.print(" left ");
    }
}

void back(int R = 110, int L = 110)
{ // BACK SPEED OF RIGHT THEN LEFT WHEEL
    if (BLOCKMOVEMENT == true)
    {
        stope();
    }
    else
    {
        analogWrite(ENA, L);
        analogWrite(ENB, R);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        //Serial.print(" back ");
    }
}
