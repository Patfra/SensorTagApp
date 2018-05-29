import csv
import sys


labels = ["Configuration","IP Address","Temp Conf","Temp Per","Mov Conf","Mov Range","Mov Per","Hum Conf",
          "Hum Per","Press Conf","Press Per","Opt Conf","Opt Per"]

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
        if temp_conf == 1:
            print "For SensorTag number " + str(count+1) + ", specify the temperature reading period (in seconds):"
            temp_per = input()
        else:
            temp_per = 0
        print "For SensorTag number " + str(count + 1) + ", specify if you wish to read gyroscope or accelerometer data:"
        print "0 - none, 1 - gyroscope, 2 - accelerometer"
        mov_conf = input()
        if mov_conf == 0:
            mov_range = 0
            mov_per = 0
        elif mov_conf == 2:
            print "For SensorTag number " + str(count+1) + ", please specify the range of accelerometer:"
            print "0 - 2G, 1 - 4G, 2 - 8G, 3 - 16G"
            mov_range = input()
            print "For SensorTag number " + str(count + 1) + ", please specify the sensor reading period (in seconds):"
            mov_per = input()
        else:
            mov_range = 0
            print "For SensorTag number " + str(count + 1) + ", please specify the sensor reading period (in seconds):"
            mov_per = input()
        print "For SensorTag number " + str(count + 1) + ", specify if you wish to read humidity:"
        print "1 - yes, 0 - no"
        hum_conf = input()
        if hum_conf == 1:
            print "For SensorTag number " + str(count+1) + ", specify the humidity reading period (in seconds):"
            hum_per = input()
        else:
            hum_per = 0
        print "For SensorTag number " + str(count + 1) + ", specify if you wish to read barometric pressure:"
        print "1 - yes, 0 - no"
        pres_conf = input()
        if pres_conf == 1:
            print "For SensorTag number " + str(count + 1) + ", specify the pressure reading period (in seconds):"
            pres_per = input()
        else:
            pres_per = 0
        print "For SensorTag number " + str(count + 1) + ", specify if you wish to read optical sensor data:"
        print "1 - yes, 0 - no"
        opt_conf = input()
        if opt_conf == 1:
            print "For SensorTag number " + str(count + 1) + ", specify the optical sensor reading period (in seconds):"
            opt_per = input()
        else:
            opt_per = 0
        print "SensorTag number " + str(count + 1)+" preferences saved.\n"
        if count == 0:
            confwriter.writerow(["Sensor"+str(count+1),ip_addr,temp_conf,temp_per,mov_conf,mov_range,mov_per,
                                 hum_conf,hum_per,pres_conf,pres_per,opt_conf,opt_per])
        else:
            confwriter.writerow(["Sensor"+str(count+1), ip_addr, temp_conf, temp_per, mov_conf, mov_range, mov_per,
                                 hum_conf, hum_per, pres_conf, pres_per, opt_conf, opt_per])
    print "Configuration file saved.\n"
    csvfile.close()


