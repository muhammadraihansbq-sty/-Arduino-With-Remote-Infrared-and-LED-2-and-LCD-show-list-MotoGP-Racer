# 🏍️ Arduino IR Remote MotoGP Rider Display

Proyek Arduino yang menampilkan daftar nama pembalap dan tim MotoGP pada LCD I2C menggunakan remote kontrol infrared. Proyek ini dapat dijalankan dan disimulasikan menggunakan **WOKWI Online Simulator**.

---

## 📋 Deskripsi Proyek

Sistem ini memungkinkan pengguna untuk menavigasi melalui daftar pembalap dan tim MotoGP menggunakan remote control infrared. Data ditampilkan pada layar LCD 16x2 dengan fitur navigasi maju dan mundur.

### Fitur Utama:
- ✅ Navigasi pembalap MotoGP menggunakan remote infrared
- ✅ Tampilan tim dan nama pembalap pada LCD I2C
- ✅ Tombol maju (1) untuk menampilkan tim + pembalap
- ✅ Tombol mundur (2) untuk menampilkan hanya nama pembalap
- ✅ Otomatis kembali ke awal ketika mencapai akhir daftar
- ✅ Kompatibel dengan WOKWI Online Simulator
- ✅ Feedback LED pada penerimaan sinyal IR

---

## 🛠️ Komponen dan Library

### Hardware yang Digunakan:
- **Arduino Uno**
- **IR Receiver Module** (connected to pin 2)
- **LCD I2C 16x2** (address: 0x27)
- **Infrared Remote Control**

### Library yang Digunakan:
| Library | Versi | Fungsi |
|---------|-------|--------|
| IRremote | ^4.7.1 | Membaca sinyal dari remote infrared |
| LiquidCrystal_I2C | ^1.1.4 | Mengontrol LCD I2C display |

---

## 🚀 Cara Menggunakan

### Kontrol Remote:
| Tombol | Fungsi | Tampilan |
|--------|--------|---------|
| **1** (Next) | Maju ke pembalap berikutnya | Baris 1: Nama Tim<br>Baris 2: Nama Pembalap |
| **2** (Prev) | Mundur ke pembalap sebelumnya | Baris 1: Nama Pembalap Saja<br>Baris 2: Kosong |

### Daftar Pembalap MotoGP:
1. F. Bagnaia - Ducati Lenovo
2. Marc Marquez - Repsol Honda
3. F. Quartararo - Monster Yamaha
4. Brad Binder - Red Bull KTM
5. Aleix Espargaro - Aprilia Racing

---

## 📁 Struktur Proyek

```
Projek Arduino dengan Remote Infrared dan LED 2 dan LCD...
├── platformio.ini          # Konfigurasi PlatformIO
├── Readme.md              # File dokumentasi (file ini)
├── diagram.json           # Diagram WOKWI
├── wokwi.toml            # Konfigurasi WOKWI
├── src/
│   └── main.cpp          # Kode utama Arduino
├── include/
│   └── README
├── lib/
│   └── README
└── test/
    └── README
```

---

## 💻 Setup dan Instalasi

### Persiapan Lokal:
1. **Install PlatformIO** di VS Code atau gunakan CLI
2. **Clone atau download** project ini
3. **Buka folder project** di VS Code dengan PlatformIO

### Instalasi Library:
Library akan otomatis terinstall saat build project karena sudah didefinisikan di `platformio.ini`:

```ini
lib_deps = 
    z3t0/IRremote@^4.7.1
    marcoschwartz/LiquidCrystal_I2C@^1.1.4
```

### Build dan Upload:
```bash
# Menggunakan PlatformIO CLI
pio run -e uno                    # Build
pio run -e uno --target upload    # Upload ke board

# Atau dari VS Code
# Klik tombol "Upload" di bottom bar
```

---

## 🎮 Menggunakan WOKWI Simulator

1. **Buka** [WOKWI](https://wokwi.com/)
2. **Import project** atau buat diagram baru
3. **Salin file `diagram.json`** dari proyek ini
4. **Jalankan simulasi** dengan tombol Play
5. **Gunakan remote virtual** untuk mengirim sinyal IR

### Konfigurasi WOKWI:
- Lihat file `wokwi.toml` untuk konfigurasi simulator

---

## 📝 Penjelasan Kode

### Konfigurasi Pin:
```cpp
const int RECV_PIN = 2;  // Pin IR receiver
```

### Command Remote:
```cpp
#define CMD_NEXT 0x30   // Tombol "1" (Maju)
#define CMD_PREV 0x18   // Tombol "2" (Mundur)
```

### Setup:
- Inisialisasi Serial, IR Receiver, dan LCD
- Menampilkan pesan siap di LCD

### Loop:
- Membaca sinyal IR dari remote
- Menavigasi daftar pembalap
- Update tampilan LCD sesuai tombol yang ditekan

---

## 🔧 Troubleshooting

| Masalah | Solusi |
|---------|--------|
| LCD tidak menampilkan apa-apa | Periksa address I2C (default: 0x27), ubah jika diperlukan |
| Remote tidak merespons | Pastikan IR receiver terhubung ke pin 2 |
| Library tidak ditemukan | Jalankan `pio lib install` atau rebuild project |
| Karakter tidak jelas | Sesuaikan nilai contrast pada LCD atau periksa koneksi I2C |

---

## 📚 Referensi dan Sumber

- **IRremote Library**: https://github.com/Arduino-IRremote/Arduino-IRremote
- **LiquidCrystal_I2C Library**: https://github.com/marcoschwartz/LiquidCrystal_I2C
- **WOKWI Simulator**: https://wokwi.com/
- **PlatformIO Docs**: https://docs.platformio.org/
- **Arduino Uno Reference**: https://docs.arduino.cc/hardware/uno-rev3

---

## 📄 Lisensi

Proyek ini bebas digunakan dan dimodifikasi untuk keperluan pribadi maupun komersial.

---

## 👨‍💻 Developer

Dibuat dengan ❤️ menggunakan Arduino, PlatformIO, dan WOKWI Simulator

**Terakhir diperbarui:** 8 Mei 2026