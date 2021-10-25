#import RPi.GPIO as GPIO
import time
def setup():
    GPIO.setmode(GPIO.board)
    GPIO.setup(11, GPIO.IN)
    GPIO.setup(13, GPIO.IN)
    GPIO.setup(15, GPIO.IN)
    GPIO.setup(16, GPIO.IN)
    GPIO.setup(18, GPIO.IN)
    GPIO.setup(22, GPIO.IN)
    GPIO.setup(7, GPIO.IN)
    GPIO.setup(3, GPIO.IN)
    GPIO.setup(5, GPIO.IN)
    GPIO.setup(12, GPIO.IN)
    GPIO.setup(24, GPIO.IN)
    GPIO.setup(26, GPIO.IN)
    GPIO.setup(19, GPIO.IN)
    GPIO.setup(21, GPIO.IN)
    GPIO.setup(23, GPIO.IN)
def data(binary_speed):
    binary_speed.append(int(GPIO.input(11)))
    binary_speed.append(int(GPIO.input(13)))
    binary_speed.append(int(GPIO.input(15)))
    binary_speed.append(int(GPIO.input(16)))
    binary_speed.append(int(GPIO.input(18)))
    binary_speed.append(int(GPIO.input(22)))
    binary_speed.append(int(GPIO.input(7)))
    binary_speed.append(int(GPIO.input(3)))
    binary_speed.append(int(GPIO.input(5)))
    binary_speed.append(int(GPIO.input(12)))
    binary_speed.append(int(GPIO.input(24)))
    binary_speed.append(int(GPIO.input(26)))
    binary_speed.append(int(GPIO.input(19)))
    binary_speed.append(int(GPIO.input(21)))
    binary_speed.append(int(GPIO.input(23)))
def loop():
    x = 0
    while (1>x):
        binary_speed = [0,0,1,0,1]
        #count = 0
        '''while (not count):
            data(binary_speed)
            count += 1'''
        string = [str(int) for int in binary_speed]
        str_of = str("".join(string))
        binary_data = int('$s'.format(str_of), 2)
        print(binary_data)
        x+=1
loop()
    
        