---
parent: Harmony 3 peripheral library application examples for PIC32CM-GC/SG family
title: ADC Blocking
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# ADC Blocking

This example application shows how to use the ADC Peripheral library in blocking mode to convert analog input on a ADC channel

## Description

The example application uses Global Software trigger to start a conversion on a ADC channel input and blocks until the conversion is complete. Once the ADC conversion is complete, it reads the ADC count value, converts it into analog voltage and prints it on the serial terminal.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_sg_gc) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/adc/adc_blocking/firmware** .

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
- ADC Core 0 Channel 0 input is available on PA03 (Pin 3 of EXT1). Connect PA03 to anlog input voltage.

## Running the Application

1. Build and Program the application using its IDE
2. Connect to the PKOB4 Virtual COM port and configure the serial settings as follows:
    - Baud : 115200
    - Data : 8 Bits
    - Parity : None
    - Stop : 1 Bit
    - Flow Control : None
3. The demo application will print the ADC count and the corresponding analog voltage measured on pin PA04 (Pin 3 of EXT1):

	![output](images/image_1.png)
