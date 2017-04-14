def gyro_to_dps(in_file)
  outfile_x = File.new('gyro_x_dps.txt', 'w')
  outfile_y = File.new('gyro_y_dps.txt', 'w')
  outfile_z = File.new('gyro_z_dps.txt', 'w')

  outfile_x.syswrite("This is X axis gyro data in Degrees per second\n\n")
  outfile_y.syswrite("This is Y axis gyro data in Degrees per second\n\n")
  outfile_z.syswrite("This is Z axis gyro data in Degrees per second\n\n")

  in_file.readlines.each do |line|
    if line =~ /gyro:/
      array = line.split(',')
      (0...array.length).each do |i|
        inner_array = array[i].split

        if i.zero?
          raw_x = inner_array[inner_array.length - 1].to_f * 0.07
          outfile_x.syswrite(raw_x)
          outfile_x.syswrite("\n")
        elsif i == 1
          raw_y = inner_array[inner_array.length - 1].to_f * 0.07
          outfile_y.syswrite(raw_y)
          outfile_y.syswrite("\n")
        elsif i == 2
          raw_z = inner_array[inner_array.length - 1].to_f * 0.07
          outfile_z.syswrite(raw_z)
          outfile_z.syswrite("\n")
        end
      end
    end
  end

  outfile_x.close
  outfile_y.close
  outfile_z.close
end

file = File.new('data_imu.txt', 'r')
gyro_to_dps(file)
file.close
