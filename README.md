# Minisumo
Code and Files for all the minisumo and sumo related projects I make, this repository includes codes, schematics, drawings, 3D files and more to make your own minisumo robot.\
**Important: These are mostly personal projects, there might be some errors that will be fixed and updated, but I'm not responsable for any damage or malfunction that is caused by using the codes, files, etc. provided in this repository**

*The projects marked in italic are projects that are still on progress*

# Why open source?
When I started there was little to no info on how to make this kind of competition robots, so I want to make newcomers an easy and accesible database.
Also anyone interested in making changes or upgrades can do them depending on their design choice and taste.

# Folders

## Minisumo Robots
- Gyu-Ma-Oh: Basic Minisumo with 4 opponent sensors and 1 Line sensor
- T4nook1: Advanced Minisumo with 5 opponent sensors and 2 line sensors
## PCB's
- Main boards:
  - Tei: PCB for minisumo using arduino nano and TB6612FNG
  - *Tenn: PCB for minisumo using arduino nano and DRV7781 drivers*
  - *Ma: PCB using SMD atmega 328P and DRV7781 drivers*
  - *Jyo: PCB for microsumo using Seeeduino Xiao and DRV7781 drivers*
- Sensors:
    - QTMicro: Microsized line sensor suitable for minisumo and microsumo robots
## Code
- Basic: basic minisumo code without line sensors and 2 opponent sensors
- *SumoESP: minisumo code for the Arduino Nano ESP model*
- Tamashi-I7ach1: main code used for minisumo robot I7ach1 which uses a ESP32-C3 as the main board
- Tamashi-T4nook1: main code used for minisumo robot T4nook1 which uses a atmega328p as the main controller
## 3D Data
- Flag System: DAMASHI-FLAG-SYSTEM, used for minisumo robots, compatible with the "OH", "JIN" and "MA-JIN" motor brackets.
- Motor brackets:
  - OH: motor bracket compatible for the minisumo robot chasis in this repository, it can hold Jsumo style motors
  - JIN: motor bracket compatible for the minisumo robot chasis in this repository, it can hold maxon motors
  - MA-JIN: same as JIN motor bracket, but it can host a qtr-micro line sensor in the back.

# Software that I use
For the most part I try to make all the files as modifiable as possible, but in some cases like the PCB's it's not that possible, so here's a list of software that you can use for the different extensions and file types in this repo.

- 3D data: I mainly use FUSION360 but I upload the files in .IGES and .STL so you can use any 3D CAD software and slicer software out there to modify and/or print the parts.
- PCB's: I upload the gerbers in zip format for easy fabrication, I also upload a separate gerber file and BOM for **[JLPCB](https://jlcpcb.com/)**  fabrication. As for modifying the files I use **[Kicad](https://www.kicad.org/)** which is a free and open source EDA.
- Code: I use Visual Studio Code with the **[PlatformIO](https://platformio.org/)** extension, but the framework I work on is the arduino framework, so you can use the **[ArduinoIDE](https://www.arduino.cc/en/software)** if you want.

---

Wiki and How to Guides soon.....