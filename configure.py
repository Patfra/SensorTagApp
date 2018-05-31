import csv
import sys


labels = ["Configuration","IP Address","Temp Conf","Mov Conf","Mov Range","Hum Conf",
          "Press Conf","Opt Conf","Period"]

print "SensorTag Configuration File Creator"
print "You will be asked to input specific values or specify options\n"
print "First of all, specify the amount of Sensors used:"
amount = input()
with open('sensorconfig.csv', 'wb') as csvfile:
    confwriter = csv.writer(csvfile)
    confwriter.writerow(["Amount",amount])
    confwriter.writerow(labels)

    for count in range(0,amount):
        print "For SensorTag number "+str(count+1)+", enter its IP address:"
        ip_addr = raw_input()
        ip_addr = str(ip_addr)
        print "For SensorTag number " + str(count+1) + ", specify if you wish to read temperature:"
        print "1 - yes, 0 - no"
        temp_conf = input()
        print "For SensorTag number " + str(count + 1) + ", specify if you wish to read gyroscope or accelerometer data:"
        print "0 - none, 1 - gyroscope, 2 - accelerometer"
        mov_conf = input()
        if mov_conf == 0:
            mov_range = 0
        elif mov_conf == 2:
            print "For SensorTag number " + str(count+1) + ", please specify the range of accelerometer:"
            print "0 - 2G, 1 - 4G, 2 - 8G, 3 - 16G"
            mov_range = input()
        else:
            mov_range = 0
        print "For SensorTag number " + str(count + 1) + ", specify if you wish to read humidity:"
        print "1 - yes, 0 - no"
        hum_conf = input()
        print "For SensorTag number " + str(count + 1) + ", specify if you wish to read barometric pressure:"
        print "1 - yes, 0 - no"
        pres_conf = input()
        print "For SensorTag number " + str(count + 1) + ", specify if you wish to read optical sensor data:"
        print "1 - yes, 0 - no"
        opt_conf = input()
        print "For SensorTag number " + str(count + 1) + ", specify data reading period (in milliseconds):"
        print "Possible range: 300 - 2550 ms"
        period = input()
        while (period < 300 or period > 2550):
            if ( period < 300 or period > 2550):
                print "Out of range! Try again:"
            period = input()
        print "SensorTag number " + str(count + 1)+" preferences saved.\n"
        if count == 0:
            confwriter.writerow(["Sensor"+str(count+1),ip_addr,temp_conf,mov_conf,mov_range,
                                 hum_conf,pres_conf,opt_conf, period])
        else:
            confwriter.writerow(["Sensor"+str(count+1), ip_addr, temp_conf, mov_conf, mov_range,
                                 hum_conf, pres_conf, opt_conf, period])
    print "Configuration file saved.\n"
    csvfile.close()


