# 🤖 ESP32 Gesture-Controlled Robotic Arm

An ESP32-based gesture-controlled robotic arm that replicates human hand movements using MPU6050 motion sensing, PCA9685 servo driver, and servo motors.

This project demonstrates Embedded Systems, Robotics, Sensor Interfacing, and Human-Machine Interaction.

---

## 📌 Project Overview

The system allows users to control a robotic arm using hand gestures.

An MPU6050 accelerometer and gyroscope sensor detects hand orientation and movement. The ESP32 processes the sensor data and controls servo motors through the PCA9685 PWM driver to achieve robotic arm movement.

---
## 📸 Project Gallery

### 🤖 Robotic Arm

Complete view of the ESP32-based gesture-controlled robotic arm.


<img width="1280" height="960" alt="WhatsApp Image 2026-07-28 at 4 19 17 PM" src="https://github.com/user-attachments/assets/b23fe145-a4fb-4dfd-97f5-9f4b18455977" />


### 🧤 Gesture Control Glove

Wearable glove containing MPU6050, flex sensors, Arduino Nano, and HC-05 Bluetooth module.

<img width="996" height="1280" alt="WhatsApp Image 2026-07-28 at 4 24 56 PM" src="https://github.com/user-attachments/assets/a2baa62a-541d-4df9-b317-75102648abc2" />



### 🔌 Complete Setup



https://github.com/user-attachments/assets/91e3bb3d-6024-4c5e-a781-9786de11e460







## ✨ Features

- Real-time hand gesture detection
- ESP32-based control system
- Multi-axis robotic arm movement
- Servo motor control using PCA9685
- MPU6050 sensor interfacing
- Low-cost robotic solution

---

## 🛠️ Hardware Components

- ESP32 Microcontroller Board
- Arduino nano
- HC-05 Bluetooth Module
- MPU6050 Accelerometer & Gyroscope Sensor
- PCA9685 16-Channel Servo Driver
- MG995 Servo Motors
- DC buck converter
- Breadboard
- Jumper Wires
- 5V Power Supply
- 9V Battery

---

## 💻 Software & Technologies

- Embedded C/C++
- Arduino IDE
- ESP32 Programming
- I2C Communication
- PWM Motor Control

---

## ⚙️ Working Principle

1. MPU6050 captures hand movement and orientation.
2. Sensor data is sent to ESP32 using I2C communication.
3. ESP32 processes the gesture data.
4. Control signals are generated for servo motors.
5. Robotic arm replicates the user's hand movement.

## 🔌 Hardware Connections

The gesture-controlled robotic arm consists of two main units:

1. **Gesture Glove Unit**
2. **Robotic Arm Control Unit**

### 🧤 Gesture Glove Unit

The glove captures hand movements using MPU6050 and flex sensors. Arduino Nano processes the sensor data and sends commands wirelessly through the HC-05 Bluetooth module.

<img width="1755" height="1660" alt="Glove" src="https://github.com/user-attachments/assets/80710722-1e91-4a88-ad7d-5d573d560fb1" />

### 🤖 Robotic Arm Control Unit

The ESP32 receives Bluetooth data and controls the servo motors through the PCA9685 PWM servo driver.

 <img width="1989" height="1824" alt="Untitled Sketch_bb" src="https://github.com/user-attachments/assets/77d21202-645d-4140-9dfe-b32cf26172df" />

## 🛠️ Challenges Faced & Solutions

### 1. Servo Motor Power Issue

**Problem:**  
MG995 servo motors require high current, and using a single power source caused servo jitter and unstable movement.

**Solution:**  
Used an external 5V power supply with a buck converter and provided a common ground between ESP32, PCA9685, and servo power supply.


### 2. Sensor Calibration

**Problem:**  
MPU6050 and flex sensor values varied depending on hand position and user movement.

**Solution:**  
Implemented sensor calibration and mapped raw sensor values into suitable servo angles for accurate movement.


### 3. Bluetooth Communication

**Problem:**  
Reliable wireless data transfer between the glove and robotic arm was required.

**Solution:**  
Used HC-05 Bluetooth communication with UART protocol to transmit gesture data from Arduino Nano to ESP32.


### 4. Servo Control

**Problem:**  
Directly controlling multiple servo motors from the microcontroller was difficult due to limited PWM outputs.

**Solution:**  
Used PCA9685 16-channel PWM servo driver to generate stable PWM signals and control multiple servo motors.


