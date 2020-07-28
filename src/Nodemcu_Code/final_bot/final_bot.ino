#include <MPU9250.h>
#include <ESP8266WebServer.h>
#include <string.h>
#include <math.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
MPU9250 IMU;
ESP8266WebServer server(80);
//int i=0,j=0,k=0,l=0,m=0,n=0;
 float angle=0.00;
double t;
int16_t gyro[3] = {0, 0, 0};
int16_t acc[3] = {0, 0, 0};
float gyroBias[3]  = {0, 0, 0};
float accelBias[3] = {0, 0, 0};
int dt;
long Time;
float a;
int X;
int Y;
float O;
int S=-1;
double x = 0.0, y = 0.0;
double cosine , sine;
double offset;
int xf[1]={400};
int yf[1]={400};
float of[1]={90};
float oi;
const float rad =57.2958; 
const int inputPin1  = D7;//n4    
const int inputPin2  = D6;//n3
const int inputPin3  = D5;//n2   
const int inputPin4  = D4;//n1
const int inputPin5  = D3; //left  
const int inputPin6  = D8;//right
const char *ssid = "LAPTOP-2QO9LQOJ 0442"; /////////////////////////// NAME OF WIFI
const char *password = "12345678"; /////////////////// WIFI PASSWORD
String payload;
String dir;
void handleSpecificArg() 
{
 payload = "";

if (server.arg("direction")== "")
{     //Parameter not found

payload = ""; }

else
{     //Parameter found

payload = "direction = ";
dir = server.arg("direction");
payload += dir;     //Gets the value of the query parameter
// Serial2.print(dir); //Write the serial data
    delay(1000);

}
Serial.println(payload);

server.send(200, "text/plain", payload);          //Returns the HTTP response

}
void backward()
{
  digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2,HIGH);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,HIGH);
    analogWrite(inputPin5,330);
    analogWrite(inputPin6,320); 
    Serial.println("backward");
}
void forward()
{
 digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2,LOW);
    digitalWrite(inputPin3,HIGH);
    digitalWrite(inputPin4,LOW);
    analogWrite(inputPin5,350);
    analogWrite(inputPin6,350);
     Serial.println("forward");
}
void right(float q)
{
  int i=0;
  while(i==0){
    data();
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2,HIGH);
    digitalWrite(inputPin3,HIGH);
    digitalWrite(inputPin4,LOW);
    analogWrite(inputPin5,320);
    analogWrite(inputPin6,320);  
    Serial.println("right");
    float r = get_gyro();
    Serial.println(r);
    if(get_gyro()<q)
    {
      pause();
     // data();
      i=1;
    }
  }
}
int k = 0;
void left(float p)
{
 
  while (k == 0) {
    data();
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, HIGH);
    analogWrite(inputPin5, 350);
    analogWrite(inputPin6, 350);
    Serial.println("left");
    float r = get_gyro();
    Serial.println(r);
    if (get_gyro() > p)
    {
      pause();
      Serial.println("pause");
      //data();
      k = 1;
    }
  }
}
void pause()
{
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2,LOW);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,LOW);
    analogWrite(inputPin5,0);
    analogWrite(inputPin6,0); 
     Serial.println("pause"); 
}
float get_gyro()
{
  IMU.readGyroData(gyro);
  dt = micros() - Time;
  angle = angle + (gyro[2] - a) * dt / 131.0 / 1000000.0;
  Time = micros();
  //  IMU.readAccelData(acc);

  //Serial.println(offset);
  return angle;

}
void setup () {
  Serial.begin(9600);
 for (int i = 0; i < 1000; i++) {
    IMU.readGyroData(gyro);
    //    gyroBias[2] += gyro[2];
    a += gyro[2];
  }
  a = a / 1000;
  //  gyroBias[2] = gyroBias[2]/1000;
  Time = micros();
    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT); 
    pinMode(inputPin5,OUTPUT );
    pinMode(inputPin6, OUTPUT);
    analogWrite(inputPin5,0 );
    analogWrite(inputPin6,0);

  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.println("Connecting..");
 
  }
  Serial.println("Connected to WiFi Network");
 Serial.print("Connected");
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

///////////////////////////////////////////////////////////

server.on("/specificArgs", handleSpecificArg);
server.begin();

Serial.println("HTTP server started");
}


void data()
{
  int e=0;
server.handleClient();
int a=payload.indexOf("O");
int b=payload.indexOf("A");
int c=payload.indexOf("B");
int d=payload.indexOf("C");
 e=payload.indexOf("D");
 //Serial.println(e);
if(e>0)
{
  //Serial.println(1);
String subo=payload.substring(a+1,b);
String subx=payload.substring(b+1,c);
String suby=payload.substring(c+1,d);
String subs=payload.substring(d+1,e);
 X=subx.toInt();
 Y=suby.toInt();
 O=subo.toFloat();//current angle from x axis
 S=subs.toInt();
/*Serial.println(X);
Serial.println(Y);
Serial.println(O);
Serial.println(S);*/
int xd=xf[S]-X;
int yd=yf[S]-Y;
if(xd>0&&yd>0)
oi=atan(yd/xd)*rad;
if(xd<0&&yd>0)
oi=180+(atan(xd/yd)*rad);
if(xd<0&&yd<0)
oi=180+(atan(xd/yd)*rad);
if(xd>0&&yd<0)
oi=360-(atan(xd/yd)*rad);  
if(xd==0)
{
  if(yd>0)
    oi=90;
  else
  oi=270;
}
if(yd==0){
  if(xd>0)
  oi=0;
  else
  oi=180;
}
}
}
int g=0,h=1,p=-10;
void loop() {
 data();
 Serial.println(oi);
 if(p!=S)
 {
 if(S>-1)
 {
float angledi=-oi;
if(angledi>0)
 left(angledi);
else{
 right(angledi);
}
  while(h>0)
  { 
    data();
if(X>xf[S]+80||X<xf[S]-80||Y>yf[S]+80||Y<yf[S]-80)
//if(Y>yf[S]+80)
{
  forward();
}
else
{
pause();
h=-1;
}
/*for(int w=0;w<3;w++)
{
  backward();
}*/
}
float angledf=-of[S];
if(angledf>0)
 left(angledf);
if(angledf<0)
 right(angledf);
p=S; 
}
 }
 else{
  data();
  h=1;
  g=0;
 }
}
