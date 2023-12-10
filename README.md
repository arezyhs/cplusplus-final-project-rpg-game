# cplusplus-final-project-rpg-game

Proyek Akhir Pemrograman Dasar
End - Project

Tujuan
Membuat game teks berbasis RPG yang dapat dijalankan di terminal C++ atau sebagai file.exe.

Glosarium
Character (Karakter): Karakter fiksi yang dikendalikan oleh pemain di dalam permainan.
Player (Pemain): Pengguna aplikasi atau pemain dalam permainan.
Class (Kelas): Peran yang dapat dipilih oleh pemain, seperti warrior, archer, atau knight.
Stats (Statistik): Representasi data pemain yang ada di dalam permainan.
Health (Kesehatan): Poin darah pemain; jika ≤ 0, permainan berakhir atau kembali ke save game sebelumnya.
Damage (Kerusakan): Poin kekuatan pemain melawan musuh.
Defense (Pertahanan): Poin pertahanan pemain terhadap kerusakan musuh.
Level (Tingkat): Tingkatan level pemain.
Coins (Koin): Jumlah uang pemain yang dapat digunakan untuk upgrade.
Enemy (Musuh): Musuh yang harus dilawan oleh pemain untuk mendapatkan koin dan meningkatkan tingkat level.
Boss: Musuh besar yang muncul setiap 10 level.
Bagaimana Permainan Berfungsi?
Awal Permainan

Pemain memulai perjalanan dari awal atau memulai permainan baru. Pemain diminta untuk memasukkan username karakternya dan memilih class (misalnya: warrior, archer, knight). Setiap class memiliki nilai statistik tersendiri (health, defense, damage, dll).
Inti Permainan

Pemain memasuki bagian utama permainan di mana mereka dapat mengontrol karakter yang telah dibuat sebelumnya dengan beberapa opsi pilihan. Permainan berlanjut hingga karakter mati (health ≤ 0) atau pemain memilih opsi keluar (exit).
Opsi yang tersedia untuk pemain di inti permainan meliputi:
Explore (Jelajahi): Pemain dapat memilih untuk melawan musuh atau melarikan diri jika bertemu. Jika melawan, masuk ke mode pertarungan (combat/battle).
Heal (Obati): Pemain dapat berobat dengan membayar 50 koin.
Save (Simpan): Menyimpan progress pemain ke dalam file progress.txt.
Load (Muat): Melanjutkan progress pemain sebelumnya dengan membaca isi dari progress.txt.
Exit (Keluar): Keluar dari permainan.
Akhir Permainan

Jika pemain mencapai level 10, pemain akan dihadapkan pada boss terakhir yang harus dilawan.
Setelah pemain mengalahkan boss, permainan berakhir dan outro dimulai.
