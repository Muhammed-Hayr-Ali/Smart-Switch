
/****************************************************************************************************/

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WidgetRTC.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include <IRsend.h>
#include <Adafruit_NeoPixel.h>
#include <ShiftRegister74HC595.h>
#include <TridentTD_OpenWeather.h>


/****************************************************************************************************/

char auth[] = "b78640da387740e78ec8b14e7290999f";
char ssid[] = "Sec";     //"Pro-Syrian.com";
char pass[] = "sec121212";     //"99119911";



/****************************************************************************************************/


#define OpenWeather_APIKEY    "7a258c185497229c92b88f009e5922e8"
#define lat       37.0484
#define lon       37.3437
#define timezone  +3
TridentTD_OpenWeather myPlace(OpenWeather_APIKEY);



/****************************************************************************************************/


#define PIN           15
#define NUMPIXELS      4
Adafruit_NeoPixel pixel = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/****************************************************************************************************/


#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
WidgetRTC rtc;
BlynkTimer timer;


/****************************************************************************************************/


IRsend irsend(16);


/****************************************************************************************************/


ShiftRegister74HC595 sr (2, 5, 0, 4);


/****************************************************************************************************/
int Menu;

const int Red = 12;               // Red
const int Green = 13;             // Green
const int Blue = 14;              // Blue

int Timer_Random_Colors;
int Cont_Random_Colors = 0;
boolean RandomColors = false;
/****************************************************************************************************/

//Widget Colors -------------------
#define BLYNK_ON          "#A1A1A1"
#define BLYNK_BALCK       "#000000"
#define BLYNK_RED         "#FF0000"
#define BLYNK_GREEN       "#00FF00"
#define BLYNK_BLUE        "#0000FF"

#define BLYNK_ORANGE      "#F93100"
#define BLYNK_PINK        "#BA3EBA"
#define BLYNK_AQUA        "#3EF9F9"
#define BLYNK_GRYA        "#63F900"

#define BLYNK_DARK        "#343232"
#define BLYNK_DARKRED     "#a40000"
#define BLYNK_DARKGREEN   "#00a400"
#define BLYNK_DARKBLUE    "#0000a4"



#define Weather             V1
#define Temperature         V2
#define Humidity            V3
#define Pressure            V4
#define WindSpeed           V5


#define LDR                 V6
#define LocalHumidity       V7
#define LocalTemperature    V8

#define ze_RGB              V10
#define Slider_Red_RGB      V11
#define Slider_Green_RGB    V12
#define Slider_Blue_RGB     V13
#define LED_OFF             V14
#define brightness_RGB      V15


#define ze_Pixel            V30
#define Slider_Red_Pixel    V31
#define Slider_Green_Pixel  V32
#define Slider_Blue_Pixel   V33
#define Pixel_OFF           V34
#define brightness_Pixel    V35


#define Remote              V50
#define Volume              V51
#define Channel             V52







#define Re_All    V55
#define Ic_All    V56


#define Relay0     V60
#define Relay1     V61
#define Relay2     V62
#define Relay3     V63
#define Relay4     V64
#define Relay5     V65
#define Relay6     V66
#define Relay7     V67
#define Relay8     V68
#define Relay9     V69


#define Icon0     V70
#define Icon1     V71
#define Icon2     V72
#define Icon3     V73
#define Icon4     V74
#define Icon5     V75
#define Icon6     V76
#define Icon7     V77
#define Icon8     V78
#define Icon9     V79









/****************************************************************************************************/




void setup()
{
  Serial.begin(115200);

  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);


  WiFi.begin(ssid, pass);
  Serial.println("connecting");

  do {
    delay(500);
    Serial.print(".");
  } while (WiFi.status() != WL_CONNECTED);


  Serial.println("\nWiFi is Connected");
  printWiFiStatus();

  myPlace.setLocation( lat, lon );
  myPlace.setUnit("metric");          //"metric""imperial"

  Blynk.config(auth);
  printBlynkStatus();



}




/****************************************************************************************************/




void loop()
{
  Blynk.run();
  timer.run();

}



/****************************************************************************************************/



//print Wifi status
void printWiFiStatus() {
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}



/****************************************************************************************************/


// print Blynk status
void printBlynkStatus() {
  bool result = Blynk.connect();
  if (result != true) {
    Serial.println("Failed To Connect BLYNK Server");
  } else {
    Serial.println("BLYNK Is Connected");

    dht.begin();
    rtc.begin();
    irsend.begin();                                  // IR BEGIN
    pixel.begin();                              // PIXEL BEGIN
    pixel.setBrightness(25);                    // SET PIXEL TO OFF
    pixel.show();

    ServerWeather();

    timer.setInterval(10000L,   LocalWeather);      // 10 second
    timer.setInterval(300000L, ServerWeather);      // 5  minute

    Blynk.virtualWrite(V16, 1);
    Blynk.virtualWrite(V21, 0);
    Blynk.virtualWrite(V22, 0);
    Blynk.syncVirtual(V16, V60, V61, V62, V63, V64, V65, V66, V67, V68, V69);


  }
}


/****************************************************************************************************/
