import RPi.GPIO as GPIO
import time
class data_set:
    def __init__(self, wheel_radius:int, angular_velocity: int=0, linear_velocity: int=0, power_draw: int=0, exhaust_temperatures: int=0, motor_temperature: int=0, tyre_temperature: int=0, percentage_loss_to_thermal: int=0) -> None:
        self.wheel_radius = wheel_radius;
        self.angular_velocity = angular_velocity;
        self.linear_velocity = linear_velocity;
        self.power_draw = power_draw;
        self.exhaust_temperatures = exhaust_temperatures;
        self.motor_temperature = motor_temperature;
        self.tyre_temperature = tyre_temperature;
        self.percentage_loss_to_thermal = percentage_loss_to_thermal;
    
def setup() -> None:
    GPIO.setmode(GPIO.board);
    #Angular Velocity
    GPIO.setup(11, GPIO.IN);
    GPIO.setup(13, GPIO.IN);
    GPIO.setup(15, GPIO.IN);
    GPIO.setup(16, GPIO.IN);
    GPIO.setup(18, GPIO.IN);
    GPIO.setup(22, GPIO.IN);
    GPIO.setup(7, GPIO.IN);

    
def speed_data(binary_speed) -> None:
    binary_speed.append(int(GPIO.input(11)));
    binary_speed.append(int(GPIO.input(13)));
    binary_speed.append(int(GPIO.input(15)));
    binary_speed.append(int(GPIO.input(16)));
    binary_speed.append(int(GPIO.input(18)));
    binary_speed.append(int(GPIO.input(22)));
    binary_speed.append(int(GPIO.input(7)));


#Uses inputs from GPIO to convert the binary data to an integer value from the angular velocity
def get_angular_velocity() -> int:
    binary_speed = [];
    count = 0;
    while (not count):
        speed_data(binary_speed);
        count += 1;
    bin = "";
    for i in binary_speed:
        bin = str(i)+bin;
        binary_vel = int(bin, 2);
    return binary_vel**2;
def get_temperature():
#binary to decimal; first bit indicates sign of integer
return None;
