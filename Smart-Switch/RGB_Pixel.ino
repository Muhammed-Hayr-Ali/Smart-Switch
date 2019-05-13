/****************************************************************************************************/

int RGB_PwmRed;
int RGB_PwmGreen;
int RGB_PwmBlue;


int Pixel_PwmRed;
int Pixel_PwmGreen;
int Pixel_PwmBlue;


long RGB_Red;
long RGB_Green;
long RGB_Blue;
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

    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }

    RGB_PwmRed = 0;
    RGB_PwmGreen = 0;
    RGB_PwmBlue = 0;
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



/******************************************************/


BLYNK_WRITE(V16) {
  switch (param.asInt())
  {
    case 1:                                              // الالوان الاساسية //
      Menu = 1;


      Blynk.setProperty(V17, "color", BLYNK_ON); // WHITE    500.1000.500
      Blynk.setProperty(V18, "color", BLYNK_RED);   // RED      1023.0.0
      Blynk.setProperty(V19, "color", BLYNK_GREEN); // GREEN    0.1023.0
      Blynk.setProperty(V20, "color", BLYNK_BLUE);  // BLUE     0.0.1023
      Blynk.setProperty(V17, "label", "WHITE");
      Blynk.setProperty(V18, "label", "RED");
      Blynk.setProperty(V19, "label", "GREEN");
      Blynk.setProperty(V20, "label", "BLUE");
      break;

    case 2:                                               // الالوان المفضلة //
      Menu = 2;


      Blynk.setProperty(V17, "color", BLYNK_ORANGE); // ORANGE   1000.200.0
      Blynk.setProperty(V18, "color", BLYNK_PINK);   // PINK       750.250.750
      Blynk.setProperty(V19, "color", BLYNK_AQUA);   // AQUA     250.1000.1000
      Blynk.setProperty(V20, "color", BLYNK_GRYA);   // GREEN YEALLO   400.1000.0
      Blynk.setProperty(V17, "label", "ORANGE");
      Blynk.setProperty(V18, "label", "PINK");
      Blynk.setProperty(V19, "label", "AQUA");
      Blynk.setProperty(V20, "label", "GREEN YEALLO");
      break;

    case 3:                                               // الالوان الخافته //
      Menu = 3;


      Blynk.setProperty(V17, "color", BLYNK_DARK);      //DARK 250.250.250
      Blynk.setProperty(V18, "color", BLYNK_DARKRED);   // DARK RED 250.0.0.
      Blynk.setProperty(V19, "color", BLYNK_DARKGREEN); // DARK GREEN 0.250.0
      Blynk.setProperty(V20, "color", BLYNK_DARKBLUE);  // DARK BLUE  0.0.250
      Blynk.setProperty(V17, "label", "DARK");
      Blynk.setProperty(V18, "label", "DARK RED");
      Blynk.setProperty(V19, "label", "DARK GREEN");
      Blynk.setProperty(V20, "label", "DARK BLUE");
      break;


  }
}





BLYNK_WRITE(V17)
{
  if ( param.asInt() && Menu == 1 )               // الالوان الاساسية //
  {
    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }
    delay (100);
    // WHITE    500.1000.500
    for (int i = 0; i <= 1000; i++) {
      analogWrite(Red, i / 2);
      analogWrite(Green, i);
      analogWrite(Blue, i / 2);
      delay(2);
    }
    RGB_PwmRed = 500;
    RGB_PwmGreen = 1000;
    RGB_PwmBlue = 500;
  }
  else if ( param.asInt()   && Menu == 2 )         // الالوان المفضلة //
  {
    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }
    delay (100);
    // ORANGE   1000.200.0
    for (int i = 0; i <= 1000; i++) {
      analogWrite(Red, i);
      analogWrite(Green, i / 5);
      delay(2);
    }
    RGB_PwmRed = 1000;
    RGB_PwmGreen = 200;
    RGB_PwmBlue = 0;
  }
  else if ( param.asInt()   && Menu == 3 )        // الالوان الخافته //
  {
    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }
    delay (100);
    //DARK 250.250.250
    for (int i = 0; i <= 250; i++) {
      analogWrite(Red, i);
      analogWrite(Green, i);
      analogWrite(Blue, i);
      delay(2);
    }
    RGB_PwmRed = 250;
    RGB_PwmGreen = 250;
    RGB_PwmBlue = 250;
  }
}





BLYNK_WRITE(V18)
{
  if ( param.asInt() && Menu == 1 )               // الالوان الاساسية //
  {
    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }
    delay (100);
    // RED      1023.0.0
    for (int i = 0; i <= 1023; i++) {
      analogWrite(Red, i);
      delay(2);
    }
    RGB_PwmRed = 1023;
    RGB_PwmGreen = 0;
    RGB_PwmBlue = 0;
  }
  else if ( param.asInt()   && Menu == 2 )         // الالوان المفضلة //
  {
    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }
    delay (100);
    // PINK       750.250.750
    for (int i = 0; i <= 750; i++) {
      analogWrite(Red, i);
      analogWrite(Green, i / 3);
      analogWrite(Blue, i);
      delay(2);
    }
    RGB_PwmRed = 750;
    RGB_PwmGreen = 250;
    RGB_PwmBlue = 750;
  }
  else if ( param.asInt()   && Menu == 3 )        // الالوان الخافته //
  {
    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }
    delay (100);
    // DARK RED 250.0.0.
    for (int i = 0; i <= 250; i++) {
      analogWrite(Red, i);
      delay(2);
    }
    RGB_PwmRed = 250;
    RGB_PwmGreen = 0;
    RGB_PwmBlue = 0;
  }
}


BLYNK_WRITE(V19)
{
  if ( param.asInt() && Menu == 1 )               // الالوان الاساسية //
  {
    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }
    delay (100);
    // GREEN    0.1023.0
    for (int i = 0; i <= 1023; i++) {
      analogWrite(Green, i);
      delay(2);
    }
    RGB_PwmRed = 0;
    RGB_PwmGreen = 1023;
    RGB_PwmBlue = 0;
  }
  else if ( param.asInt()   && Menu == 2 )         // الالوان المفضلة //
  {
    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }
    delay (100);
    // AQUA     250.1000.1000
    for (int i = 0; i <= 1000; i++) {
      analogWrite(Red, i / 4);
      analogWrite(Green, i);
      analogWrite(Blue, i);
      delay(2);
    }
    RGB_PwmRed = 250;
    RGB_PwmGreen = 1000;
    RGB_PwmBlue = 1000;
  }
  else if ( param.asInt()   && Menu == 3 )        // الالوان الخافته //
  {
    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }
    delay (100);
    // DARK GREEN 0.250.0
    for (int i = 0; i <= 250; i++) {
      analogWrite(Green, i);
      delay(2);
    }
    RGB_PwmRed = 0;
    RGB_PwmGreen = 250;
    RGB_PwmBlue = 0;
  }
}


BLYNK_WRITE(V20)
{
  if ( param.asInt() && Menu == 1 )               // الالوان الاساسية //
  {
    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }
    delay (100);
    // BLUE     0.0.1023
    for (int i = 0; i <= 1023; i++) {
      analogWrite(Blue, i);
      delay(2);
    }
    RGB_PwmRed = 0;
    RGB_PwmGreen = 0;
    RGB_PwmBlue = 1023;
  }
  else if ( param.asInt()   && Menu == 2 )         // الالوان المفضلة //
  {
    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }
    delay (100);
    // GREEN YEALLO   400.1000.0
    for (int i = 0; i <= 1000; i++) {
      analogWrite(Red, i / 2.5);
      analogWrite(Green, i);
      delay(2);
    }
    RGB_PwmRed = 400;
    RGB_PwmGreen = 1000;
    RGB_PwmBlue = 0;
  }
  else if ( param.asInt()   && Menu == 3 )        // الالوان الخافته //
  {
    while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
      RGB_PwmRed--;
      RGB_PwmGreen--;
      RGB_PwmBlue--;
      analogWrite(Red, RGB_PwmRed);
      analogWrite(Green, RGB_PwmGreen);
      analogWrite(Blue, RGB_PwmBlue);
      delay(1);
    }
    delay (100);
    // DARK BLUE  0.0.250
    for (int i = 0; i <= 250; i++) {
      analogWrite(Blue, i);
      delay(2);
    }
    RGB_PwmRed = 0;
    RGB_PwmGreen = 0;
    RGB_PwmBlue = 250;
  }
}


/*************************** لون عشوائي **********************************/


// Random Colors ON OFF
BLYNK_WRITE(V21)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    RandomColors = true;
  } else {
    RandomColors = false;
  }
}


// SLIDER
BLYNK_WRITE(V22)
{
  Timer_Random_Colors = param.asInt();
  int t = param.asInt() * 10;
  if (t <= 60) {
    Blynk.setProperty (V22, "label", String(t) + " Second");
  } else   if (t >= 60) {
    Blynk.setProperty (V22, "label", String(t/60) + " min");
  }
}



void Random_Colors() {
  // RGB OFF
  while ( RGB_PwmRed > 0 || RGB_PwmGreen > 0 || RGB_PwmBlue > 0) {
    RGB_PwmRed--;
    RGB_PwmGreen--;
    RGB_PwmBlue--;
    analogWrite(Red, RGB_PwmRed);
    analogWrite(Green, RGB_PwmGreen);
    analogWrite(Blue, RGB_PwmBlue);
    delay(1);
  }

  // Random Colors
  RGB_Red = random(1024);   //or  random(0, 1024); 0~1023
  RGB_Green = random(1024);
  RGB_Blue = random(1024);


  //RED
  for (int i = 0; i <= RGB_Red; i++) {
    analogWrite(Red, i);
    delay(2);
  }
  //GREEN
  for (int i = 0; i <= RGB_Green; i++) {
    analogWrite(Green, i);
    delay(2);
  }
  //BLUE
  for (int i = 0; i <= RGB_Blue; i++) {
    analogWrite(Blue, i);
    delay(2);
  }

  RGB_PwmRed = RGB_Red;
  RGB_PwmGreen = RGB_Green;
  RGB_PwmBlue = RGB_Blue;
}











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
