# Student Data Management with Singly Linked List (C Language)

![GitHub repo size](https://img.shields.io/github/repo-size/ahmadtsanims/Student-Data-Management?style=for-the-badge)
![GitHub last commit](https://img.shields.io/github/last-commit/ahmadtsanims/Student-Data-Management?style=for-the-badge)

Program berbasis *Command Line Interface* (CLI) ini dibuat menggunakan bahasa C untuk mengelola data mahasiswa. Program ini mengimplementasikan struktur data **Singly Linked List** untuk menyimpan data secara dinamis dan algoritma **Bubble Sort** untuk mengurutkan data berdasarkan IPK tertinggi tanpa merusak urutan asli pada linked list.

## 🚀 Fitur Utama
* **Insert Data (Insert Akhir):** Menambahkan data mahasiswa baru (NRP, Nama, IPK) ke bagian akhir list.
* **Tampilkan Data:** Menampilkan semua data mahasiswa sesuai dengan urutan waktu input (urutan asli).
* **Tampilkan IPK Tertinggi:** Mengurutkan dan menampilkan data mahasiswa dari IPK terbesar ke terkecil (*descending*) menggunakan metode penyalinan pointer ke array (aman untuk struktur linked list asli).

---

## 🛠️ Penjelasan Struktur Kode

Program ini dibagi menjadi beberapa bagian penting:

### 1. Struktur Data (`struct`)
* `DataMahasiswa`: Menyimpan atribut entitas mahasiswa seperti `nrp` (string), `nama` (string), dan `ipk` (float).
* `Node`: Representasi node dalam Linked List yang membungkus `DataMahasiswa` dan pointer `*next` untuk menunjuk ke node selanjutnya.

### 2. Alur Logika Fungsi
* **`insertAkhir()`**: Melakukan alokasi memori dinamis (`malloc`) untuk node baru, mengisi datanya, lalu mencarinya hingga ujung linked list untuk ditautkan di akhir.
* **`tampilNormal()`**: Melakukan *traversal* (penelusuran) dari `head` hingga node terakhir untuk mencetak data secara rapi.
* **`tampilByIPK()`**: 
  1. Menghitung jumlah node yang ada.
  2. Membuat array of pointers (`Node **arr`) untuk menampung alamat dari setiap node.
  3. Mengurutkan array pointer tersebut menggunakan **Bubble Sort** secara *descending* berdasarkan nilai IPK.
  4. Mencetak hasil urutan tanpa mengubah struktur pointer `next` asli pada linked list.

### 3. Menu Utama (`main`)
Menggunakan loop `do-while` dan percabangan `switch-case` untuk menyajikan menu interaktif kepada pengguna.

---

## 💻 Cara Menjalankan

1. Clone repositori ini:
   ```bash
   git clone [https://github.com/username-kamu/nama-repo.git](https://github.com/username-kamu/nama-repo.git)
