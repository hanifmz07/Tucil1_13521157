# Tugas Kecil 1 Strategi Algoritma (Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force)
## Overview
Permainan kartu 24 adalah permainan kartu aritmatika dengan tujuan mencari cara untuk mengubah 4 buah angka random sehingga mendapatkan hasil akhir sejumlah 24. Permainan ini menarik cukup banyak peminat dikarenakan dapat meningkatkan kemampuan berhitung serta mengasah otak agar dapat berpikir dengan cepat dan akurat. Permainan Kartu 24 biasa dimainkan dengan menggunakan kartu remi. Kartu remi terdiri dari 52 kartu yang terbagi menjadi empat suit (sekop, hati, keriting, dan wajik) yang masing-masing terdiri dari 13 kartu (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). Yang perlu diperhatikan hanyalah nilai kartu yang didapat (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). As bernilai 1, Jack bernilai 11, Queen bernilai 12, King bernilai 13, sedangkan kartu bilangan memiliki nilai dari bilangan itu sendiri. Pada awal permainan moderator atau salah satu pemain mengambil 4 kartu dari dek yang sudah dikocok secara random. Permainan berakhir ketika pemain berhasil menemukan solusi untuk membuat kumpulan nilainya menjadi 24. Pengubahan nilai tersebut dapat dilakukan menggunakan operasi dasar matematika penjumlahan (+), pengurangan (-), perkalian (×), divisi (/) dan tanda kurung ( () ). Tiap kartu harus digunakan tepat sekali dan urutan penggunaannya bebas.

## Features
- Menerima input 4 buah elemen dengan elemen yang dibolehkan adalah A, J, K, Q, dan digit 2-10.
- Pemilihan 4 elemen secara acak
- Menampilkan jumlah solusi yang ditemukan
- Menampilkan seluruh ekspresi yang merupakan solusi
- Menampilkan waktu yang dibutuhkan dalam proses pencarian solusi
- Solusi dapat disimpan dalam bentuk file .txt

## Requirements
- Dibuat menggunakan bahasa C++
- Program berhasil dijalankan di **OS Windows 11** dan dicompile dengan **g++ versi 12.1.0**

## How to run
Pastikan bahwa terminal berada pada path terluar dari repository.

Untuk mengcompile program, gunakan command berikut:
```
gcc src/24game.cpp src/main.cpp -lstdc++ -o bin/main
```

Untuk menjalankan program, jalankan binary file yang telah dihasilkan dengan menggunakan command berikut:
```
bin/main
```

## Author
Nama: Hanif Muhammad Zhafran

NIM: 13521157

Kelas: K1