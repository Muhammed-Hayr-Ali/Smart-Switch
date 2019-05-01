/****************************************************************************************************/

int RGB_PwmRed;
int RGB_PwmGreen;
int RGB_PwmBlue;


int Pixel_PwmRed;
int Pixel_PwmGreen;
int Pixel_PwmBlue;


/****************************************************************************************************/



// zeRGBa assigned
BLYNK_WRITE(ze_RGB)
{
  int r = param[0].asInt();
  int g = param[1].asInt();
  int b = param[2].asInt();
  analogWrite(Red, r);
  analogWrite(Green, g);
  analogWrite(Blue, b);
  RGB_PwmRed = r;
  RGB_PwmGreen = g;
  RGB_PwmBlue = b;
}





/****************************************************************************************************/


// Slider brightness Red
BLYNK_WRITE(Slider_Red_RGB)
{
  int pinValue = param.asInt();
  analogWrite(Red, pinValue);
  RGB_PwmRed = pinValue;
}


// Slider brightness Green
BLYNK_WRITE(Slider_Green_RGB)
{
  int pinValue = param.asInt();
  analogWrite(Green, pinValue);
  RGB_PwmGreen = pinValue;
}


// Slider brightness Blue
BLYNK_WRITE(Slider_Blue_RGB)
{
  int pinValue = param.asInt();
  analogWrite(Blue, pinValue);
  RGB_PwmBlue = pinValue;
}




/****************************************************************************************************/



// LED OFF
BLYNK_WRITE(LED_OFF)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {

    for (int i = RGB_PwmRed; i >= 0; i--) {
      analogWrite(Red, i);
      delay(2);
    }
    for (int i = RGB_PwmGreen; i >= 0; i--) {
      analogWrite(Green, i);
      delay(2);
    }
    for (int i = RGB_PwmBlue; i >= 0; i--) {
      analogWrite(Blue, i);
      delay(2);
    }
    RGB_PwmRed = 0;
    RGB_PwmGreen = 0;
    RGB_PwmBlue = 0;
    Serial.println("RGB OFF");
  } else {
    //break
  }
}



/****************************************************************************************************/


// Slider brightness
BLYNK_WRITE(brightness_RGB)
{
  int pinValue = param.asInt();
  analogWrite(Red, RGB_PwmRed - pinValue);
  analogWrite(Green, RGB_PwmGreen - pinValue);
  analogWrite(Blue, RGB_PwmBlue - pinValue);
}









/****************************************************************************************************/

/*****************    Pixel   ***********************/

// zeRGBa assigned
BLYNK_WRITE(ze_Pixel)
{
  int R = param[0].asInt();
  int G = param[1].asInt();
  int B = param[2].asInt();

  for (int i = 0; i < NUMPIXELS; i++) {
    pixel.setPixelColor(i, pixel.Color(R, G, B));
    pixel.show();
    Pixel_PwmRed = R;
    Pixel_PwmGreen = G;
    Pixel_PwmBlue = B;
  }
}

// Slider brightness Red
BLYNK_WRITE(Slider_Red_Pixel)
{
  int R = param.asInt();
  for (int i = 0; i < NUMPIXELS; i++) {
    pixel.setPixelColor(i, pixel.Color(R, Pixel_PwmGreen, Pixel_PwmBlue));
    pixel.show();
    Pixel_PwmRed = R;
  }
}
// Slider brightness Green
BLYNK_WRITE(Slider_Green_Pixel)
{
  int G = param.asInt();
  for (int i = 0; i < NUMPIXELS; i++) {
    pixel.setPixelColor(i, pixel.Color(Pixel_PwmRed, G, Pixel_PwmBlue));
    pixel.show();
    Pixel_PwmGreen = G;
  }
}
// Slider brightness Blue
BLYNK_WRITE(Slider_Blue_Pixel)
{
  int B = param.asInt();
  for (int i = 0; i < NUMPIXELS; i++) {
    pixel.setPixelColor(i, pixel.Color(Pixel_PwmRed, Pixel_PwmGreen, B));
    pixel.show();
    Pixel_PwmBlue = B;
  }
}

BLYNK_WRITE(Pixel_OFF)                //pixel off
{
  int pinValue = param.asInt();
  if (pinValue = 1) {
    pixel.setBrightness(0);
    pixel.show();
    Pixel_PwmRed = 0;
    Pixel_PwmGreen = 0;
    Pixel_PwmBlue = 0;
  }
}


BLYNK_WRITE(brightness_Pixel)                 //pixel Brightness
{
  int pinValue = param.asInt();
  pixel.setBrightness(pinValue);
  pixel.show();
  Pixel_PwmRed = pinValue;
  Pixel_PwmGreen = pinValue;
  Pixel_PwmBlue = pinValue;
}
