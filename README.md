# SenseHatGyro
This program takes raw imu data file (generated from Sense Hat) as input.
And saves gyro data with respect x, y, z axis in separate files "gyroXdps", "gyroYdps", "gyroZdps" respectively.
Raw data is converted to Degrees per Seconds while saving in output files.
Another raw data file in repository is "data_imu" .

# Compilation
````
gcc -Wall gyroToDPS.c -lm -o gyroToDPS
````
