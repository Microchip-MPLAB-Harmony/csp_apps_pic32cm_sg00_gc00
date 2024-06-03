---
parent: Harmony 3 peripheral library application examples for PIC32CM-GC00 family
title: SERCOM I2C EEPROM read write 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# SERCOM I2C EEPROM read write

This example application demonstrates how to use the SERCOM peripheral to write and read from the I2C serial EEPROM memory.

## Description

This example uses the I2C peripheral library to write an array of values to the I2C Serial EEPROM and verify the value written by reading the values back and comparing it to the value written.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32ck_gc) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/sercom/i2c/master/i2c_eeprom/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32cm_gc_curiosity_pro.X    | MPLABX Project for [PIC32CM GC00 Curiosity PRO]()|
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_gc_curiosity_pro.X    | [PIC32CM GC00 Curiosity PRO]()|
|||

### Setting up [PIC32CM GC00 Curiosity PRO]()

- Connect the Debug USB port on the board to the computer using a micro USB cable
- Connect the [EEPROM 3 click Board](https://www.mikroe.com/eeprom-3-click) on the mikro BUS header

## Running the Application

1. Build and Program the application using its IDE
2. LED indicates success or failure:
    - The LED is turned ON when the value read from the EEPROM matches with the written value
    - The LED is turned OFF when the value read from the EEPROM did not match with the written value

The following table shows the LED name:

| Board      |LED Name   |
| ---------- | ----------- |
| [PIC32CM GC00 Curiosity PRO]()    | LED0 |
||||
