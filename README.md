# CyberSter

Cyberster is a mp3 portable MP3 player using different electronic modules. It can play music from an SD card and send audio through AUX or Bluetooth. A screen is used to show the menu and song information. The device also uses a Type-C port for power and transferring music files.

## BOM 

## Core BOM (LCSC Parts for JLCPCB Assembly)

| Ref | Component | Manufacturer Part | LCSC Part # | Qty | Function |
|-----|-----------|------------------|-------------|-----|----------|
| U1 | WiFi + Bluetooth module | ESP32-S3-WROOM-1-N16R8 | C2913202 | 1 | Main MCU |
| U2 | MP3 decoder IC | VS1053B-L | C13316 | 1 | MP3 audio decoding |
| U3 | Li-ion charger IC | TP4056 | C16581 | 1 | Battery charging |
| U4 | 3.3V LDO regulator | AMS1117-3.3 | C6186 | 1 | 3.3V supply |
| J1 | USB Type-C connector | TYPE-C-31-M-12 | C165948 | 1 | USB data + power |
| J2 | MicroSD card socket | MICRO-SD-DM3D-SF | C91145 | 1 | Music storage |
| J3 | 3.5mm audio jack | PJ-320A | C128188 | 1 | AUX output |
| J4 | Battery connector | JST-PH-2A-SMD | C160404 | 1 | LiPo battery |
| J5 | Pin header for TFT | 2.54mm 1×8 header | C49257 | 1 | TFT connection |

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

nd ur good to go now ....

## Future Possible Updates

> Bt support

> Inbuilt Speaker

> Playlist

> Better Animations, etcetcetc.....

## Images

<img width="1535" height="898" alt="image" src="https://github.com/user-attachments/assets/3c730610-5af8-4006-a271-a77e10744079" />

<img width="749" height="913" alt="image" src="https://github.com/user-attachments/assets/9103c617-fdbe-401d-bd9b-b25f4bcea79b" />

<img width="1104" height="916" alt="image" src="https://github.com/user-attachments/assets/793188d7-f49b-4fdb-901f-a5d9e6c84e6b" />

<img width="1536" height="896" alt="image" src="https://github.com/user-attachments/assets/6503a1f1-086c-4802-863e-c8f4a82134d2" />

<img width="1538" height="904" alt="image" src="https://github.com/user-attachments/assets/7ee44092-b52c-4bf2-8a27-69f521a9606d" />

<img width="1531" height="906" alt="image" src="https://github.com/user-attachments/assets/e4ab9767-ee94-4fc3-9e51-f2c04680ea63" />

<img width="1114" height="980" alt="image" src="https://github.com/user-attachments/assets/be781f75-4ed0-4fca-8101-06911c55a1ac" />

<img width="1076" height="983" alt="image" src="https://github.com/user-attachments/assets/78e516de-3667-4e26-a941-0305a9199252" />

## JLCPCB

<img width="1131" height="478" alt="Capture" src="https://github.com/user-attachments/assets/699652d0-a9fa-4377-8a68-e6d6e1599c91" />

<img width="1178" height="584" alt="ESP32" src="https://github.com/user-attachments/assets/4deb283d-273a-4d75-94bf-227bfd411fd7" />

<img width="1125" height="704" alt="DISPLAY" src="https://github.com/user-attachments/assets/85662e3e-7ef2-4694-80a1-d7816124d8f5" />

Total = 85 USD





