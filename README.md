# MOTOR-BOARD
It's a DEV Board specially developed for controlling motors.
We can use this dev board to make anything from a moving car a self balancing robot or even a CNC mill machine.
It's like a all in one mobility powerhouse.


# BOM
 We have a normal [BOM](BOM/Untitled%20spreadsheet%20-%20BOM.csv)
 & a interactive one https://shaurya-ashu.github.io/MOTOR-BOARD/index.html

# Zine
 <img width="934" height="816" alt="Frame 1" src="https://github.com/user-attachments/assets/bd4e5ca1-61a5-400b-9936-22737e6c4e32" />
 
# Info
It is a dev board based on ESP32-S3-WROOM-1 (My FAV.) mcu, specially designed for multiple types of motors from brushed DC motors, Servo Motors stepper motors etc.
<img width="1350" height="1528" alt="Screenshot 2026-06-09 at 7 26 10 PM" src="https://github.com/user-attachments/assets/f9005f16-3053-4665-83c5-0ffc697a289e" />

I have used a USB-C port for programming and powering Electronics and the dedicated 3S input for powering the motors.
<img width="1240" height="1090" alt="Screenshot 2026-06-09 at 7 27 20 PM" src="https://github.com/user-attachments/assets/0104a7c5-1d12-4b57-a116-27b3fd4fcf5e" />



I have used a INPUT VOLTAGE MULTIPLEXER for selecting between the USB-C power source and battery power source to power the electronics , its is set default to USB power and if USB power is unavailable, then it uses the battery power source.
<img width="1100" height="608" alt="Screenshot 2026-06-09 at 7 28 06 PM" src="https://github.com/user-attachments/assets/f11ae037-f028-4872-8c13-075d096c7efc" />


We have to dedicated LDO to convert USB power source and battery power source to 3.3v .
<img width="522" height="728" alt="Screenshot 2026-06-09 at 7 28 37 PM" src="https://github.com/user-attachments/assets/91f7a6d1-898b-4165-bab3-d96a251ef44d" />


It has three peripheral interfaces which you are UART,I2C & SPI .

<img width="294" height="798" alt="Screenshot 2026-06-09 at 7 29 10 PM" src="https://github.com/user-attachments/assets/41d5618e-4706-4f63-ac96-cae86861cc0f" />


Now lets begin with the main part of the schematics the motor drivers and the selector .
So i have used two 3-Way Switches for selecting between diff motors to drive .
we have 2x-TB6612FNG to drive 4x-DC brushless motor
<img width="646" height="476" alt="Screenshot 2026-06-09 at 7 29 52 PM" src="https://github.com/user-attachments/assets/d4b58ac9-b0ae-4bc9-b800-9b4f6981f7c4" />


4x-Breakout_A4988 where we can insert A4988 Module to run 4x-Stepper motors.
<img width="680" height="720" alt="Screenshot 2026-06-09 at 7 30 38 PM" src="https://github.com/user-attachments/assets/0f4294dc-4ff7-4cab-a7db-59e3f0e1b257" />


also to power the servo i have used 2x-ST1S41PHR buck converter so that each servo can get up-to 6v @1A .
<img width="766" height="620" alt="Screenshot 2026-06-09 at 7 31 12 PM" src="https://github.com/user-attachments/assets/094a2efd-91b7-4cb0-be3b-7b1bb66ba54c" />


Now the the switching part so i have divide it like this in the diagram below :-
<img width="2000" height="1410" alt="DIAGRAM-SELECTOR" src="https://github.com/user-attachments/assets/479544a8-ca5f-4dca-b8dd-259c3510d921" />
Here the vcc enables the drivers for dc-motors & stepper motor and the buck converter for servo's.
The control pins are connected to same pins for for dc-motors , stepper motor & servo .

# PCB

So it's a 4 layer PCB
Confi as:
# Top layer - Signal
<img width="761" height="555" alt="Screenshot 2026-06-10 at 1 47 24 PM" src="https://github.com/user-attachments/assets/29be1bc1-20f4-4f24-9f0b-c71c570c5783" />

# 1 inner layer - GND
<img width="761" height="554" alt="Screenshot 2026-06-10 at 1 47 37 PM" src="https://github.com/user-attachments/assets/0a509127-9394-4e14-a60e-198456100b2b" />

# 2 inner layer - Power
<img width="759" height="549" alt="Screenshot 2026-06-10 at 1 47 53 PM" src="https://github.com/user-attachments/assets/064996bc-c449-4959-bd80-e8e463923036" />

# Bottom layer - Signal
<img width="755" height="547" alt="Screenshot 2026-06-10 at 1 48 08 PM" src="https://github.com/user-attachments/assets/629a9b29-60fe-475c-adfa-a020ff61d2e1" />


the GND layer is divide into two parts then normal electronics and the power/driver electronics and is connected by a single trace .
<img width="761" height="554" alt="Screenshot 2026-06-10 at 1 47 37 PM" src="https://github.com/user-attachments/assets/2f356dde-066e-4748-ae4c-7e49fa3a4415" />




