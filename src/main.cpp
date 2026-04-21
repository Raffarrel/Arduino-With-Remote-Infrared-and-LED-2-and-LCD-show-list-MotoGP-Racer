#include <Arduino.h> // WAJIB untuk PlatformIO agar __FlashStringHelper terbaca
#include <IRremote.hpp> // Gunakan .hpp untuk library versi 4.x
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin IR Receiver
const int PIN_RECEIVER = 2;

// Struktur data
struct Pembalap {
  String tim;
  String nama;
};

Pembalap daftarPembalap[] = {
  {"Ducati Lenovo", "F. Bagnaia"},
  {"Repsol Honda", "Marc Marquez"},
  {"Monster Yamaha", "F. Quartararo"},
  {"Red Bull KTM", "Brad Binder"},
  {"Aprilia Racing", "Aleix Espargaro"}
};

int totalData = 5;
int indexSekarang = 0;

// DEKLARASI PROTOTYPE FUNGSI (Penting untuk PlatformIO)
void updateLCD();

void setup() {
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  
  // Memulai IR Receiver dengan cara versi 4.x
  IrReceiver.begin(PIN_RECEIVER, ENABLE_LED_FEEDBACK);
  
  updateLCD();
}

void loop() {
  if (IrReceiver.decode()) {
    // PlatformIO terkadang membaca command secara berbeda, 
    // pastikan command sesuai dengan remote yang digunakan
    uint16_t command = IrReceiver.decodedIRData.command;
    
    // Log ke serial untuk debug jika tombol tidak merespon
    Serial.print("Command diterima: ");
    Serial.println(command);

    if (command == 48) { // Tombol 1
      indexSekarang++;
      if (indexSekarang >= totalData) indexSekarang = 0;
      updateLCD();
    } 
    else if (command == 24) { // Tombol 2
      indexSekarang--;
      if (indexSekarang < 0) indexSekarang = totalData - 1;
      updateLCD();
    }

    IrReceiver.resume(); 
  }
}

// Implementasi fungsi
void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T: ");
  lcd.print(daftarPembalap[indexSekarang].tim);
  
  lcd.setCursor(0, 1);
  lcd.print(daftarPembalap[indexSekarang].nama);
}