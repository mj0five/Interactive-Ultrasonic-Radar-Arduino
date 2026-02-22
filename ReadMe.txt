# Arduino Ultrasonic Radar with Joystick Control & Real-Time PPI Display

Interactive ultrasonic radar system built with Arduino Uno that scans the environment, detects objects, provides audio-visual feedback, supports manual targeting via joystick, and visualizes detections in a classic radar-style PPI (Plan Position Indicator) display using Processing.

## Features

- 180° continuous automatic sweep scanning
- Manual targeting mode using analog joystick (KY-023)
- Mode switching via joystick push-button
- Real-time object detection with HC-SR04 ultrasonic sensor
- Audible alert (active buzzer) when object is within threshold
- Visual status indication (RGB LED: green = clear, red = object detected)
- Classic green phosphor radar visualization with sweep trail and highlighted targets
- Full-screen PPI-style display in Processing

## Hardware Requirements

| Component              | Model / Type         | Quantity | Notes                              |
|------------------------|----------------------|----------|------------------------------------|
| Microcontroller        | Arduino Uno          | 1        | or compatible clone                |
| Ultrasonic Sensor      | HC-SR04              | 1        | mounted on servo                   |
| Micro Servo            | SG90 / MG90S         | 1        | 180° standard hobby servo          |
| Joystick Module        | KY-023 / similar     | 1        | with X-axis & push button          |
| Active Buzzer          | KY-012 / generic     | 1        | active (self-oscillating)          |
| RGB LED Module         | KY-016 (common cathode) | 1     | or discrete LEDs + resistors       |
| Jumper wires           | Male-to-male / male-to-female | ~20 |                                    |
| Breadboard (optional)  | Mini or full-size    | 1        | for prototyping                    |
| USB cable              | Type A to B          | 1        | for programming & power            |

**Power note**: For best stability, power the servo and buzzer from an external 5 V supply (GND shared with Arduino).

## Wiring Diagram
Arduino Uno ───────────────┐
├─ 5V     → HC-SR04 VCC   │
├─ GND    → HC-SR04 GND   │
├─ D10    → HC-SR04 Trig  │
├─ D11    → HC-SR04 Echo  │
├─ D9     → SG90 Signal   │
├─ 5V     → SG90 VCC      │
├─ GND    → SG90 GND      │
├─ A0     → Joystick VRx  │
├─ D2     → Joystick SW   │ (with internal pull-up)
├─ D3     → Buzzer +      │
├─ GND    → Buzzer –      │
├─ D5     → RGB Red       │
├─ D6     → RGB Green     │
└─ D7     → RGB Blue      │ (optional channel)


# Software Requirements

- **Arduino IDE** (≥ 2.0 recommended)  
- **Processing** (≥ 4.x recommended)  
- Arduino libraries: **Servo** (built-in)

# Installation & Usage

Step 1 – Upload Arduino firmware

1. Open `firmware/arduino_radar.ino` in Arduino IDE
2. Select **Tools → Board → Arduino Uno**
3. Select correct port (**Tools → Port**)
4. Click **Upload**

Step 2 – Run radar visualization

1. Open `visualization/radar_display.pde` in Processing
2. Change the serial port name in `setup()` to match your Arduino  
   ```processing
   myPort = new Serial(this, "COM3", 9600);   // ← change this line
(On macOS/Linux usually starts with /dev/cu.usb... or /dev/tty...)
3. Click the Run button (▶)

The radar window should open and start showing live sweep + detections.


# Controls

Joystick left/right → manual targeting (after mode switch)
Joystick button press → toggle between Auto sweep ↔ Manual mode
Object closer than 50 cm → buzzer sounds + LED turns red


feel free to change the code and the diagram. 
I happily welcome any recomendation or modifications. 

