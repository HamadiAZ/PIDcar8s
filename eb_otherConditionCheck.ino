
void conditions_manager()
{
    if (otherconditionsCheck())
    {
        myledwhiteon();
        otherconditionsDO();
        Taction = millis();
        otherconditionsCounter++;
        pathSteps++;
    }
    else
        ELSE();
}
boolean otherconditionsCheck()
{

    switch (otherconditionsCounter)
    {
    case 0:
        // Serial.println(" Condition 1 check ");
        // if(Rdistance<100){return true;} example
        return true;
    case 1:
        Serial.println(" Condition 2 check ");
        return true;
//        if (compare(IntDsensors, "x111111x") || compare(IntDsensors, "xx111111") || compare(IntDsensors, "111111xx")) return true;
//        else return false;
        break;

    case 2:
        Serial.println(" Condition 3 check ");
        return true;
        break;

    case 3:
        Serial.println(" Condition 4 check ");

        break;

    // ADD CASES IF U HAVE MORE
    default:
        Serial.println("Error! NOMBER OF C IN PATHSTRING IS MORE THAN THE CONDITIONS IN otherconditionsCheck FUNCTION");
        return true; // to continue following and does get stuck
    }
    return false; // if anything missing in the conditions bech lcode may7bsch
}
