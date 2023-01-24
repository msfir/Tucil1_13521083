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
$ clone https://github.com/msfir/card24-solver.git
$ cd card24-solver
$ make
```
Hasil kompilasi akan disimpan di dalam folder `bin` dengan nama executable `24solver`
