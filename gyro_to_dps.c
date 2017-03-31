/********************************************************************************************************
 * FILE NAME: gyroToDPS.c 																				*
 *																										*
 * PURPOSE: Converting raw IMU data into unit of degrees per second.									*
 *																										*
 * FILE REFERENCES:																						*
 *																										*
 * NAME							I/O 			DESCRIPTION												*
 *																										*
 * data_imu.txt					I 				Raw IMU sensor data collected from SenseHAT				*
 * data_imu2.txt				I 				Raw IMU sensor data collected from SenseHAT				*
 * 																										*
 * gyro_x_dps.txt				O 				Storing gyroscope X axis data in degrees per Seconds 	*
 * gyro_y_dps.txt				O 				Storing gyroscope Y axis data in degrees per Seconds 	*
 * gyro_z_dps.txt				O 				Storing gyroscope Z axis data in degrees per Seconds 	*
 * 																										*
 * EXTERNAL VARIABLES:	none																			*
 *																										*
 * EXTERNAL REFERENCES:	none 																			*
 *																										*
 * ABNORMAL TERMINATION CONDITIONS, ERRORS AND WARNING MESSAGES:										*
 *		Abnormal termination if input file cannot be opened.											*
 * 																										*
 * ASSUMPTIONS, CONSTRAINTS	AND RESTRICTIONS															*
 * 		Assuming input files in specific format which they are.											*
 *																										*
 * NOTES:																								*
 *																										*
 * REQUIREMENTS / FUNCTIONAL SPECIFICATION REFERENCES:													*
 *																										*
 * DEVELOPMENT HISTORY:																					*
 *																										*
 * DATE			AUTHOR		CHANGE ID 		RELEASE		DESCRIPTION OF CHANGE							*
 *																										*
 *																										*
 * 31/3/2017	vee-pool								Convert to NASA C style							*
 ********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  FILE *infile, *outfile_x, *outfile_y, *outfile_z;

  float buff;
  char temp[20];
  int ret_val=0;

  infile = fopen ("data_imu2.txt", "r");
  
  if (infile == NULL)
  {
    printf("Cannot open the file data_imu.txt\n");
    return 0;
  }
  
  outfile_x = fopen ("gyro_x_dps.txt", "w");
  outfile_y = fopen ("gyro_y_dps.txt", "w");
  outfile_z = fopen ("gyro_z_dps.txt", "w");

  fputs("This is X axis gyro data in Degrees per second\n\n", outfile_x);
  fputs("This is Y axis gyro data in Degrees per second\n\n", outfile_y);
  fputs("This is Z axis gyro data in Degrees per second\n\n", outfile_z);

  ret_val = fscanf (infile, "%s", temp);

  while (ret_val != EOF)
  {
    if ( strcmp(temp, "gyro:") == 0 )
    {
      ret_val = fscanf (infile, "%s", temp);

      if ( strcmp(temp, "x:")==0 )
      {
        ret_val = fscanf (infile, "%f", &buff);

        fprintf(outfile_x, "%0.9f", buff*0.07);        
        fputc('\n',outfile_x);
      }

      ret_val = fscanf (infile, "%s", temp);

      if ( strcmp(temp, "y:")==0 )
      {
        ret_val = fscanf (infile, "%f",  &buff);

        fprintf(outfile_y, "%0.9f", buff*0.07);
        fputc('\n', outfile_y);
      }

      ret_val = fscanf (infile, "%s", temp);

      if ( strcmp(temp, "z:")==0 )
      {
        ret_val = fscanf (infile, "%f", &buff);

        fprintf(outfile_z, "%0.9f", buff*0.07);
        fputc('\n', outfile_z);
      }
    }

    ret_val = fscanf (infile, "%s", temp);
  }

  fclose(infile);
  fclose(outfile_x);
  fclose(outfile_y);
  fclose(outfile_z);

  return 0;
}