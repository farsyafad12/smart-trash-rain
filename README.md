# ♻️ Proyek Pemilah Sampah Basah dan Tidak Basah Otomatis

Sistem ini menggunakan **ESP32** untuk memilah jenis sampah berdasarkan kelembapan (basah atau tidak basah) menggunakan **Rain Sensor** dan **Infrared Sensor**. Hasil deteksi akan digerakkan oleh **Servo Motor**, serta ditampilkan melalui **lampu indikator** (Traffic Light) dan **buzzer** sebagai notifikasi suara.

---

## 🎯 Tujuan Proyek

Meningkatkan efisiensi pemilahan sampah di tahap awal dengan sistem otomatis, cocok untuk lingkungan rumah, sekolah, atau proyek edukasi berbasis IoT.

---

## 🛠️ Komponen yang Digunakan

| Komponen           | Jumlah | Keterangan                          |
|--------------------|--------|--------------------------------------|
| ESP32 Dev Board    | 1      | Mikrocontroller utama                |
| Infrared Sensor    | 1      | Untuk deteksi keberadaan sampah     |
| Rain Sensor (digital) | 1   | Untuk mendeteksi kelembapan sampah  |
| Servo Motor MG90S  | 1      | Menggerakkan pemilah sampah          |
| LED Merah          | 1      | Indikator standby                   |
| LED Kuning         | 1      | Indikator proses deteksi            |
| LED Hijau          | 1      | Indikator proses selesai            |
| Buzzer             | 1      | Notifikasi bunyi                    |
| Breadboard & Kabel Jumper | - | Untuk koneksi ( Secukupnya )                       |

---

## 🔌 Wiring (Pinout ESP32)

| Komponen      | Pin ESP32 |
|---------------|-----------|
| Infrared Sensor | D32 |
| Rain Sensor     | D33 |
| Servo Motor     | D25 |
| LED Merah       | D16 |
| LED Kuning      | D17 |
| LED Hijau       | D18 |
| Buzzer          | D19 |

---

## ⚙️ Cara Kerja Sistem

1. **Standby Mode**  
   - LED merah menyala menandakan sistem siap mendeteksi.

2. **Deteksi Sampah Masuk**  
   - Infrared sensor mendeteksi keberadaan sampah.
   - LED kuning menyala menandakan sistem sedang mendeteksi jenis sampah.

3. **Deteksi Basah atau Tidak**  
   - Rain sensor mendeteksi apakah sampah tersebut basah (nilai digital LOW) atau tidak basah (HIGH).

4. **Pemilahan Sampah**  
   - Jika basah → servo bergerak ke kiri (posisi 45°).  
   - Jika tidak basah → servo bergerak ke kanan (posisi 135°).

5. **Notifikasi Selesai**  
   - LED hijau menyala.
   - Buzzer berbunyi singkat sebagai tanda proses selesai.

6. **Reset Posisi**  
   - Servo kembali ke posisi tengah (90°).
   - LED kembali ke merah (standby).

---

## 📸 Sketsa Rangkaian

![Ilustrasi Rangkaian](image/1.png)

---

## 👨‍💻 Source Code

> File kode lengkap bisa kamu buka di `code.ino`  
> Jangan lupa install library `Servo.h` di Arduino IDE.

---

## 📢 Catatan Tambahan
- Gunakan **power supply 5V eksternal** untuk servo agar tidak drop.
- Sensor IR biasanya aktif saat **LOW** (logika terbalik).
- Pastikan sensor rain tidak terkena air berlebihan agar awet.

---

## 🤝 Kontribusi
Feel free buat modifikasi sistem ini jadi lebih advance! Bisa ditambah fitur:
- Kirim notifikasi ke Telegram
- Monitoring via web dashboard
- Deteksi 3 jenis sampah atau lebih

---

## 💡 License
Proyek ini bersifat open-source untuk edukasi dan eksperimen.

