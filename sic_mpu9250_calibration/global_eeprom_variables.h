#ifndef GLOBAL_EEPROM_VARIABLES
#define GLOBAL_EEPROM_VARIABLES


///////////////////////////////////////////////////
float axRaw = 0.00;
float ayRaw = 0.00;
float azRaw = 0.00;

float axCal = 0.00;
float ayCal = 0.00;
float azCal = 0.00;

float axOff = 0.00;
float ayOff = 0.00;
float azOff = 0.00;

float acc_vect[3];
float acc_vect_norm[3];

float accx_variance = 0.00;
float accy_variance = 0.00;
float accz_variance = 0.00;
////////////////////////////////////////////////////


////////////////////////////////////////////////////
float gxRaw = 0.00;
float gyRaw = 0.00;
float gzRaw = 0.00;

float gxCal = 0.00;
float gyCal = 0.00;
float gzCal = 0.00;

float gxOff = 0.00;
float gyOff = 0.00;
float gzOff = 0.00;
////////////////////////////////////////////////////




////////////////////////////////////////////////////
// magCal = A*(magRaw - b) using the A matrix and b vector to remove the magnetic offsets
float mxRaw = 0.00;
float myRaw = 0.00;
float mzRaw = 0.00;

float mxCal = 0.00;
float myCal = 0.00;
float mzCal = 0.00;

float A_mat[3][3];

float b_vect[3];

float mag_vect[3];
float mag_vect_norm[3];

// sensor body NWU frame
float n[3], w[3], u[3];
////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
float roll, pitch, yaw;

float Q_roll = 0.00; // roll rate gyro bias process noise (i.e gxCal rate variance)
float R_roll = 0.00; // roll angle measurement variance

float Q_pitch = 0.00; // pitch rate gyro bias process noise (i.e gyCal rate variance)
float R_pitch = 0.00; // pitch angle measurement variance

float Q_yaw = 0.00; // yaw rate gyro bias process noise (i.e gzCal rate variance)
float R_yaw = 0.00; // yaw angle measurement variance
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
float qw=0.00;
float qx=0.00;
float qy=0.00;
float qz=0.00;
////////////////////////////////////////////////////////////////////////////


#endif


