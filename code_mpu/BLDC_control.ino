#include "MPU9250.h"
#include "Servo.h"

byte servoPin = 8;

MPU9250 mpu;
Servo servo;
void setup() {
    servo.attach(servoPin);
    servo.writeMicroseconds(1000);
    Serial.begin(9600);
    Wire.begin();
    delay(2000);
    
    if (!mpu.setup(0x68)) {  // change to your own address
        while (1) {
            Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
            delay(5000);
        }
    }
}

void loop() {
    if (mpu.update()) 
    {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
            print_roll_pitch_yaw();
            prev_ms = millis();
        }
    }
    
    int roll = abs(mpu.getRoll());
    
    int pwmVal = map(roll,0,90,1000,2000);
    
    Serial.println(roll);
    Serial.println(mpu.getRoll(), 2);
    servo.writeMicroseconds(pwmVal);
}

void print_roll_pitch_yaw() {
    //Serial.print("Yaw, Pitch, Roll: ");
    //Serial.print(mpu.getYaw(), 2);
    //Serial.print(", ");
    //Serial.print(mpu.getPitch(), 2);
    //Serial.print(", ");
    Serial.println("============================");
}
