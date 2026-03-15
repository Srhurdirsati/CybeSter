#include <SPI.h>
#include <SD.h>
#include <Adafruit_VS1053.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

// VS1053
#define VS1053_CS 5
#define VS1053_DCS 6
#define VS1053_DREQ 7
#define VS1053_RST 8

// SD
#define SD_CS 10

// TFT
#define TFT_CS 9
#define TFT_DC 4
#define TFT_RST 3

// Buttons
#define BTN_PLAY 14
#define BTN_NEXT 15
#define BTN_PREV 16
#define BTN_UP 17
#define BTN_DOWN 18
#define BTN_MENU 21

// Battery
#define BAT_ADC 1

#define MAX_SONGS 200
#define SCREEN_W 240
#define SCREEN_H 240

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

Adafruit_VS1053_FilePlayer player =
Adafruit_VS1053_FilePlayer(
VS1053_RST,
VS1053_CS,
VS1053_DCS,
VS1053_DREQ,
SD_CS
);

String songList[MAX_SONGS];
int songCount = 0;

int selected = 0;
int currentSong = -1;

bool playing = false;

int volume = 20;

int scrollOffset = 0;

unsigned long lastUI = 0;

void scanFiles(File dir) {

while(true){

File entry = dir.openNextFile();

if(!entry) break;

String name = entry.name();

if(name.endsWith(".MP3") || name.endsWith(".mp3")){

songList[songCount++] = name;

}

entry.close();

}

}

float readBattery(){

int raw = analogRead(BAT_ADC);

float voltage = raw * (3.3 / 4095.0) * 2;

return voltage;

}

int batteryPercent(){

float v = readBattery();

if(v >= 4.2) return 100;
if(v >= 4.0) return 85;
if(v >= 3.8) return 60;
if(v >= 3.6) return 40;
if(v >= 3.4) return 20;
return 5;

}

void drawHeader(){

tft.fillRect(0,0,240,30,ST77XX_BLUE);

tft.setCursor(5,8);
tft.setTextColor(ST77XX_WHITE);
tft.setTextSize(2);
tft.print("MP3 Player");

int bat = batteryPercent();

tft.setCursor(180,8);
tft.print(bat);
tft.print("%");

}

void drawList(){

tft.fillRect(0,30,240,170,ST77XX_BLACK);

for(int i=0;i<6;i++){

int index = scrollOffset + i;

if(index >= songCount) break;

if(index == selected){

tft.fillRect(0,30 + i*28,240,28,ST77XX_GREEN);

tft.setTextColor(ST77XX_BLACK);

}else{

tft.setTextColor(ST77XX_WHITE);

}

tft.setCursor(10,40 + i*28);

tft.print(songList[index]);

}

}

void drawPlayer(){

tft.fillRect(0,30,240,170,ST77XX_BLACK);

tft.setCursor(10,40);
tft.print("Playing:");

tft.setCursor(10,70);
tft.print(songList[currentSong]);

}

void drawProgress(){

if(!player.playingMusic) return;

uint32_t pos = player.currentPosition();
uint32_t len = player.playingMusicSize;

if(len == 0) return;

int w = (pos * 200) / len;

tft.drawRect(20,200,200,10,ST77XX_WHITE);

tft.fillRect(20,200,w,10,ST77XX_GREEN);

}

void playSelected(){

currentSong = selected;

player.stopPlaying();

player.startPlayingFile(songList[currentSong].c_str());

playing = true;

drawPlayer();

}

void handleButtons(){

if(!digitalRead(BTN_UP)){

selected--;

if(selected < 0) selected = 0;

if(selected < scrollOffset) scrollOffset--;

drawList();

delay(150);

}

if(!digitalRead(BTN_DOWN)){

selected++;

if(selected >= songCount) selected = songCount -1;

if(selected > scrollOffset + 5) scrollOffset++;

drawList();

delay(150);

}

if(!digitalRead(BTN_PLAY)){

if(currentSong == selected){

if(playing){

player.pausePlaying(true);

playing=false;

}else{

player.pausePlaying(false);

playing=true;

}

}else{

playSelected();

}

delay(200);

}

if(!digitalRead(BTN_NEXT)){

selected++;

if(selected >= songCount) selected = 0;

playSelected();

delay(200);

}

if(!digitalRead(BTN_PREV)){

selected--;

if(selected < 0) selected = songCount-1;

playSelected();

delay(200);

}

}

void sleepMode(){

player.stopPlaying();

tft.fillScreen(ST77XX_BLACK);

tft.setCursor(60,120);
tft.print("Sleeping");

delay(2000);

esp_deep_sleep_start();

}

void setup(){

Serial.begin(115200);

pinMode(BTN_PLAY,INPUT_PULLUP);
pinMode(BTN_NEXT,INPUT_PULLUP);
pinMode(BTN_PREV,INPUT_PULLUP);
pinMode(BTN_UP,INPUT_PULLUP);
pinMode(BTN_DOWN,INPUT_PULLUP);
pinMode(BTN_MENU,INPUT_PULLUP);

tft.init(240,240);
tft.setRotation(2);

if(!SD.begin(SD_CS)){

tft.print("SD Error");

while(1);

}

if(!player.begin()){

tft.print("VS1053 Error");

while(1);

}

player.setVolume(volume,volume);

scanFiles(SD.open("/"));

drawHeader();
drawList();

}

void loop(){

handleButtons();

if(millis() - lastUI > 300){

drawProgress();

drawHeader();

lastUI = millis();

}

if(!player.playingMusic && playing){

selected++;

if(selected >= songCount) selected = 0;

playSelected();

}

if(!digitalRead(BTN_MENU)){

sleepMode();

}

}
