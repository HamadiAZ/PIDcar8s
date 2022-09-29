
void conditions_manager()
{
    if (otherconditionsCheck())
    {
        myledwhiteon();
        otherconditionsDO();
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
        return false;
    case 1:
        Serial.println(" Condition 2 check ");

        break;

    case 2:
        Serial.println(" Condition 3 check ");

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