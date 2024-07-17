---
parent: Harmony 3 peripheral library application examples for PIC32CM GC/SG family
title: MCRAMC ECC with Fault Injection testing
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# MCRAMC ECC with Fault Injection testing

This example application demonstrates how to test the SRAM using the MCRAMC ECC feature on internal SRAM memory.

## Description

This example uses the MCRAMC to test its ECC with Fault Injection feature. This application writes a 32-bit data in SRAM for single and double error injection to highlight SEC and DED process.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_sg_gc) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/nvmctrl/mcramc_ecc_testing/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32cm_gc_curiosity_pro.X | MPLABX project for [PIC32CM GC00 Curiosity Pro board Kit](https://www.microchip.com/developmenttools/ProductDetails/) |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_gc_curiosity_pro.X | [PIC32CM GC00 Curiosity Pro board](https://www.microchip.com/dev
elopmenttools/ProductDetails/)
|||

### Setting up [PIC32CM GC00 Curiosity Pro board](https://www.microchip.com/developmenttools/ProductDetails/)

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Build and Program the application using its IDE
2. Application Menu is displayed with following choices
	- 'a': Single Fault Injection is chosen and following message is displayed on console:
	
	![output](images/mcramc_single_fault_injection_display.png)
	
	- 'b': Double Fault Injection is chosen and following message is displayed on console:
	
	![output](images/mcramc_double_fault_injection_display.png)
	
3. The on-board LED blinks each time a SERR interrupt occurs
