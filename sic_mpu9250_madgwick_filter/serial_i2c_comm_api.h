#ifndef SERIAL_I2C_COMM_API_H
#define SERIAL_I2C_COMM_API_H
#include <Arduino.h>
#include <Wire.h>
#include "eeprom_setup.h"




////////////////////////////////////////////////
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


// void initLed1()
// {
//   pinMode(A1, OUTPUT);
// }
// void onLed1()
// {
//   digitalWrite(A1, HIGH);
// }
// void offLed1()
// {
//   digitalWrite(A1, LOW);
// }
////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
String updateFilterGain(float gain){
  setFilterGain(gain);
  return "1";
}
String sendFilterGain(){
  return String(filterGain, 3);
}

String sendMode(){
  String data = String(mode);
  return data;
}

String updateI2CADDRESS(int address){
  setI2CADDRESS(address);               
  return "1";
}
String sendI2CADDRESS(){
  return String(i2cAddress);
}

/////////////////////////////////////////////////////////




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

String sendRPY()
{
  String data = String(roll, 6);
  data += ",";
  data += String(pitch, 6);
  data += ",";
  data += String(yaw, 6);
  return data;
}

String sendQuat()
{
  String data = String(qw, 6);
  data += ",";
  data += String(qx, 6);
  data += ",";
  data += String(qy, 6);
  data += ",";
  data += String(qz, 6);
  return data;
}

String sendAngleVariance(){
  String data = String(roll_variance, 6);
  data += ",";
  data += String(pitch_variance, 6);
  data += ",";
  data += String(yaw_variance, 6);
  return data;
}

String sendRateVariance(){
  String data = String(roll_rate_variance, 6);
  data += ",";
  data += String(pitch_rate_variance, 6);
  data += ",";
  data += String(yaw_rate_variance, 6);
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



///////////////////////////////////////////////////////////////////
String updateRollAngleVariance(float rollAngleVariance){
  setRollAngleVariance(rollAngleVariance);
  return "1";
}
String updatePitchAngleVariance(float pitchAngleVariance){
  setPitchAngleVariance(pitchAngleVariance);
  return "1";
}
String updateYawAngleVariance(float yawAngleVariance){
  setYawAngleVariance(yawAngleVariance);
  return "1";
}
//////////////////////////////////////////////////////////////////






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
      offLed0();

      /////////////// FUNCTION CALLS /////////////////////

      if (serDataBuffer[0] == "acc-cal")
      {
        ser_msg = sendCalAccData();
      }
      else if(serDataBuffer[0] == "gyro-cal"){
        ser_msg = sendCalGyroData();
      }
      else if (serDataBuffer[0] == "rpy")
      {
        ser_msg = sendRPY();
      }
      else if (serDataBuffer[0] == "quat")
      {
        ser_msg = sendQuat();
      }


      else if (serDataBuffer[0] == "gyro-var") {
        ser_msg = sendRateVariance();
      }

      else if (serDataBuffer[0] == "acc-var") {
        ser_msg = sendAccVariance();
      }


      else if (serDataBuffer[0] == "rpy-var") {
        ser_msg = sendAngleVariance();
      }
      else if (serDataBuffer[0] == "r-var") {
        ser_msg = updateRollAngleVariance(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "p-var") {
        ser_msg = updatePitchAngleVariance(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "y-var") {
        ser_msg = updateYawAngleVariance(serDataBuffer[1].toFloat());
      }


      else if (serDataBuffer[0] == "mode"){
        ser_msg = sendMode();
      }
      else if (serDataBuffer[0] == "gain") {
        if (serDataBuffer[1]=="") ser_msg = sendFilterGain();
        else ser_msg = updateFilterGain(serDataBuffer[1].toFloat());
        Serial.println(ser_msg);
        ser_msg = "";
      }
      else if (serDataBuffer[0] == "i2c") {
        if (serDataBuffer[1]=="") ser_msg = sendI2CADDRESS();
        else ser_msg = updateI2CADDRESS(constrain(serDataBuffer[1].toInt(), 0, 127));
        Serial.println(ser_msg);
        ser_msg = "";
      }


      Serial.println(ser_msg);
      ser_msg = "";
      onLed0();

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







//////////////////////// I2C COMMUNICATION ////////////////////////////////////

String i2c_msg = "";

String i2cMsg = "", i2cMsgBuffer, i2cDataBuffer[5];

void i2cSlaveSendData()
{
  String msg = "";
  if (i2c_msg != "")
  {
    msg = i2c_msg;
    i2c_msg = "";
  }
  else
  {
    msg = "0";
    i2c_msg = "";
  }
  char charArray[msg.length() + 1];
  msg.toCharArray(charArray, msg.length() + 1);
  Wire.write(charArray, msg.length());
}

void i2cSlaveReceiveData(int dataSizeInBytes)
{
  offLed0();

  int indexPos = 0, i = 0;

  for (int i = 0; i < dataSizeInBytes; i += 1)
  {
    char c = Wire.read();
    i2cMsg += c;
  }

  i2cMsg.trim();

  if (i2cMsg != "")
  {
    do
    {
      indexPos = i2cMsg.indexOf(',');
      if (indexPos != -1)
      {
        i2cMsgBuffer = i2cMsg.substring(0, indexPos);
        i2cMsg = i2cMsg.substring(indexPos + 1, i2cMsg.length());
        i2cDataBuffer[i] = i2cMsgBuffer;
        i2cMsgBuffer = "";
      }
      else
      {
        if (i2cMsg.length() > 0)
          i2cDataBuffer[i] = i2cMsg;
      }
      i += 1;
    } while (indexPos >= 0);
  }

  if (i2cDataBuffer[0] == "rpy")
  {
    i2c_msg = sendRPY();
  }

  else if (i2cDataBuffer[0] == "quat")
  {
    i2c_msg = sendRPY();
  }

  else if (i2cDataBuffer[0] == "rpy-rate")
  {
    i2c_msg = sendCalGyroData();
  }

  else if (i2cDataBuffer[0] == "acc-cal")
  {
    i2c_msg = sendCalAccData();
  }

  i2cMsg = "";
  i2cMsgBuffer = "";
  i2cDataBuffer[0] = "";
  i2cDataBuffer[1] = "";
  i2cDataBuffer[2] = "";
  i2cDataBuffer[3] = "";
  i2cDataBuffer[4] = "";

  onLed0();
}

/////////////////////////////////////////////////////////


#endif