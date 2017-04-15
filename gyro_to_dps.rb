def gyro_to_dps(in_file)
  j = 0 # To print the reading numbers

  puts 'Gyroscope readings in Degrees per Seconds'
  in_file.readlines.each do |line|
    if line =~ /gyro:/
      j += 1
      puts "---#{j}---"
      array = line.split(',')
      (0...array.length).each do |i|
        inner_array = array[i].split
        if i.zero?
          x = inner_array[inner_array.length - 1].to_f * 0.07
          puts "x: #{x}"
        elsif i == 1
          y = inner_array[inner_array.length - 1].to_f * 0.07
          puts "y: #{y}"
        elsif i == 2
          z = inner_array[inner_array.length - 1].to_f * 0.07
          puts "z: #{z}"
        end
      end
    end
  end
end

file = File.new('data_imu.txt', 'r')
gyro_to_dps(file)
file.close
