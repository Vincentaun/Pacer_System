# Pacer System

**A Preliminary Study on the Application of Low-Cost Microcontrollers for Aerobic Endurance Assessment: Development and Field Testing of a PACER System**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Arduino](https://img.shields.io/badge/Arduino-Compatible-blue.svg)](https://www.arduino.cc/)

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [System Architecture](#system-architecture)
- [Project Structure](#project-structure)
- [Assets Gallery](#assets-gallery)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## 🎯 Overview

The Pacer System is an innovative Arduino-based fitness assessment tool designed to evaluate aerobic endurance using low-cost microcontrollers. This system implements a digital version of the Progressive Aerobic Cardiovascular Endurance Run (PACER) test, providing real-time feedback and automated scoring for fitness assessments.

The system uses ultrasonic sensors to detect participant movement, an LCD display for real-time feedback, and audio cues to guide the testing process. It's designed for educational institutions, fitness centers, and research applications where cost-effective fitness assessment tools are needed.

## ✨ Features

- **Automated PACER Test Implementation**: Digital version of the standard PACER fitness test
- **Real-time Distance Detection**: Ultrasonic sensor-based movement tracking
- **Progressive Difficulty**: 7 rounds with increasing pace requirements
- **Visual Feedback**: 16x2 LCD display showing round, count, and failure information
- **Audio Cues**: Buzzer notifications for timing and feedback
- **Automatic Scoring**: Real-time calculation of test results
- **Failure Detection**: Automatic detection of missed intervals (max 2 failures)
- **Reset Functionality**: Easy system restart via button press
- **Low-cost Implementation**: Uses readily available Arduino components

## 🔧 Hardware Requirements

### Core Components
- **Arduino Uno/Nano** (or compatible microcontroller)
- **HC-SR04 Ultrasonic Sensor** - Distance measurement
- **16x2 I2C LCD Display** - Real-time feedback
- **Push Button** - System control and reset
- **Buzzer** - Audio feedback
- **Jumper Wires** - Connections
- **Breadboard** - Prototyping (optional)

### Pin Configuration
```
Ultrasonic Sensor:
- Trigger Pin: Digital Pin 13
- Echo Pin: Digital Pin 12

LCD Display (I2C):
- SDA: A4 (Arduino Uno)
- SCL: A5 (Arduino Uno)
- Address: 0x27

Button: Digital Pin 2 (with internal pull-up)
Buzzer: Digital Pin 8
```

## 🚀 Installation

### Prerequisites
- Arduino IDE (version 1.8.0 or higher)
- Required Libraries:
  - `Wire.h` (included with Arduino IDE)
  - `LiquidCrystal_I2C.h`

### Library Installation
1. Open Arduino IDE
2. Go to **Sketch** → **Include Library** → **Manage Libraries**
3. Search for "LiquidCrystal I2C" by Frank de Brabander
4. Click **Install**

### Hardware Setup
1. Connect the ultrasonic sensor:
   - VCC → 5V
   - GND → GND
   - Trig → Pin 13
   - Echo → Pin 12

2. Connect the I2C LCD:
   - VCC → 5V
   - GND → GND
   - SDA → A4
   - SCL → A5

3. Connect the button:
   - One terminal → Pin 2
   - Other terminal → GND

4. Connect the buzzer:
   - Positive → Pin 8
   - Negative → GND

### Software Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/Vincentaun/Pacer_System.git
   ```

2. Open `Code_for_machine.ino` in Arduino IDE

3. Select your Arduino board and port:
   - **Tools** → **Board** → Select your Arduino model
   - **Tools** → **Port** → Select the appropriate COM port

4. Upload the code to your Arduino

## 📖 Usage

### Starting the Test
1. Power on the Arduino system
2. The LCD will display a 5-second countdown with visual effects
3. Position the participant at the starting line (within 150cm of the sensor)
4. Press and hold the button to begin the test

### During the Test
- The system runs through 7 progressive rounds
- Each round has specific timing requirements:
  - Round 1: 7 intervals, 9-second timing
  - Round 2: 8 intervals, 8.5-second timing
  - Round 3: 8 intervals, 8-second timing
  - Round 4: 9 intervals, 7.5-second timing
  - Round 5: 9 intervals, 7-second timing
  - Round 6: 10 intervals, 6.5-second timing
  - Round 7: 10 intervals, 6-second timing

### Test Completion
- **Success**: Complete all rounds successfully
- **Failure**: Miss 2 intervals (automatic termination)
- **Reset**: Press the button when prompted to restart

### Display Information
- **Round**: Current test round (1-7)
- **Count**: Successful intervals completed
- **Fail**: Number of failed intervals (max 2)
- **Result**: Final score upon completion

## 🏗️ System Architecture

### Test Logic Flow
```
Start → Countdown → Round 1 → ... → Round 7 → Success
  ↓                    ↓              ↓
Reset ← Fail (2x) ← Timeout ← Distance Check
```

### Timing System
- Each round has progressively shorter intervals
- Ultrasonic sensor detects participant position
- Audio feedback confirms successful intervals
- Visual display shows real-time progress

## 📁 Project Structure

```
Pacer_System/
├── Code_for_machine.ino          # Main Arduino code
├── README.md                     # Project documentation
├── LICENSE                       # MIT License
├── 實驗記錄表 - Experiment Data.xlsx # Experimental data
└── assets/                       # Project assets
    ├── Arduino_MC.png           # Arduino microcontroller image
    ├── LCD_Display.png          # LCD display image
    ├── Materials.png            # Materials overview
    ├── Ultrasonic_Sensor.png    # Ultrasonic sensor image
    ├── poster.png               # Project poster
    └── 7864bdfb-91c2-44d7-b179-7c227cd5bad3.mp4 # Demo video
```

## 🖼️ Assets Gallery

The following PNG image files are available in the `assets/` folder for documentation and reference:

| Filename | Path | Description |
|----------|------|-------------|
| `Arduino_MC.png` | `assets/Arduino_MC.png` | Arduino microcontroller component image |
| `LCD_Display.png` | `assets/LCD_Display.png` | LCD display component image |
| `Materials.png` | `assets/Materials.png` | Complete materials overview and setup |
| `Ultrasonic_Sensor.png` | `assets/Ultrasonic_Sensor.png` | Ultrasonic sensor component image |
| `poster.png` | `assets/poster.png` | Project presentation poster |

### Usage in Documentation
These images can be referenced in documentation using:
```markdown
![Arduino Microcontroller](assets/Arduino_MC.png)
![LCD Display](assets/LCD_Display.png)
![Materials Overview](assets/Materials.png)
![Ultrasonic Sensor](assets/Ultrasonic_Sensor.png)
![Project Poster](assets/poster.png)
```

## 🤝 Contributing

We welcome contributions to improve the Pacer System! Here's how you can help:

### How to Contribute
1. **Fork** the repository
2. **Create** a feature branch:
   ```bash
   git checkout -b feature/amazing-feature
   ```
3. **Commit** your changes:
   ```bash
   git commit -m 'Add some amazing feature'
   ```
4. **Push** to the branch:
   ```bash
   git push origin feature/amazing-feature
   ```
5. **Open** a Pull Request

### Contribution Guidelines
- Follow Arduino coding standards
- Add comments for complex logic
- Test thoroughly with hardware
- Update documentation as needed
- Include hardware setup photos if adding new components

### Areas for Improvement
- [ ] Wireless connectivity (WiFi/Bluetooth)
- [ ] Data logging to SD card
- [ ] Mobile app integration
- [ ] Additional sensor support
- [ ] Calibration features
- [ ] Multi-participant support

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

```
MIT License

Copyright (c) 2025 Vincentaun

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## 🙏 Acknowledgments

- **Arduino Community** - For the excellent development platform and libraries
- **LiquidCrystal_I2C Library** - By Frank de Brabander for LCD control
- **Educational Institutions** - For providing testing environments and feedback
- **Open Source Community** - For inspiration and collaborative development

---

**📧 Contact**: For questions, suggestions, or collaboration opportunities, please open an issue on GitHub.

**🔗 Links**: 
- [Arduino Official Website](https://www.arduino.cc/)
- [PACER Test Information](https://www.cooperinstitute.org/fitnessgram)
- [Project Repository](https://github.com/Vincentaun/Pacer_System)
