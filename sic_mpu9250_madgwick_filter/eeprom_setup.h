#ifndef EEPROM_SETUP_H
#define EEPROM_SETUP_H



/////////////////// STORING AND READING PARAMETERS FROM EEPROM /////////////////
#include <EEPROM.h>
#include "global_eeprom_variables.h"

int FIRST_TIME_ADDRESS = 0;

int AX_OFFSET_ADDRESS = 4;
int AY_OFFSET_ADDRESS = 8;
int AZ_OFFSET_ADDRESS = 12;

int GX_OFFSET_ADDRESS = 16;
int GY_OFFSET_ADDRESS = 20;
int GZ_OFFSET_ADDRESS = 24;

int B_VECT_X_ADDRESS = 28;
int B_VECT_Y_ADDRESS = 32;
int B_VECT_Z_ADDRESS = 36;

int A_MAT_00_ADDRESS = 40;
int A_MAT_01_ADDRESS = 44;
int A_MAT_02_ADDRESS = 48;

int A_MAT_10_ADDRESS = 52;
int A_MAT_11_ADDRESS = 56;
int A_MAT_12_ADDRESS = 60;

int A_MAT_20_ADDRESS = 64;
int A_MAT_21_ADDRESS = 68;
int A_MAT_22_ADDRESS = 72;

int ROLL_ANGLE_VAR_ADDRESS = 76;
int PITCH_ANGLE_VAR_ADDRESS = 80;
int YAW_ANGLE_VAR_ADDRESS = 84;

int ROLL_RATE_VAR_ADDRESS = 88;
int PITCH_RATE_VAR_ADDRESS = 92;
int YAW_RATE_VAR_ADDRESS = 96;

int ACC_X_VAR_ADDRESS = 100;
int ACC_Y_VAR_ADDRESS = 104;
int ACC_Z_VAR_ADDRESS = 108;

int I2C_ADDRESS = 112;
int GAIN_ADDRESS = 116;





//////////////////////////////////////////////////////////
float getFilterGain(){
  float gain;
  EEPROM.get(GAIN_ADDRESS, gain);
  return gain;
}
void setFilterGain(float gain){
  EEPROM.put(GAIN_ADDRESS, gain);
  filterGain = getFilterGain();
  madgwickFilter.setAlgorithmGain(filterGain);
}

int getI2CADDRESS(){
  float address;
  EEPROM.get(I2C_ADDRESS, address);
  return (int)address;
}

void setI2CADDRESS(int address){
  EEPROM.put(I2C_ADDRESS, (float)address);
  i2cAddress = getI2CADDRESS();
  Wire.begin(i2cAddress);
}
/////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////

float getAxOffset(){
  float axOffset;
  EEPROM.get(AX_OFFSET_ADDRESS, axOffset);
  return axOffset;
}

float getAyOffset(){
  float ayOffset;
  EEPROM.get(AY_OFFSET_ADDRESS, ayOffset);
  return ayOffset;
}

float getAzOffset(){
  float azOffset;
  EEPROM.get(AZ_OFFSET_ADDRESS, azOffset);
  return azOffset;
}

//////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////

float getGxOffset(){
  float gxOffset;
  EEPROM.get(GX_OFFSET_ADDRESS, gxOffset);
  return gxOffset;
}

float getGyOffset(){
  float gyOffset;
  EEPROM.get(GY_OFFSET_ADDRESS, gyOffset);
  return gyOffset;
}

float getGzOffset(){
  float gzOffset;
  EEPROM.get(GZ_OFFSET_ADDRESS, gzOffset);
  return gzOffset;
}

//////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////

float getBvectX(){
  float bvectX;
  EEPROM.get(B_VECT_X_ADDRESS, bvectX);
  return bvectX;
}

float getBvectY(){
  float bvectY;
  EEPROM.get(B_VECT_Y_ADDRESS, bvectY);
  return bvectY;
}

float getBvectZ(){
  float bvectZ;
  EEPROM.get(B_VECT_Z_ADDRESS, bvectZ);
  return bvectZ;
}

//////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////

float getAmat00(){
  float amat00;
  EEPROM.get(A_MAT_00_ADDRESS, amat00);
  return amat00;
}

float getAmat01(){
  float amat01;
  EEPROM.get(A_MAT_01_ADDRESS, amat01);
  return amat01;
}

float getAmat02(){
  float amat02;
  EEPROM.get(A_MAT_02_ADDRESS, amat02);
  return amat02;
}

float getAmat10(){
  float amat10;
  EEPROM.get(A_MAT_10_ADDRESS, amat10);
  return amat10;
}

float getAmat11(){
  float amat11;
  EEPROM.get(A_MAT_11_ADDRESS, amat11);
  return amat11;
}

float getAmat12(){
  float amat12;
  EEPROM.get(A_MAT_12_ADDRESS, amat12);
  return amat12;
}

float getAmat20(){
  float amat20;
  EEPROM.get(A_MAT_20_ADDRESS, amat20);
  return amat20;
}

float getAmat21(){
  float amat21;
  EEPROM.get(A_MAT_21_ADDRESS, amat21);
  return amat21;
}

float getAmat22(){
  float amat22;
  EEPROM.get(A_MAT_22_ADDRESS, amat22);
  return amat22;
}

//////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////

float getRollAngleVariance(){
  float rollAngleVariance;
  EEPROM.get(ROLL_ANGLE_VAR_ADDRESS, rollAngleVariance);
  return rollAngleVariance;
}
void setRollAngleVariance(float rollAngleVariance){
  EEPROM.put(ROLL_ANGLE_VAR_ADDRESS, rollAngleVariance);
  roll_variance = getRollAngleVariance();
}

float getPitchAngleVariance(){
  float pitchAngleVariance;
  EEPROM.get(PITCH_ANGLE_VAR_ADDRESS, pitchAngleVariance);
  return pitchAngleVariance;
}
void setPitchAngleVariance(float pitchAngleVariance){
  EEPROM.put(PITCH_ANGLE_VAR_ADDRESS, pitchAngleVariance);
  pitch_variance = getPitchAngleVariance();
}

float getYawAngleVariance(){
  float yawAngleVariance;
  EEPROM.get(YAW_ANGLE_VAR_ADDRESS, yawAngleVariance);
  return yawAngleVariance;
}
void setYawAngleVariance(float yawAngleVariance){
  EEPROM.put(YAW_ANGLE_VAR_ADDRESS, yawAngleVariance);
  yaw_variance = getYawAngleVariance();
}

//////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////

float getRollRateVariance(){
  float rollRateVariance;
  EEPROM.get(ROLL_RATE_VAR_ADDRESS, rollRateVariance);
  return rollRateVariance;
}

float getPitchRateVariance(){
  float pitchRateVariance;
  EEPROM.get(PITCH_RATE_VAR_ADDRESS, pitchRateVariance);
  return pitchRateVariance;
}

float getYawRateVariance(){
  float yawRateVariance;
  EEPROM.get(YAW_RATE_VAR_ADDRESS, yawRateVariance);
  return yawRateVariance;
}

//////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////
float getAccxVariance(){
  float accxVariance;
  EEPROM.get(ACC_X_VAR_ADDRESS, accxVariance);
  return accxVariance;
}

float getAccyVariance(){
  float accyVariance;
  EEPROM.get(ACC_Y_VAR_ADDRESS, accyVariance);
  return accyVariance;
}

float getAcczVariance(){
  float acczVariance;
  EEPROM.get(ACC_Z_VAR_ADDRESS, acczVariance);
  return acczVariance;
}
//////////////////////////////////////////////////////////////










//////////////////////////////////////////////////////////////////////////////

void updateGlobalParamsFromEERPOM(){

  axOff = getAxOffset();
  ayOff = getAyOffset();
  azOff = getAzOffset();

  gxOff = getGxOffset();
  gyOff = getGyOffset();
  gzOff = getGzOffset();

  b_vect[0] = getBvectX();
  b_vect[1] = getBvectY();
  b_vect[2] = getBvectZ();

  A_mat[0][0] = getAmat00();
  A_mat[0][1] = getAmat01();
  A_mat[0][2] = getAmat02();

  A_mat[1][0] = getAmat10();
  A_mat[1][1] = getAmat11();
  A_mat[1][2] = getAmat12();

  A_mat[2][0] = getAmat20();
  A_mat[2][1] = getAmat21();
  A_mat[2][2] = getAmat22();

  roll_variance = getRollAngleVariance();
  pitch_variance = getPitchAngleVariance();
  yaw_variance = getYawAngleVariance();

  roll_rate_variance = getRollRateVariance();
  pitch_rate_variance = getPitchRateVariance();
  yaw_rate_variance = getYawRateVariance();

  accx_variance = getAccxVariance();
  accy_variance = getAccyVariance();
  accz_variance = getAcczVariance();

  filterGain = getFilterGain();
  i2cAddress = getI2CADDRESS();
}
/////////////////////////////////////////////////////////////


#endif