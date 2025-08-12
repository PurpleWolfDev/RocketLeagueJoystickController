# Rocket League Joystick Controller

A custom-built joystick controller using Arduino UNO and a dual-axis joystick for playing *Rocket League*. This project demonstrates how to capture analog joystick inputs and translate them into keyboard and mouse actions via Node.js—perfect for hands-on learners, students, and DIY gamers.

---

## 🚀 Features

- **Arduino UNO–based** custom joystick implementation  
- **Analog X/Y axis input** converted to digital keyboard and mouse events  
- **Node.js interface** using `serialport` for serial communication  
- **Input simulation** via `robotjs` to interact with *Rocket League* or other games  
- Lightweight, modular, and easy to adapt for different games or controllers

---

## 📦 Getting Started

### Prerequisites

- **Hardware**: Arduino UNO, dual-axis joystick module, USB cable  
- **Software**: Node.js (v14+ recommended), npm, Arduino IDE  

### Setup Guide

1. **Upload Arduino code**  
   - Open `ArduinoCode.ino` in the Arduino IDE  
   - Select the correct board and port  
   - Upload the sketch to your Arduino UNO

2. **Install Node.js dependencies**  
   ```bash
   cd path/to/project
   npm install
