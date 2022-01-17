#include <iostream>
#include <cctype>
#include <stdlib.h>


using namespace std;


//deklasrasi array, struct dan fungsi prototype
char papanGame[3][3] = {{'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}};


struct Player
{
    int menuChoice;
    int choice;
    int turn = 1;
    char mark;
    string name[2] = {{"Player 1"}, {"Player 2"}};
};

int cekMenang();
void gambarPapan(string name);
void gameLogic(Player player);

//fungsi main
int main(void)
{
    //deklasrasi variable local di fungsi main
    Player player;
    char conf;

    //tampilan menu utama
    cout << "\n\nTic-Tac-Toe\n\n";
    cout << "1) Play\n";
    cout << "2) About\n";
    cout << "3) Exit\n";
    cin >> player.menuChoice;

    //tampilan menu setelah pemilihan menu
    switch (player.menuChoice)
    {
    //case 1 mulai permainan
    case 1:
        do
        {
            system("cls");
            //for loop untuk pemasukan nama Player 1 dan Player 2
            for (int i = 0; i <= 1; i++)
            {
                cout << "\n\n\tEnter Your Name\n\n";
                cout << "Player " << i + 1 << " : ";
                cin >> player.name[i];
                system("cls");
            }

            cout << "\n\n";
            //mengkonfirmasi apakah nama yang diinputkan sudah benar atau belum
            for (int i = 0; i <= 1; i++)
            {
                cout << "Player " << i + 1 << " : " << player.name[i] << "\n";
            }
            cout << "Submit ? [y/n] : ";
            cin >> conf;
            conf = toupper(conf);
        } while (conf != 'Y');

        conf = 'N';

        do
        {
            //memanggil fungsi gameLogic untuk memulai permainan
            gameLogic(player);
            //menampilkan pilihan setelah permainan selesai, Player dapat bermain ulang atau kembali ke menu utama
            cout << "\nPlay Again[P], Home[H] : ";
            cin >> conf;
            conf = toupper(conf);
            //jika player ingin bermain kembali for loop di bawah akan mereset array papanGame menjadi keadaan semula. 
            if (conf == 'P')
            {
            //49 ASCII untuk angka 1 
            int i = 49;
                for (int row = 0; row < 3; row++){
                    for (int col = 0; col < 3; col++){
                        papanGame[row][col] = i;
                        i++;
                        }
                }
            }
        } while (conf != 'H');
        system("cls");
        main();
        break;
    case 2:
        // about page
        
        system("cls");
        cout << "\t\tTic-Tac-Toe\n\n"
             << "\t\tVersion 1.3\n\n"
             << "Copyright c 2021 Kelompok 7.\nAll Right Reserved\n\n"
             << "Press Enter to return..";
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 3:
        //exit
        break;
    default:
        cout << "Error : Please enter a valid number... \n";
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    }
    return 0;
}

// Fungsi Untuk Menggambar papan
void gambarPapan(string name)
{
    system("cls");
    cout << "\n\n\tChoose a number between 1 and 9\n\n";

    for (int r = 0; r < 3; r++)
    {
        if (r == 0)
        {
            cout << "\n\n\t\b\b\b" << name
                 << "\n\n";
            cout << "     |     |     \n";
        }
        for (int c = 0; c < 3; c++)
        {
            cout << "  " << papanGame[r][c] << "  ";
            if (c != 2)
            {
                cout << "|";
            }
        }
        cout << "\n";
        if (r != 2)
        {
            cout << "_____|_____|_____" << endl;
            cout << "     |     |     " << endl;
        }
    }
    cout << "     |     |     \n";
}

//fungsi logika dari permainan
void gameLogic(Player player)
{
    //deklasrasi variable lokal
    int winOrDraw;

    do
    {
        /* code */
        //pemanggilan fungsi gambarPapan dengan memasukan argument berupa playerTurn , untuk menampilkan nama player yang sedang medapatkan giliran bermain  
        gambarPapan(player.name[(player.turn % 2) ? 0 : 1] + "'s Turn");
        player.turn = (player.turn % 2);
        player.mark = ((player.turn % 2) == 1) ? 'X' : 'O';
        cin >> player.choice;
        //kondisi if di bawah akan memastikan apakah papan game kosong dan dapat di isi oleh X atau O
        //row 1
        if (player.choice == 1 && papanGame[0][0] == '1')
        {
            papanGame[0][0] = player.mark;
        }
        else if (player.choice == 2 && papanGame[0][1] == '2')
        {
            papanGame[0][1] = player.mark;
        }
        else if (player.choice == 3 && papanGame[0][2] == '3')
        {
            papanGame[0][2] = player.mark;
        } //row 2
        else if (player.choice == 4 && papanGame[1][0] == '4')
        {
            papanGame[1][0] = player.mark;
        }
        else if (player.choice == 5 && papanGame[1][1] == '5')
        {
            papanGame[1][1] = player.mark;
        }
        else if (player.choice == 6 && papanGame[1][2] == '6')
        {
            papanGame[1][2] = player.mark;
        } //row 3
        else if (player.choice == 7 && papanGame[2][0] == '7')
        {
            papanGame[2][0] = player.mark;
        }
        else if (player.choice == 8 && papanGame[2][1] == '8')
        {
            papanGame[2][1] = player.mark;
        }
        else if (player.choice == 9 && papanGame[2][2] == '9')
        {
            papanGame[2][2] = player.mark;
        }

        else
        {
            cout << "Invalid move ";
            player.turn--;
            cin.ignore();
            cin.get();
        }
        winOrDraw = cekMenang();
        player.turn++;

    } while (winOrDraw == 0);
    if (cekMenang() == 1)
    {
        gambarPapan(player.name[(player.turn % 2)] + " Won");
    }
    else if (cekMenang() == 2)
    {
        gambarPapan("  Draw");
    }
}

/**
 * fungsi cekMenang akan mengecek berkala apakah status menang dan seri terjadi dan mengembalikan nilai integer sesuai dengan statusnya,
 * jika ada player yg menang fungsi mereturn 1, jika terjadi seri fungsi akan mereturn 2. jika tidak ada yang terjadi fungsi akan mereturn 0.
 */
int cekMenang()
{
    // vertikal
    for (int row = 0; row < 3; row++)
    {
        if (papanGame[row][0] == papanGame[row][1] && papanGame[row][0] == papanGame[row][2])
        {
            return 1;
        }
    }
    // horizontal
    for (int col = 0; col < 3; col++)
    {
        if (papanGame[0][col] == papanGame[1][col] && papanGame[2][col] == papanGame[0][col])
        {
            return 1;
        }
    }
    // diagonal miring kanan
    if (papanGame[0][0] == papanGame[1][1] && papanGame[2][2] == papanGame[0][0])
    {
        return 1;
    }

    // diagonal miring kiri
    if (papanGame[2][0] == papanGame[1][1] && papanGame[0][2] == papanGame[2][0])
    {
        return 1;
    }

    // draw
    if (papanGame[0][0] != '1' &&
        papanGame[0][1] != '2' &&
        papanGame[0][2] != '3' &&
        papanGame[1][0] != '4' &&
        papanGame[1][1] != '5' &&
        papanGame[1][2] != '6' &&
        papanGame[2][0] != '7' &&
        papanGame[2][1] != '8' &&
        papanGame[2][2] != '9')
    {
        return 2;
    }

    return 0;
}