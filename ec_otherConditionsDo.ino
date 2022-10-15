

void otherconditionsDO()
{
  // Serial.println("otherconditionsDO working !!!!!!!!!!!!!!");
  int a=1;
  if (otherconditionsCounter == 0)
  {
    stope();
    delay(5000);
  }
  else if (otherconditionsCounter == a)
  {
    // delay 230
    for (int i = 3500; i < 5501; i+=100) {
      SetPoint = i;
      int t = millis();
      while (1) {
        pidfollow(false);
        updatesensors(currentLineColor);
        if (CountLines() >= 2 || millis() - t > 6)
          break;
      }
      if (CountLines() >= 2 ) break;
    }
    SetPoint = 5500;

    int t = millis();
    while (true) {
      pidfollow(false);
      updatesensors(currentLineColor);
      if (CountLines() == 2 || millis() - t > 4000)
        break;
    }
    myledwhiteon();
    t = millis();
    while (true) {
      forward(200, 100);
      updatesensors(currentLineColor);
      if (CountLines() == 1 || millis() - t > 500)
        break;
    }
    t = millis();
    while (true) {
      pidfollow(false);
      updatesensors(currentLineColor);
      if (CountLines() == 2 || millis() - t > 2000)
        break;
    }
    myledwhiteon();
    t = millis();
    while (true) {
      forward(200, 100);
      updatesensors(currentLineColor);
      if (CountLines() == 1 || millis() - t > 500)
        break;
    }
    t = millis();
    while (true) {
      pidfollow(false);
      updatesensors(currentLineColor);
      if (CountLines() == 2 || millis() - t > 2000)
        break;
    }
    myledwhiteon();
    t = millis();
    while (true) {
      forward(200, 100);
      updatesensors(currentLineColor);
      if (CountLines() == 1 || millis() - t > 500)
        break;
    }
    SetPoint = 3500;
    Kp = 0.05;
    Kd = 0.14;
  }
  else if (otherconditionsCounter == (a+1)) {
    SetPoint = 2100;
    Kp = 0.03;
    Kd = 0.14;
    int t = millis();
    boolean lastWasCountOneLine = true;
    int COUNTER = 0;
    int timer = millis();
    while (1) {
      pidfollow(false);
      updatesensors(currentLineColor, WhichLineToFollow::LEFT);
      if (CountLines() == 2 && lastWasCountOneLine == true && millis() - timer > 100) {
        COUNTER++;
        lastWasCountOneLine = false;
        timer = millis();
      }
      if (CountLines() == 1) lastWasCountOneLine = true;
      if (COUNTER >= 3) {
        timer = millis();
        while (1) {
          pidfollow(false);
          updatesensors(currentLineColor, WhichLineToFollow::LEFT);
          if (millis() - timer > 200) break;
        }
        SetPoint = 3500;
        Kp = 0.05;
        Kd = 0.14;
        return;
      }
      if ((compare(IntDsensors, "x111111x") || compare(IntDsensors, "xx111111") || compare(IntDsensors, "111111xx")) && millis() - t > 2200) {
        pathSteps++;
        SetPoint = 3500;
        Kp = 0.05;
        Kd = 0.14;
        return ;
      }
    }
  }
  else   if (otherconditionsCounter == 3)
  {
  }
  else   if (otherconditionsCounter == 4)
  {
  }
  else Serial.println("Error! NOMBER OF C IN PATHSTRING IS MORE THAN THE CONDITIONS IN otherconditionsDO FUNCTION");

}
