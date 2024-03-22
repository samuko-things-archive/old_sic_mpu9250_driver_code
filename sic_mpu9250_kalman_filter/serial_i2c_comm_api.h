#ifndef SERIAL_I2C_COMM_API_H
#define SERIAL_I2C_COMM_API_H
#include <Arduino.h>
#include <Wire.h>
#include "eeprom_setup.h"

void initLed0()
{
  pinMode(A0, OUTPUT);
}
void onLed0()
{
  digitalWrite(A0, HIGH);
}
void offLed0()
{
  digitalWrite(A0, LOW);
}


void initLed1()
{
  pinMode(A1, OUTPUT);
}
void onLed1()
{
  digitalWrite(A1, HIGH);
}
void offLed1()
{
  digitalWrite(A1, LOW);
}



///////// DIFFERENT TASK FOR SERIAL AND I2C COMMUNICATION //////////

/////////////////////////////////////////////////////////////////////////////////////
String sendCalAccData(){
  String data = String(axCal, 6);
  data += ",";
  data += String(ayCal, 6);
  data += ",";
  data += String(azCal, 6);
  return data;
}

String sendCalGyroData(){
  String data = String(gxCal, 6);
  data += ",";
  data += String(gyCal, 6);
  data += ",";
  data += String(gzCal, 6);
  return data;
}

String sendRPY_est()
{
  String data = String(roll_est, 6);
  data += ",";
  data += String(pitch_est, 6);
  data += ",";
  data += String(yaw_est, 6);
  return data;
}

String send_heading()
{
  String data = String(heading_est, 6);
  return data;
}



String sendAngleVariance(){
  String data = String(R_roll, 6);
  data += ",";
  data += String(R_pitch, 6);
  data += ",";
  data += String(R_yaw, 6);
  return data;
}

String sendRateVariance(){
  String data = String(Q_roll, 6);
  data += ",";
  data += String(Q_pitch, 6);
  data += ",";
  data += String(Q_yaw, 6);
  return data;
}

String sendAccVariance(){
  String data = String(accx_variance, 6);
  data += ",";
  data += String(accy_variance, 6);
  data += ",";
  data += String(accz_variance, 6);
  return data;
}

///////////////////////////////////////////////////////////////////////////////////////








///////////////// SERIAL COMMUNICATION //////////////////////
String ser_msg = "";

String serMsg = "", serMsgBuffer, serDataBuffer[2];

void serialReceiveAndSendData()
{
  int indexPos = 0, i = 0;

  if (Serial.available() > 0)
  {
    while (Serial.available())
    {
      serMsg = Serial.readString();
    }
    serMsg.trim();
    if (serMsg != "")
    {
      do
      {
        indexPos = serMsg.indexOf(',');
        if (indexPos != -1)
        {
          serMsgBuffer = serMsg.substring(0, indexPos);
          serMsg = serMsg.substring(indexPos + 1, serMsg.length());
          serDataBuffer[i] = serMsgBuffer;
          serMsgBuffer = "";
        }
        else
        {
          if (serMsg.length() > 0)
            serDataBuffer[i] = serMsg;
        }
        i += 1;
      } while (indexPos >= 0);
    }

    if (serDataBuffer[0] != "")
    {
      onLed1();

      /////////////// FUNCTION CALLS /////////////////////

      if (serDataBuffer[0] == "acc-cal")
      {
        ser_msg = sendCalAccData();
      }
      else if(serDataBuffer[0] == "gyro-cal"){
        ser_msg = sendCalGyroData();
      }
      else if (serDataBuffer[0] == "rpy-est")
      {
        ser_msg = sendRPY_est();
      }
      else if (serDataBuffer[0] == "heading")
      {
        ser_msg = send_heading();
      }



      else if (serDataBuffer[0] == "gyro-var") {
        ser_msg = sendRateVariance();
      }
      else if (serDataBuffer[0] == "acc-var") {
        ser_msg = sendAccVariance();
      }  
      else if (serDataBuffer[0] == "rpy-ang-var") {
        ser_msg = sendAngleVariance();
      }



      Serial.println(ser_msg);
      ser_msg = "";
      offLed1();

      ////////////////////////////////////////////////////
    }
    else
    {
      ser_msg = "0";
      Serial.println(ser_msg);
      ser_msg = "";
    }
  }

  serMsg = "";
  serMsgBuffer = "";
  serDataBuffer[0] = "";
  serDataBuffer[1] = "";
}
//////////////////////////////////////////////////////////////////////////


#endif