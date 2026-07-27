# 🤖 ESP32 Gesture-Controlled Robotic Arm

An ESP32-based gesture-controlled robotic arm that replicates human hand movements using MPU6050 motion sensing, PCA9685 servo driver, and servo motors.

This project demonstrates Embedded Systems, Robotics, Sensor Interfacing, and Human-Machine Interaction.

---

## 📌 Project Overview

The system allows users to control a robotic arm using hand gestures.

An MPU6050 accelerometer and gyroscope sensor detects hand orientation and movement. The ESP32 processes the sensor data and controls servo motors through the PCA9685 PWM driver to achieve robotic arm movement.

---

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

### System Flow

