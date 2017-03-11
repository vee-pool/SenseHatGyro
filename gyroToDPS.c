/*
This program takes raw imu data file (generated from Sense Hat) as input.
And saves gyro data with respect x, y, z axis in separate files "gyroXdps", "gyroYdps", "gyroZdps" respectively.
Raw data is converted to Degrees per Seconds while saving in output files.
Another raw data file in repository is "data_imu" .
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	FILE *infile, *outfilex, *outfiley, *outfilez;

	float buff;
	char temp[20];
	int ret_val=0;

	infile = fopen ("data_imu2.txt","r");
	
	if (infile == NULL)
	{
		printf("Cannot open the file\n");
		return 0;
	}
	
	outfilex = fopen ("gyroXdps.txt", "w");
	outfiley = fopen ("gyroYdps.txt","w");
	outfilez = fopen ("gyroZdps.txt","w");

	fputs("This is X axis gyro data in Degrees per second\n\n", outfilex);
	fputs("This is Y axis gyro data in Degrees per second\n\n", outfiley);
	fputs("This is Z axis gyro data in Degrees per second\n\n", outfilez);

	ret_val = fscanf (infile,"%s",temp);

	while (ret_val != EOF)
	{
		if ( strcmp(temp, "gyro:")==0 )
		{
			ret_val = fscanf (infile,"%s",temp);

			if ( strcmp(temp, "x:")==0 )
			{
				ret_val = fscanf (infile,"%f",&buff);

				fprintf(outfilex, "%0.9f", buff*0.07);				
				fputc('\n',outfilex);
			}

			ret_val = fscanf (infile,"%s",temp);

			if ( strcmp(temp, "y:")==0 )
			{
				ret_val = fscanf (infile,"%f",&buff);

				fprintf(outfiley, "%0.9f", buff*0.07);
				fputc('\n',outfiley);
			}

			ret_val = fscanf (infile,"%s",temp);

			if ( strcmp(temp, "z:")==0 )
			{
				ret_val = fscanf (infile,"%f",&buff);

				fprintf(outfilez, "%0.9f", buff*0.07);
				fputc('\n',outfilez);
			}
		}

		ret_val = fscanf (infile,"%s",temp);
	}

	fclose(infile);
	fclose(outfilex);
	fclose(outfiley);
	fclose(outfilez);

	return 0;
}
