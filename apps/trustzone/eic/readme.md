---
parent: Harmony 3 peripheral library application examples for PIC32CM LE/LS family
title: TrustZone EIC pin toggle
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# TrustZone EIC pin toggle

This example application demonstrates handling of external pin interrupt in secure and non-secure project.

## Description

This demonstrates TrustZone feature and uses two projects viz., Secure and Non-Secure Project that work together on the same
MCU and offering security isolation between the Trusted and the Non-trusted resources in the device.

- Secure project uses an EIC pin to generate interrupt on rising edge and toggles LED0
- Non-secure project uses an EIC pin to generate interrupt on rising edge and toggles LED1

## Components Used

- **EIC** - Configured as Mix-Secure Peripheral for Secure EIC and Non-secure EIC interrupts
- **LED0** - Configured as Secure mode
- **LED1** - Configured as Non-secure mode

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_sg_gc) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is as shown below:

| Type        | Path                         |
|:-----------:|:----------------------------:|
| Project group | apps/trustZone/eic/eic/pic32cm_sg_curiosity_progroup |
|Secure Project|  apps/trustZone/eic/eic_secure |
|Non-Secure Project|  apps/trustZone/eic/ |
||||

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| :-----------------: | :----------------------------------------------: |
| pic32cm_sg_curiosity_pro_Secure.X <br> pic32cm_sg_curiosity_pro.X | Secure and Non-secure MPLABX project for [PIC32CM SG00 Curiosity Pro]() |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_sg_curiosity_pro_Secure.X <br> pic32cm_sg_curiosity_pro.X  | [PIC32CM SG00 Curiosity Pro]() |
|||

### Setting up [PIC32CM SG00 Curiosity Pro]()

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Open the project group in the MPLAB X IDE and set the non-secure project as main project
2. Build and program the application
3. Observe the output for [PIC32CM SG00 Curiosity Pro]() as follows:
    - LED0(Green) is toggled on Switch (SW0) press using EIC interrupt in secure project
    - LED1(Red) is toggled on Switch (SW1) press using EIC interrupt in non-secure project    