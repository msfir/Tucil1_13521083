# Tugas Kecil 1: Penyelesaian Permainan Kartu 24 dengan Algoritma _Brute Force_

## Deskripsi Program
Program ini dibuat untuk menyelesaikan permainan kartu 24. Program akan meminta input atau men-_generate_ bilangan berdasarkan kartu remi, yaitu A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, dan K. Kartu berupa huruf akan dikonversi menjadi bilangan yang bersesuaian. Tujuan dari permainan ini adalah untuk membentuk sebuah ekspresi matematika dari kombinasi 4 kartu sehingga hasil evaluasinya sama dengan 24. Operasi matematika yang diizinkan adalah penjumlahan (+), pengurangan (-), perkalian (×), pembagian (/), dan tanda kurung untuk pengelompokan. Program ini akan mencari semua ekspresi matematika yang mungkin dibentuk dari kombinasi 4 kartu tersebut secara _brute force_.

## Instalasi dan Persyaratan Program
### Persyaratan (Requirements)
- OS Linux
- gcc ([GNU Compiler Collection](https://gcc.gnu.org/))
- [GNU make](https://www.gnu.org/software/make)
### Langkah Instalasi
```shell
$ git clone https://github.com/msfir/card24-solver.git
$ cd card24-solver
$ make
```
Hasil kompilasi akan disimpan di dalam folder `bin` dengan nama executable `24solver`

## Cara Penggunaan
Setelah menjalankan executable, user akan disediakan dua buah opsi:
1. Memasukkan kombinasi 4 kartu secara manual
2. Men-_generate_ kombinasi 4 kartu secara acak

Untuk input manual, user harus memasukkan 4 kartu yang valid yang dipisahkan dengan <kbd>Enter</kbd> maupun <kbd>Space</kbd>. Kartu-kartu yang valid adalah A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, dan K. Jika user memasukkan satu pun kartu yang tidak valid, maka program akan mencetak error dan user akan diminta untuk mengulang input yang valid.

Program akan mencari semua solusi berdasarkan input yang valid. Setelah semua solusi dicetak di terminal, user akan diberikan opsi untuk menyimpan solusi tersebut ke dalam sebuah file. User akan ditanyai dengan pertanyaan berikut.
```shell
Apakah Anda ingin menyimpan solusi? (y/[n])
```
Secara default, `n` merupakan jawaban pertanyaan tersebut (ditandai dengan kurung siku). Jika user menjawab dengan `y`, maka selanjutnya user akan diminta menginput nama file untuk menyimpan solusi. Pada OS Linux, nama file tidak memilki batasan apapun kecuali penggunaan karakter _slash_ (/) karena karakter tersebut merupakan _path separator_.

<p align=right><sup>Dibuat oleh Moch. Sofyan Firdaus (13521083)</sup></p>
