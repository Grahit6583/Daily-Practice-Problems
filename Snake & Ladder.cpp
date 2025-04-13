#include<bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <conio.h>
using namespace std;

class Player{
    public:
        string name;
        int position;
};

class Snake{
    public:
        int head;
        int tail;
};

class Ladder{
    public:
        int bottom;
        int top;
};

void display(string name, int position){
    cout<<name<<" Position : "<<position<<"\n";
    return;
}

int roll_dice(){
    cout << "Rolling dice";
    for (int i = 0; i < 3; i++) {
        cout << ".";
        fflush(stdout);
        sleep(1);  // For Windows, you might use Sleep(1000);
    }
    cout << "\n";
    return (rand() % 6) + 1;
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    srand(static_cast<unsigned int>(time(0)));
    int n;
    cin>>n;

    vector<Player> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i].name;
        arr[i].position = -1;
    }

    vector<Snake> snake(5);
    vector<Ladder> ladder(5);

    snake[0].head = 17;
    snake[0].tail = 7;
    snake[1].head = 62;
    snake[1].tail = 19;
    snake[2].head = 87;
    snake[2].tail = 36;
    snake[3].head = 92;
    snake[3].tail = 73;
    snake[4].head = 98;
    snake[4].tail = 79;

    ladder[0].bottom = 4;
    ladder[0].top = 14;
    ladder[1].bottom = 9;
    ladder[1].top = 31;
    ladder[2].bottom = 28;
    ladder[2].top = 84;
    ladder[3].bottom = 51;
    ladder[3].top = 67;
    ladder[4].bottom = 80;
    ladder[4].top = 99;

    bool game_end = false;

    while(!game_end){
        for(int i=0; i<n; i++){

            display(arr[i].name,arr[i].position);
            cout << "Press Enter to roll the dice...";
            getch();

            int num = roll_dice();
            arr[i].position += num;
            cout << arr[i].name << " got " << num << "\n";

            if(arr[i].position == 100){
                cout<<arr[i].name<<" wins the game!!!\n";
                game_end = true;
                break;
            }
            else if(arr[i].position > 100){
                cout << "Over shot 100! Stay at " << arr[i].position << ".\n";
                arr[i].position -= num;
            }
            else{
                bool ladderUsed = true;
                for(int j=0; j<5; j++){
                    if(arr[i].position == ladder[j].bottom){
                        cout << arr[i].name << " climbs a ladder from " 
                        << ladder[j].bottom << " to " << ladder[j].top << "!\n";
                        arr[i].position = ladder[j].top;
                        ladderUsed = false;
                        break;
                    }
                }

                if(ladderUsed){
                    for(int j=0; j<5; j++){
                        if(arr[i].position == snake[j].head){
                            cout << arr[i].name << " got bitten by a snake at " 
                                << snake[j].head << " and falls to " << snake[j].tail << "!\n";
                            arr[i].position = snake[j].tail;
                            break;
                        }
                    }                    
                }
            }
            cout << "Current position: " << arr[i].position << "\n\n";
        }
    }
    return 0;
}
