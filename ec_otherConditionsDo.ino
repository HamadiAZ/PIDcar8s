

void otherconditionsDO()
{
  switch (otherconditionsCounter)
  {
    case 0:
      Serial.println(" Condition 1 found ");
      SetPoint = 5000;
      myledwhiteon();
      for (int i = 0; i < 3; i++) {
        Kp = 0.05;
        Kd = 0.14;
        while (1) {
          pidfollow(false);
          updatesensors(currentLineColor);
          if (CountLines() > 1)break;
          }
        Kp = 0.02;
        Kd = 0.10;
        while (1) {
          pidfollow(false);
          updatesensors(currentLineColor, WhichLineToFollow::LEFT);
          if (CountLines() <= 1)break;
          }
      }
      myledwhiteon();
      SetPoint = 3000;
      for (int i = 0; i < 3; i++) {
        Kp = 0.05;
        Kd = 0.14;
        while (1) {
          pidfollow(false);
          updatesensors(currentLineColor);
          if (CountLines() > 1)break;
          }
        Kp = 0.02;
        Kd = 0.10;
        while (1) {
          pidfollow(false);
          updatesensors(currentLineColor);
          if (CountLines() <= 1)break;
          }
      }
     myledwhiteon();
      Kp = 0.05;
      Kd = 0.14;
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
