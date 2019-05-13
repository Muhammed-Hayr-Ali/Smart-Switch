/****************************************************************************************************/


void LocalWeather()
{
  int LDRValue = map(analogRead(A0), 0, 1023, 0, 10);
  float localhumidity = dht.readHumidity();
  float localtemperature = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(localhumidity) || isnan(localtemperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(LDR, LDRValue);
  Blynk.virtualWrite(LocalHumidity, localhumidity);
  Blynk.virtualWrite(LocalTemperature, localtemperature);
  //  Serial.println("Read Local Weather");

  if ( RandomColors == true) {
    Cont_Random_Colors++;
    if (Cont_Random_Colors >= Timer_Random_Colors) {
      Cont_Random_Colors = 0;
      Random_Colors();
    }

  }

}


/****************************************************************************************************/
