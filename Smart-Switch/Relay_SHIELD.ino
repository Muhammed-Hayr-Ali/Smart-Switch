BLYNK_WRITE(Re_All)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    sr.setAllHigh();
      Blynk.virtualWrite(Ic_All, 1);

  }
  else if (pinValue == 0) {
    sr.setAllLow();
      Blynk.virtualWrite(Ic_All, 2);

  }
}




BLYNK_WRITE(Relay0)
{
    if ( param.asInt() == 1 ) {
      sr.set(0, HIGH);
        Blynk.virtualWrite(Icon0, 1);

    }  else {
      sr.set(0, LOW);
        Blynk.virtualWrite(Icon0, 2);

    }

  }





BLYNK_WRITE(Relay1)
{
    if ( param.asInt() == 1 ) {
      sr.set(1, HIGH);
        Blynk.virtualWrite(Icon1, 1);

    }  else {
      sr.set(1, LOW);
        Blynk.virtualWrite(Icon1, 2);

    }

  }





BLYNK_WRITE(Relay2)
{
    if ( param.asInt() == 1 ) {
      sr.set(2, HIGH);
        Blynk.virtualWrite(Icon2, 1);

    }  else {
      sr.set(2, LOW);
        Blynk.virtualWrite(Icon2, 2);

    }

  }





BLYNK_WRITE(Relay3)
{
    if ( param.asInt() == 1 ) {
      sr.set(3, HIGH);
        Blynk.virtualWrite(Icon3, 1);

    }  else {
      sr.set(3, LOW);
        Blynk.virtualWrite(Icon3, 2);

    }

  }





BLYNK_WRITE(Relay4)
{
    if ( param.asInt() == 1 ) {
      sr.set(4, HIGH);
        Blynk.virtualWrite(Icon4, 1);

    }  else {
      sr.set(4, LOW);
        Blynk.virtualWrite(Icon4, 2);

    }

  }





BLYNK_WRITE(Relay5)
{
    if ( param.asInt() == 1 ) {
      sr.set(8, HIGH);
        Blynk.virtualWrite(Icon5, 1);

    }  else {
      sr.set(8, LOW);
        Blynk.virtualWrite(Icon5, 2);

    }

  }





BLYNK_WRITE(Relay6)
{
    if ( param.asInt() == 1 ) {
      sr.set(9, HIGH);
        Blynk.virtualWrite(Icon6, 1);

    }  else {
      sr.set(9, LOW);
        Blynk.virtualWrite(Icon6, 2);

    }

  }





BLYNK_WRITE(Relay7)
{
    if ( param.asInt() == 1 ) {
      sr.set(10, HIGH);
        Blynk.virtualWrite(Icon7, 1);

    }  else {
      sr.set(10, LOW);
        Blynk.virtualWrite(Icon7, 2);

    }

  }





BLYNK_WRITE(Relay8)
{
    if ( param.asInt() == 1 ) {
      sr.set(11, HIGH);
        Blynk.virtualWrite(Icon8, 1);

    }  else {
      sr.set(11, LOW);
        Blynk.virtualWrite(Icon8, 2);

    }

  }





BLYNK_WRITE(Relay9)
{
    if ( param.asInt() == 1 ) {
      sr.set(12, HIGH);
        Blynk.virtualWrite(Icon9, 1);

    }  else {
      sr.set(12, LOW);
        Blynk.virtualWrite(Icon9, 2);

    }

  }
