

int icon;


void ServerWeather() {


  myPlace.weatherNow();
  /*
    Serial.println("[OpenWeather] Temperature: " + String(myPlace.readTemperature()));  // [metric] Celcius  or [imperial] Fahrenheit
    Serial.println("[OpenWeather] Humidity   : " + String(myPlace.readHumidity()));     // %
    Serial.println("[OpenWeather] Pressure   : " + String(myPlace.readPressure()));     // hPa
    Serial.println("[OpenWeather] Weather    : " + myPlace.readWeather());
    Serial.println("[OpenWeather] Icons      : " + myPlace.readIcons());
    Serial.println("[OpenWeather] Country    : " + myPlace.readCountry());
    Serial.println("[OpenWeather] City       : " + myPlace.readCity());
    Serial.println("[OpenWeather] Wind Speed : " + String(myPlace.readWindSpeed()));    // [metric] meter/sec  or [imperial] miles/hour
    Serial.println("[OpenWeather] Sunrise    : " + String(myPlace.readSunrise(timezone)));
    Serial.println("[OpenWeather] Sunset     : " + String(myPlace.readSunset(timezone)));
    Serial.println("[OpenWeather] Wind Speed : " + String(myPlace.readWindSpeed()));    // [metric] meter/sec  or [imperial] miles/hour
  */



  if (String("01d") == myPlace.readIcons()) {
    icon = 1;
  }
  else if (String("01n") == myPlace.readIcons()) {
    icon = 2;
  }



  else if (String("02d") == myPlace.readIcons()) {
    icon = 3;
  }
  else if (String("02n") == myPlace.readIcons()) {
    icon = 4;
  }



  else if (String("03d") == myPlace.readIcons()) {
    icon = 5;
  }
  else if (String("03n") == myPlace.readIcons()) {
    icon = 6;
  }




  else if (String("04d") == myPlace.readIcons()) {
    icon = 7;
  }

  else if (String("04n") == myPlace.readIcons()) {
    icon = 7;
  }



  else if (String("09d") == myPlace.readIcons()) {
    icon = 8;
  }

  else if (String("09n") == myPlace.readIcons()) {
    icon = 8;
  }


  else if (String("10d") == myPlace.readIcons()) {
    icon = 9;
  }


  else if (String("10n") == myPlace.readIcons()) {
    icon = 10;
  }


  else if (String("11d") == myPlace.readIcons()) {
    icon = 11;
  }

  else if (String("11n")  == myPlace.readIcons()) {
    icon = 11;
  }


  else if (String("13d") == myPlace.readIcons()) {
    icon = 12;
  }

  else if (String("13n") == myPlace.readIcons()) {
    icon = 12;
  }


  else if (String("50d") == myPlace.readIcons()) {
    icon = 13;
  }
  else if (String("50n") == myPlace.readIcons()) {
    icon = 13;
  }

  //  Serial.println("Read Server Weather");
  Blynk.setProperty (Weather, "label", myPlace.readWeather());
  Blynk.virtualWrite(Weather, icon);
  Blynk.virtualWrite(Temperature, myPlace.readTemperature());
  Blynk.virtualWrite(Humidity, myPlace.readHumidity());
  Blynk.virtualWrite(Pressure, myPlace.readPressure());
  Blynk.virtualWrite(WindSpeed, myPlace.readWindSpeed());
}
