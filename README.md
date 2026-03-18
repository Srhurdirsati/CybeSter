# CyberSter

Cyberster is a portable MP3 player using different electronic modules. It can play music from an SD card and send audio through AUX or Bluetooth. A screen is used to show the menu and song information. The device also uses a Type-C port for power and transferring music files.

## Complete Hardware & BOM Table

| Ref | Component / Module | Example / Manufacturer Part | LCSC Part # | Qty |
|-----|--------------------|-----------------------------|-------------|-----|
| U1 | ESP32-S3 WiFi + Bluetooth module | ESP32-S3-WROOM-1-N16R8 | C2913202 | 1 | 
| U2 | MP3 audio decoder | VS1053B-L | C13316 | 1 |
| U3 | 3.3V LDO regulator | AMS1117-3.3 | C6186 | 1 |
| J1 | USB Type-C connector | TYPE-C-31-M-12 | C165948 | 1 | 
| J2 | MicroSD card socket | MICRO-SD-DM3D-SF | C91145 | 1 |
| J3 | 3.5mm headphone jack | PJ-320A | C128188 | 1 | 
| X1 | Crystal oscillator | 12MHz SMD | C9002 | 1 | 
| C1 | Bulk capacitor | 10µF 0603 | C19702 | 2 | 
| C2 | Decoupling capacitor | 0.1µF 0603 | C14663 | 6 | 
| R1 | USB CC resistor | 5.1k 0603 | C23186 | 2 | 
| R2 | USB series resistor | 22Ω 0603 | C23345 | 2 | 
| D1 | Charge indicator LED | Red SMD LED | C2984265 | 
| J4 | Battery connector | JST-PH-2A-SMD | C160404 | 1 | 
| DISP | TFT Display | ST7789 SPI 240×240 | — | 1 | 
| BAT | Battery | 3.7V LiPo | — | 1 | 
| CHG | Battery charger | TP4056 module | C16581 | 1 | 
| BTN | Buttons  | Tactile switches | — | 6 |



## Features 

> MP3 playback from SD card

> Scrollable music list

> Basic UI on TFT screen

> Play / Pause / Next / Previous controls

> Volume adjustment

> Sleep mode

> Automatic next-track playback

> Aux Output

## Usage 

> Install Arduino IDE.

> Install the ESP32 board package.

> Install the required libraries:

> Adafruit VS1053

> Adafruit GFX

> Adafruit ST7789

> SPI

> SD

> Open the firmware file.

> Select your ESP32 board.

> Upload the code.

And you are good to go now ....

## Future Possible Updates

> Bt support

> Inbuilt Speaker

> Playlist

> Better Animations, etcetcetc.....

## Images

<img width="1651" height="899" alt="image" src="https://github.com/user-attachments/assets/a0c71bbf-84b9-460b-9f0f-2393c04b39b4" />


<img width="706" height="915" alt="image" src="https://github.com/user-attachments/assets/076a558c-8446-4371-b5b5-7d823b2a27b3" />

<img width="1050" height="841" alt="image" src="https://github.com/user-attachments/assets/f12bdcaa-5124-43f5-bf81-b4286e1eef95" />

<img width="1644" height="901" alt="image" src="https://github.com/user-attachments/assets/1ec491b5-f2d0-4b89-a8e9-6d74057b9992" />

<img width="1639" height="898" alt="image" src="https://github.com/user-attachments/assets/f149bda4-098f-494f-922f-5a45a657eb12" />


<img width="1531" height="906" alt="image" src="https://github.com/user-attachments/assets/e4ab9767-ee94-4fc3-9e51-f2c04680ea63" />

<img width="1114" height="980" alt="image" src="https://github.com/user-attachments/assets/be781f75-4ed0-4fca-8101-06911c55a1ac" />

<img width="1076" height="983" alt="image" src="https://github.com/user-attachments/assets/78e516de-3667-4e26-a941-0305a9199252" />

## JLCPCB

<img width="1131" height="478" alt="Capture" src="https://github.com/user-attachments/assets/699652d0-a9fa-4377-8a68-e6d6e1599c91" />

<img width="1178" height="584" alt="ESP32" src="https://github.com/user-attachments/assets/4deb283d-273a-4d75-94bf-227bfd411fd7" />

<img width="1125" height="704" alt="DISPLAY" src="https://github.com/user-attachments/assets/85662e3e-7ef2-4694-80a1-d7816124d8f5" />

I'll connect the display with wires as the orientation of diaply is differernt from the one it's in PCB and i can't change beacause I don't have my PC now amd am on Mobile

This was my most difficult and complex project till now and most timetaking so I just wan't to say that PCB won't feel easy at all if you are a begginer and also make sure u have enough knowledge to start .


TFT = 13 USD, ESP-32 = 7 USD, JLC = 67 

Total = 87 USD With Shipping 






