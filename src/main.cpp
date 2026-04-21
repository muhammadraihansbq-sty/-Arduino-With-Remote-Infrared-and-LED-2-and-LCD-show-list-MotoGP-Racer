#include <Arduino.h>
#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>

// --- Konfigurasi Pin ---
const int RECV_PIN = 2;

// --- Nilai Command Tombol Remote ---
#define CMD_NEXT 0x30     // Tombol "1" (Maju: Tim + Nama)
#define CMD_PREV 0x18     // Tombol "2" (Mundur: Nama Saja)

LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- Data Pembalap MotoGP ---
String tim[] = {
  "Ducati Lenovo", 
  "Repsol Honda", 
  "Monster Yamaha", 
  "Red Bull KTM", 
  "Aprilia Racing"
};

String pembalap[] = {
  "F. Bagnaia", 
  "Marc Marquez", 
  "F. Quartararo", 
  "Brad Binder", 
  "Aleix Espargaro"
};

int totalData = 5;
int currentIndex = 0; 

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Sistem Ready");
  lcd.setCursor(0, 1);
  lcd.print("Tekan 1 atau 2");
}

void loop() {
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;

    // --- Tombol 1: Maju & Tampilkan Tim + Pembalap ---
    if (command == CMD_NEXT) {
      currentIndex++;
      if (currentIndex >= totalData) currentIndex = 0;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(tim[currentIndex]);    // Baris 1: Nama Tim
      lcd.setCursor(0, 1);
      lcd.print(pembalap[currentIndex]); // Baris 2: Nama Pembalap
    }
    
    // --- Tombol 2: Mundur & Tampilkan Nama Pembalap Saja ---
    else if (command == CMD_PREV) {
      currentIndex--;
      if (currentIndex < 0) currentIndex = totalData - 1;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(pembalap[currentIndex]); // Baris 1: Nama Pembalap Saja
      // Baris 2 dikosongkan sesuai permintaan
    }

    IrReceiver.resume(); 
  }
}