# Arduino MotoGP Rider List Display

Proyek ini adalah aplikasi Arduino yang menggunakan remote infrared untuk menavigasi daftar nama pembalap MotoGP. Data ditampilkan pada LCD 16x2 I2C, dengan feedback visual melalui LED.

## Fitur

- **Navigasi Daftar**: Gunakan tombol remote IR untuk berpindah antar pembalap (next/previous).
- **Tampilan LCD**: Menampilkan nama tim dan pembalap pada layar LCD.
- **Feedback LED**: LED merah dan hijau memberikan indikasi visual.
- **Simulasi Wokwi**: Dapat dijalankan di simulator Wokwi untuk testing tanpa hardware fisik.

## Komponen Hardware

- Arduino Uno
- IR Receiver (TSOP4838 atau sejenis)
- LCD 1602 dengan modul I2C
- Remote IR (NEC protocol)
- 2x LED (Merah dan Hijau)
- 2x Resistor 1kΩ

## Wiring

- **IR Receiver**:
  - VCC → 5V
  - GND → GND
  - DAT → Pin 2

- **LCD I2C**:
  - VCC → 5V
  - GND → GND
  - SDA → A4
  - SCL → A5

- **LED Merah**:
  - Anoda → Pin 3 (melalui resistor 1kΩ)
  - Katoda → GND

- **LED Hijau**:
  - Anoda → Pin 5 (melalui resistor 1kΩ)
  - Katoda → GND

## Software Requirements

- PlatformIO IDE
- Arduino Framework
- Library Dependencies:
  - IRremote v4.7.1
  - LiquidCrystal_I2C v1.1.4

## Instalasi

1. Clone atau download repository ini.
2. Buka dengan PlatformIO IDE.
3. Install dependencies dengan menjalankan `pio lib install` di terminal PlatformIO.
4. Build project dengan `pio run`.
5. Upload ke Arduino Uno dengan `pio run --target upload`.

## Penggunaan

1. Upload kode ke Arduino Uno.
2. Hubungkan komponen sesuai wiring diagram.
3. Gunakan remote IR:
   - Tombol 1: Next pembalap
   - Tombol 2: Previous pembalap
4. LCD akan menampilkan nama tim di baris pertama dan nama pembalap di baris kedua.

## Simulasi Wokwi

Proyek ini dapat disimulasikan di Wokwi:

1. Buka [Wokwi](https://wokwi.com/).
2. Import diagram dari file `diagram.json`.
3. Jalankan simulasi.
4. Gunakan virtual IR remote untuk navigasi.

## Daftar Pembalap

- Ducati Lenovo: F. Bagnaia
- Repsol Honda: Marc Marquez
- Monster Yamaha: F. Quartararo
- Red Bull KTM: Brad Binder
- Aprilia Racing: Aleix Espargaro

## Troubleshooting

- Jika remote tidak merespons, periksa command code di Serial Monitor dan sesuaikan dengan remote Anda.
- Pastikan alamat I2C LCD benar (default 0x27).
- LED feedback dari IR receiver akan berkedip saat menerima sinyal.

## Lisensi

Proyek ini dibuat untuk tujuan edukasi.