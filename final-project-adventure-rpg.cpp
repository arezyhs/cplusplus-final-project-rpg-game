#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

/*
    created by
        1. arezyh.s
        2. shylniac
*/

// class player.
class Player {
public:
    string name;
    int level;
    int exp;
    int health;
    int attack;
    int coins;
    int defense;

    Player(const string& n) : name(n), level(1), exp(0), health(100), attack(10), coins(0), defense(0) {}

    // menampilkan stat karakter player selama bermain.
    void displayStats() const {
        system("cls");
        cout << name << "'s stats" << endl;
        cout << "Level  : " << level << endl;
        cout << "Exp    : " << exp << "/100" << endl;
        cout << "Health : " << health << endl;
        cout << "Damage : " << attack << "\t Defence : " << defense << endl;
        cout << "Coins  : " << coins << endl;
    }

    // fitur loadgame untuk kembali ke progress selanjutnya.
    void loadGame() {
        ifstream file("player_progress.txt");
        if (file.is_open()) {
            file >> level >> exp >> health >> attack >> coins;
            file.close();
            cout << "Game berhasil di-load" << endl;
        } else {
            cout << "Gagal membuka progress game!" << endl;
        }
    }
};

// class musuh, kalau mau buat musuh baru silahkan...
class Enemy {
public:
    string name;
    int health;
    int defense;
    int damage;
    int rewardCoins;
    int rewardExp;

    Enemy(const string& n, int h, int d, int dmg, int coins, int exp)
        : name(n), health(h), defense(d), damage(dmg), rewardCoins(coins), rewardExp(exp) {}

    virtual ~Enemy() {}

    virtual void displayIntro() const {
        cout << "Oh tidak! Anda berjumpa dengan " << name << "di jalan!" << endl;
    }
    
    virtual void attackPlayer(Player& player) const {
        player.health -= max(0, damage - player.defense); // memastikan damage tidak negatif < 0
        cout << name << " menyerangmu. Anda memiliki " << player.health << " darah tersisa." << endl;
    }
};

class GoblinEnemy : public Enemy {
public:
    GoblinEnemy() : Enemy("Goblin", 80, 1, 12, 5, 10) {}
    void displayIntro() const override {
        cout << "Oh tidak! Anda bertemu dengan " << name << " kecil" << endl;
    }
};

class WizardEnemy : public Enemy {
public:
    WizardEnemy() : Enemy("Wizard", 70, 0, 18, 8, 15) {}
    void displayIntro() const override {
        cout << "Oh no! A powerful " << name << " stands before you!" << endl;
    }
};

class DarkKnightEnemy : public Enemy {
public:
    DarkKnightEnemy() : Enemy("Corrupted Knight", 90, 5, 20, 13, 17) {}
    void displayIntro() const override {
        cout << "Anda bertemu dengan " << name << "! Dia menunggumu di tengah jalan..." << endl;
    }
};

class GiantEnemy : public Enemy {
public:
    GiantEnemy() : Enemy("Giant", 120, 2, 18, 15, 20) {}
    void displayIntro() const override {
        cout << "Jalan anda diblokir oleh " << name << " Raksasa" << endl;
    }
};

class FinalBossEnemy : public Enemy {
public:
    FinalBossEnemy() : Enemy("[BOSS] Dragon Lord", 500, 20, 30, 50, 100) {}
    void displayIntro() const override {
        cout << "Anda berada di level terakhir. Level 10." << endl;
        cout << "Di depan anda, ada musuh terakhir yang harus anda hadapi!" << endl;
        cout << "Dragon Lord!" << endl;
    }
};

// fungsi prototype
void combat(Player& player, Enemy& enemy);

// fungsi berobat dengan bayaran koin
void heal(Player& player) {
    if (player.coins < 35) {
        cout << "Koin anda tidak cukup!" << endl;
    } else {
        player.coins -= 35;
        player.health += 50;
        cout << "Darah bertambah sejumlah 50!" << endl;
    }
    system("pause");
}

// fitur explore dalam game dan hal yang terjadi ketika sedang berjalan.
void explore(Player& player) {
    system("cls");
    cout << "Anda melanjutkan perjalanan anda yang tak berujung..." << endl;

    // kemungkinan player bertemu dengan hal-hal selama bermain.
    int randomEnemyType = rand() % 5;
    Enemy* enemy;

    if (player.level != 10) { // jika tidak = level 10, lawan musuh biasa random.
    switch (randomEnemyType) {
        case 0:
            enemy = new GoblinEnemy();
            break;
        case 1:
            enemy = new WizardEnemy();
            break;
        case 2:
            enemy = new GiantEnemy();
            break;
        case 3:
            enemy = new DarkKnightEnemy();
            break;
        default:
            enemy = new GoblinEnemy();
    }

    enemy->displayIntro();
    combat(player, *enemy);

    delete enemy;
    } else { // kalau level 10, ketemu boss.
        enemy = new FinalBossEnemy();
        enemy->displayIntro();
        combat(player, *enemy);

        delete enemy;

        if (player.health > 0) {
            // Menang
            system("pause");
            cout << "Selamat! Anda berhasil mengalahkan penjaga dari hutan ini!" << endl;
            cout << "Anda telah menyelesaikan perjalanan Anda!" << endl;
            cout << "Terima kasih sudah bermain!" << endl;
            system("pause");
            exit(0);
        } else {
            // Kalah
            cout << "Kamu dikalahkan oleh Final Boss!" << endl;
            cout << "GAME OVER" << endl;
            exit(0);
        }
    }
}

// fitur pertempuran melawan musuh
void combat(Player& player, Enemy& enemy) {
    while (player.health > 0 && enemy.health > 0) {
        // giliran player.
        cout << "1. Attack" << endl;
        cout << "2. Run" << endl;
        int choice;
        cout << ">> Masukkan pilihan anda: ";
        cin >> choice;

        switch (choice) {
            case 1: // opsi player menyerang musuh yang dijumpa
                enemy.health -= player.attack;
                cout << "Anda menyerang " << enemy.name << ". Dia memiliki " << enemy.health << " darah tersisa!" << endl;
                break;
            case 2:
                // opsi apabila player mencoba lari, 50:50
                if (rand() % 2 == 0) {
                    cout << "Anda berhasil kabur dari musuh!" << endl;
                    return;
                } else {
                    cout << "Anda gagal kabur dari musuh!" << endl;
                }
                break;
            default:
                cout << "Pilih opsi yang sesuai (1/2)" << endl;
        }

        // giliran musuh,
        if (enemy.health >= 0) {
        enemy.attackPlayer(player);
        }
    }
        
        if (player.health > 0) {
            cout << "Anda mengalahkan " << enemy.name << "!" << endl;
            player.coins += enemy.rewardCoins;
            player.exp += enemy.rewardExp;

            if (player.exp >= 100) {
                player.level += 1;
                player.exp = 0;
                player.attack += 1;
            }

            } else {
                cout << "Kamu dikalahkan oleh " << enemy.name << endl;
                cout << "GAME OVER" << endl;
                exit(0);
        }
    }

// fungsi simpan progress
void save(Player& player) {
    ofstream file("player_progress.txt");
    if (file.is_open()) {
        file << player.level << endl;
        file << player.exp << endl;
        file << player.health << endl;
        file << player.attack << endl;
        file << player.coins << endl;
    file.close();
    cout << "Progress game anda telah disimpan!" << endl;
    } else {
        cout << "Progress game anda gagal disimpan!" << endl;
    }
    system("pause");
}

int main() {
    system("cls");
    srand(time(0));

    // selamat datang.
    cout << "************************************" << endl;
    cout << "\t GAME ADVENTURE RPG" << endl;
    cout << "\t\t LV10" << endl;
    cout << "************************************" << endl;
    system("pause");

    // masuk ke menu pembuatan karakter.
    string playerName;
    cout << "Masukkan nama karakter anda: ";
    getline(cin, playerName); system("cls");

    Player player(playerName);
    // memilih kelas karakter.
    int chooseRoles;
    do {
        cout << "1. Warrior" << endl;
        cout << "2. Archer" << endl;
        cout << "3. Knight" << endl;
        cout << "Pilih kelas karakter anda (1/2/3)" << endl;
        cout << ">> ";
        cin >> chooseRoles;
    } while (chooseRoles != 1 && chooseRoles != 2 && chooseRoles != 3 && chooseRoles != 9);

    if (chooseRoles == 1) { // warrior
        player.health = 100;
        player.attack = 20;
        player.defense = 5;
        cout << "Anda memilih Warrior" << endl; system("pause");
    } else if (chooseRoles == 2) { // archer
        player.health = 75;
        player.attack = 20;
        player.defense = 20;
        cout << "Anda memilih Archer" << endl; system("pause");
    } else if (chooseRoles == 3) { // knight
        player.health = 150;
        player.attack = 25;
        player.defense = 10;
        cout << "Anda memilih Knight" << endl; system("pause");
    } else if (chooseRoles == 9) { // cheat untuk test game ketika level 10
        player.health = 200;
        player.attack = 50;
        player.defense = 50;
        cout << "Cheat diaktifkan!" << endl; system("pause");
    };

    // pesan intro berjalan masuk ke game!
    system("cls");
    cout << "\tINTRO" << endl;
    string intro = "Anda adalah seorang Traveller yang sedang tersesat di jalan...\nUntuk dapat keluar dari sini, anda harus membunuh penjaga dari jalan ini. \nSelamat bermain!";
    for (char c : intro) {
        cout << c << flush;
        this_thread::sleep_for(50ms);
    }
    cout << endl;
    system("pause");

    // loop permainan.
    while (true) {
        system("cls");
        player.displayStats();

        // opsi pilihan bermain.
        cout << "1. Explore" << endl;
        cout << "2. Heal (35 coins)" << endl;
        cout << "3. Save" << endl;
        cout << "4. Load" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cout << ">> Masukkan pilihan anda (1/2/3/4/5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                explore(player);
                break;
            case 2:
                heal(player);
                break;
            case 3:
                save(player);
                break;
            case 4:
                player.loadGame();
                break;
            case 5:
                cout << "Terima kasih sudah bermain!" << endl;
                return 0;
            default:
                cout << "Pilih opsi yang sesuai (1/2/3/4/5)" << endl;
        }
    }
    return 0;
}