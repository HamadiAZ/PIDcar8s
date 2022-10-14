

void otherconditionsDO()
{
  switch (otherconditionsCounter)
  {
    case 0:
      Serial.println(" Condition 1 found ");
      SetPoint = 4500;
      while (1){
        pidfollow(false);
        updatesensors(currentLineColor);
        if (countLines() > 1))break;
      }
      
      while (1){
        pidfollow(false);
        updatesensors(currentLineColor,WhichLineToFollow::LEFT);
        if (countLines() <=1))break;
      }
      otherconditionsCounter++;
      break;
    case 1:
      Serial.println(" Condition 2 found ");

      otherconditionsCounter++;
      break;

    case 2:
      Serial.println(" Condition 3 found ");

      otherconditionsCounter++;
      break;

    case 3:
      Serial.println(" Condition 4 found ");

      otherconditionsCounter++;
      break;

    // ADD CASES IF U HAVE MORE
    default:
      Serial.println("Error! NOMBER OF C IN PATHSTRING IS MORE THAN THE CONDITIONS IN otherconditionsDO FUNCTION");
  }
  otherconditionsCounter += 1;
  return 0;
}
