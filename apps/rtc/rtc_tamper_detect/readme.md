---
parent: Harmony 3 peripheral library application examples for PIC32CM LE/LS family
title: RTC tamper detect 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# RTC tamper detect

This example application shows how to configure and use tamper detect feature of RTC.

## Description

This example application shows how to setup system time and configure tamper detection using the RTC Peripheral Library. The application sets up system time and then waits for tamper detection to happen. On Tamper detection, application displays the tamper detected information and timestamp at which tamper is detected.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_sg_gc) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/rtc/rtc_tamper_detect/** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32cm_gc_curiosity_pro.X | MPLABX project for [PIC32CM GC00 Curiosity Pro]() |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_gc_curiosity_pro.X | [PIC32CM GC00 Curiosity Pro]()
|||

### Setting up [PIC32CM GC00 Curiosity Pro]()

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Open the Terminal application (Ex.:Tera term) on the computer
2. Connect to the EDBG Virtual COM port and configure the serial settings as follows:
    - Baud : 115200
    - Data : 8 Bits
    - Parity : None
    - Stop : 1 Bit
    - Flow Control : None
3. Build and Program the application project using its IDE
4. System time is displayed in terminal session as RTC is configured in calendar mode.

    ![output](images/output_rtc_tamper_detect_1.png)

    *NOTE: System time value shown in the screen capture are for illustration purpose only. it will be updated every second while running the application.*

5. To generate a tamper event, press switch SW0:

    | Board      | Switch |
    | ---------- | --- |
    | [PIC32CM GC00 Curiosity Pro]() | SW0 |
    |||

6. Upon detection of the tamper event, LED will be toggled and the console output will be updated as follows:

    ![output](images/output_rtc_tamper_detect_2.png)

Following table provides the LED name:

| Board      | LED Name |
| ---------- | ---------------- |
| [PIC32CM GC00 Curiosity Pro]() | LED0 |
|||
