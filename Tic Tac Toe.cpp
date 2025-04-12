#include<bits/stdc++.h>

using namespace std;

void print_Grid(vector<vector<char>> &grid){
    cout<<"\nCurrent Grid:\n";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<grid[i][j]<<" ";

        }
        cout<<"\n";
    }
}

bool check(vector<vector<char>> &grid, bool &tie){

    for(int i=0; i<3; i++){
        if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] || grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]){
            return true;
        }
    }

    if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] || grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
        return true;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[i][j] != 'x' && grid[i][j] != '0'){
                return false;
            }
        }
    }
    tie = true;
    return true;
}

void Play_Game(string p1, string p2, vector<vector<char>>&grid,char &token, bool &tie){
    int digit = 0;
    if(token == 'x'){
        cout<<p1<<" Please Enter the number \n";
        cin>>digit;
    }

    if(token == '0'){
        cout<<p2<<" Please Enter the number \n";
        cin>>digit;
    }
    int row = -1;
    int col = -1;
    switch (digit)
    {
    case 1:
        row = 0;
        col = 0;
        break;
    
    case 2:
        row = 0;
        col = 1;
        break;
    
    case 3:
        row = 0;
        col = 2;
        break;
    
    case 4:
        row = 1;
        col = 0;
        break;
    
    case 5:
        row = 1;
        col = 1;
        break;
    
    case 6:
        row = 1;
        col = 2;
        break;
    
    case 7:
        row = 2;
        col = 0;
        break;

    case 8:
        row = 2;
        col = 1;
        break;

    case 9:
        row = 2;
        col = 2;
        break;
    default:
        cout<<"Invalid Choice\n";
        Play_Game(p1,p2,grid,token,tie);
        return;
    }

    if(token == 'x' && grid[row][col] != 'x' && grid[row][col] != '0'){
        grid[row][col] = token;
        token = '0';
    }
    else if(token == '0' && grid[row][col] != 'x' && grid[row][col] != '0'){
        grid[row][col] = token;
        token = 'x';
    }
    else{
        cout<<"Cell is already filled. Please enter again \n";
        Play_Game(p1,p2,grid,token,tie);
        return;
    }

    check(grid,tie);
}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        string p1 = "";
        string p2 = "";
        cout<<"Enter Player 1 Name: \n";
        cin>>p1;    
        cout<<"Player 1 : "<<p1<<" \nSymbol : x\n";
        cout<<"Enter Player 2 Name: \n";
        cin>>p2;
        cout<<"Player 2 : "<<p2<<" \nSymbol : 0\n";
        vector<vector<char>> grid={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
        print_Grid(grid);
    
        bool tie = false;
        char token = 'x';
        while(!check(grid,tie)){
            Play_Game(p1,p2,grid,token,tie);
            print_Grid(grid);
            check(grid,tie);
        }
    
        if(token == '0' && tie == false){
            cout<<p1<<" wins the game!!!\n\n";
        }
        else if(token == 'x' && tie == false){
            cout<<p2<<" wins the game!!!\n\n";
        }
        else{
            cout<<"DRAW\n\n";
        }
    }

    return 0;
}
