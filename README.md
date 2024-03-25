# sic_mpu9250_driver_code
This is a child project of the Samuko IMU Compute (`sic_mpu9250`) project. It contains the code that is uploaded into `sic_mpu9250_driver module` via an FTDI programmer.
</br>
It has two parts - `sic_mpu9250_calibration` and `sic_mpu9250_kalman_filter`.
</br>
the `sic_mpu9250_calibration` is used for calibration and setting up the MPU9250 IMU with the `sic_mpu9250_setup_py_codes`. It is also used with the `sic_mpu9250 ros2 package` and ros2 imu_tools package for ros2 based projects.
</br>
the `sic_mpu9250_kalman_filter` is used with the `sic_mpu9250_i2c_lib` for arduino-based projects. It is also used with the `sic_mpu9250_py_lib` and `sic_mpu9250_cpp_lib` for any other PC or microcomputer project.


## How to Use the Driver Code
- Ensure you have the Arduino IDE up and running on your PC

- Download (by clicking on the green Code button above) or clone the repo into your PC

- extract and copy the library dependencies to your library folder:
> for ubuntu OS, copy to ~/Arduino/libraries folder
> for Windows, copy to ...Documents/Arduino/libraries folder

> NOTE: it makes use of the `invensense-imu` library by bolder flight and `arduino_matrix_vector_lab` library by samuko things

- Open the sic_mpu9250_driver_code folder

- Open any of the `calibration` or `kalman filter` code in your Arduino IDE.

- select the board - `Arduino UNO` - and PORT. 

- verify and upload the code the code to the `sic_mpu9250_driver module` via FTDI programmer.
