---
parent: Harmony 3 peripheral library application examples for PIC32CM GC00 family
title: Flash read write 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# FCW read write

This example application demonstrates how to use the FCW to erase and program the internal Flash memory.

## Description

This example uses the FCW peripheral library to erase a row and write an array of values to the internal Flash memory. It verifies the value written by reading the values back and comparing it to the value written.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_sg_gc) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/fcw/flash_read_write/firmware** .

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

## Running the Application

1. Build and Program the application using its IDE
2. The LED indicates the success or failure:
    - The LED is turned ON when the value read from the flash memory matched with the written value
    - The LED is turned OFF when the value read from the flash memory did not match with the written value
3. The following table provides the LED name:

| Board      | LED Name |
| ---------- | ---------------- |
| [PIC32CM GC00 Curiosity PRO]()    | LED0 |
|||
