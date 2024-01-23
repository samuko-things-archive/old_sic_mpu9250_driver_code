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

//////////////////////////////////////////////////////////////////////
String resetEEPROM(){
  setFIRST_TIME(0);
  return "1";
}
////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////

String sendRawAccData(){
  String data = String(axRaw, 6);
  data += ",";
  data += String(ayRaw, 6);
  data += ",";
  data += String(azRaw, 6);
  return data;
}

String sendCalAccData(){
  String data = String(axCal, 6);
  data += ",";
  data += String(ayCal, 6);
  data += ",";
  data += String(azCal, 6);
  return data;
}


String sendOffAccData(){
  String data = String(axOff, 6);
  data += ",";
  data += String(ayOff, 6);
  data += ",";
  data += String(azOff, 6);
  return data;
}


String sendRawGyroData(){
  String data = String(gxRaw, 6);
  data += ",";
  data += String(gyRaw, 6);
  data += ",";
  data += String(gzRaw, 6);
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

String sendOffGyroData(){
  String data = String(gxOff, 6);
  data += ",";
  data += String(gyOff, 6);
  data += ",";
  data += String(gzOff, 6);
  return data;
}


String sendRawMagData(){
  String data = String(mxRaw, 6);
  data += ",";
  data += String(myRaw, 6);
  data += ",";
  data += String(mzRaw, 6);
  return data;
}

String sendCalMagData(){
  String data = String(mxCal, 6);
  data += ",";
  data += String(myCal, 6);
  data += ",";
  data += String(mzCal, 6);
  return data;
}

String sendBvectMagData(){
  String data = String(b_vect[0], 6);
  data += ",";
  data += String(b_vect[1], 6);
  data += ",";
  data += String(b_vect[2], 6);
  return data;
}

String sendAmatR0MagData(){
  String data = String(A_mat[0][0], 6);
  data += ",";
  data += String(A_mat[0][1], 6);
  data += ",";
  data += String(A_mat[0][2], 6);
  return data;
}

String sendAmatR1MagData(){
  String data = String(A_mat[1][0], 6);
  data += ",";
  data += String(A_mat[1][1], 6);
  data += ",";
  data += String(A_mat[1][2], 6);
  return data;
}

String sendAmatR2MagData(){
  String data = String(A_mat[2][0], 6);
  data += ",";
  data += String(A_mat[2][1], 6);
  data += ",";
  data += String(A_mat[2][2], 6);
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

String sendRPY_rad(){
  String data = String(roll, 6);
  data += ",";
  data += String(pitch, 6);
  data += ",";
  data += String(yaw, 6);
  return data;
}

String sendRPY_rate(){
  String data = String(roll_rate, 6);
  data += ",";
  data += String(pitch_rate, 6);
  data += ",";
  data += String(yaw_rate, 6);
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
///////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
String updateAxOffset(float axOffset){
  setAxOffset(axOffset);
  return "1";
}
String updateAyOffset(float ayOffset){
  setAyOffset(ayOffset);
  return "1";
}
String updateAzOffset(float azOffset){
  setAzOffset(azOffset);
  return "1";
}
////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
String updateGxOffset(float gxOffset){
  setGxOffset(gxOffset);
  return "1";
}
String updateGyOffset(float gyOffset){
  setGyOffset(gyOffset);
  return "1";
}
String updateGzOffset(float gzOffset){
  setGzOffset(gzOffset);
  return "1";
}
////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
String updateBvectX(float bvectX){
  setBvectX(bvectX);
  return "1";
}
String updateBvectY(float bvectY){
  setBvectY(bvectY);
  return "1";
}
String updateBvectZ(float bvectZ){
  setBvectZ(bvectZ);
  return "1";
}
////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
String updateAmat00(float amat00){
  setAmat00(amat00);
  return "1";
}
String updateAmat01(float amat01){
  setAmat01(amat01);
  return "1";
}
String updateAmat02(float amat02){
  setAmat02(amat02);
  return "1";
}


String updateAmat10(float amat10){
  setAmat10(amat10);
  return "1";
}
String updateAmat11(float amat11){
  setAmat11(amat11);
  return "1";
}
String updateAmat12(float amat12){
  setAmat12(amat12);
  return "1";
}


String updateAmat20(float amat20){
  setAmat20(amat20);
  return "1";
}
String updateAmat21(float amat21){
  setAmat21(amat21);
  return "1";
}
String updateAmat22(float amat22){
  setAmat22(amat22);
  return "1";
}
///////////////////////////////////////////////////////////////////



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



///////////////////////////////////////////////////////////////////
String updateRollRateVariance(float rollRateVariance){
  setRollRateVariance(rollRateVariance);
  return "1";
}
String updatePitchRateVariance(float pitchRateVariance){
  setPitchRateVariance(pitchRateVariance);
  return "1";
}
String updateYawRateVariance(float yawRateVariance){
  setYawRateVariance(yawRateVariance);
  Q_yaw = getYawRateVariance();
  return "1";
}
//////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////
String updateAccxVariance(float accxVariance){
  setAccxVariance(accxVariance);
  return "1";
}
String updateAccyVariance(float accyVariance){
  setAccyVariance(accyVariance);
  return "1";
}
String updateAcczVariance(float acczVariance){
  setAcczVariance(acczVariance);
  return "1";
}
////////////////////////////////////////////////////////////////////










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

      if (serDataBuffer[0] == "acc-raw")
      {
        ser_msg = sendRawAccData();
      }
      else if (serDataBuffer[0] == "acc-cal")
      {
        ser_msg = sendCalAccData();
      }
      else if (serDataBuffer[0] == "acc-off") {
        ser_msg = sendOffAccData();
      }


      else if (serDataBuffer[0] == "ax-off") {
        ser_msg = updateAxOffset(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "ay-off") {
        ser_msg = updateAyOffset(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "az-off") {
        ser_msg = updateAzOffset(serDataBuffer[1].toFloat());
      }


      else if (serDataBuffer[0] == "gyro-raw")
      {
        ser_msg = sendRawGyroData();
      }
      else if (serDataBuffer[0] == "gyro-cal")
      {
        ser_msg = sendCalGyroData();
      }
      else if (serDataBuffer[0] == "gyro-off") {
        ser_msg = sendOffGyroData();
      }


      else if (serDataBuffer[0] == "gx-off") {
        ser_msg = updateGxOffset(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "gy-off") {
        ser_msg = updateGyOffset(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "gz-off") {
        ser_msg = updateGzOffset(serDataBuffer[1].toFloat());
      }


      else if (serDataBuffer[0] == "mag-raw")
      {
        ser_msg = sendRawMagData();
      }
      else if (serDataBuffer[0] == "mag-cal")
      {
        ser_msg = sendCalMagData();
      }
      else if (serDataBuffer[0] == "bvect") {
        ser_msg = sendBvectMagData();
      }
      else if (serDataBuffer[0] == "amat0") {
        ser_msg = sendAmatR0MagData();
      }
      else if (serDataBuffer[0] == "amat1") {
        ser_msg = sendAmatR1MagData();
      }
      else if (serDataBuffer[0] == "amat2") {
        ser_msg = sendAmatR2MagData();
      }



      else if (serDataBuffer[0] == "bvect-x") {
        ser_msg = updateBvectX(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "bvect-y") {
        ser_msg = updateBvectY(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "bvect-z") {
        ser_msg = updateBvectZ(serDataBuffer[1].toFloat());
      }


      else if (serDataBuffer[0] == "amat-00") {
        ser_msg = updateAmat00(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "amat-01") {
        ser_msg = updateAmat01(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "amat-02") {
        ser_msg = updateAmat02(serDataBuffer[1].toFloat());
      }


      else if (serDataBuffer[0] == "amat-10") {
        ser_msg = updateAmat10(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "amat-11") {
        ser_msg = updateAmat11(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "amat-12") {
        ser_msg = updateAmat12(serDataBuffer[1].toFloat());
      }


      else if (serDataBuffer[0] == "amat-20") {
        ser_msg = updateAmat20(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "amat-21") {
        ser_msg = updateAmat21(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "amat-22") {
        ser_msg = updateAmat22(serDataBuffer[1].toFloat());
      }


      else if (serDataBuffer[0] == "rpy-ang-var") {
        ser_msg = sendAngleVariance();
      }


      else if (serDataBuffer[0] == "r-ang-var") {
        ser_msg = updateRollAngleVariance(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "p-ang-var") {
        ser_msg = updatePitchAngleVariance(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "y-ang-var") {
        ser_msg = updateYawAngleVariance(serDataBuffer[1].toFloat());
      }


      else if (serDataBuffer[0] == "rpy-rate-var") {
        ser_msg = sendRateVariance();
      }


      else if (serDataBuffer[0] == "r-rate-var") {
        ser_msg = updateRollRateVariance(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "p-rate-var") {
        ser_msg = updatePitchRateVariance(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "y-rate-var") {
        ser_msg = updateYawRateVariance(serDataBuffer[1].toFloat());
      }


      else if (serDataBuffer[0] == "acc-var") {
        ser_msg = sendAccVariance();
      }


      else if (serDataBuffer[0] == "accx-var") {
        ser_msg = updateAccxVariance(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "accy-var") {
        ser_msg = updateAccyVariance(serDataBuffer[1].toFloat());
      }
      else if (serDataBuffer[0] == "accz-var") {
        ser_msg = updateAcczVariance(serDataBuffer[1].toFloat());
      }


      else if(serDataBuffer[0] == "rpy-rad"){
        ser_msg = sendRPY_rad();
      }
      else if(serDataBuffer[0] == "rpy-rate"){
        ser_msg = sendRPY_rate();
      }
      else if (serDataBuffer[0] == "rpy-est")
      {
        ser_msg = sendRPY_est();
      }
      else if (serDataBuffer[0] == "heading")
      {
        ser_msg = send_heading();
      }


      else if (serDataBuffer[0] == "reset") {
        ser_msg = resetEEPROM();
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















/////////////// I2C COMMUNICATION /////////////////

String i2c_msg = "";

String i2cMsg = "", i2cMsgBuffer, i2cDataBuffer[4];

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
  onLed0();

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

  if (i2cDataBuffer[0] == "rpy-est")
  {
    i2c_msg = sendRPY_est();
  }

  else if (i2cDataBuffer[0] == "heading")
  {
    i2c_msg = send_heading();
  }

  else if (i2cDataBuffer[0] == "rpy-rate")
  {
    i2c_msg = sendRPY_rate();
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

  offLed0();
}

/////////////////////////////////////////////////////////

#endif