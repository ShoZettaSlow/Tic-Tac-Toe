#include <iostream>
#include <vector>

void clear()
{
    int i;
    for (i=0; i<50;i++)
    {
        std::cout << '\n';
    }
}

int render(std::vector<int> plays)
{
    int i;
    char show[9];
    for (i=0;i<9;i++)
    {
        switch(plays[i])
        {
            case 0:
            show[i]=49+i;
            break;

            case 1:
            show[i]='X';
            break;

            case 2:
            show[i]='X';
            break;
        }
    }
    clear();
    std::cout << "Player 1: X\tPlayer 2: X";
    std::cout << '\n';
    std::cout << '\n';
    std::cout <<'\t'<< "+-----+-----+-----+" << '\n';
    std::cout <<'\t'<< "|     |     |     |" << '\n';
    std::cout <<'\t'<< "|  "<< show[0] <<"  |  "<< show[1] <<"  |  "<< show[2] <<"  |" << '\n';
    std::cout <<'\t'<< "|     |     |     |" << '\n';
    std::cout <<'\t'<< "+-----+-----+-----+" << '\n';
    std::cout <<'\t'<< "|     |     |     |" << '\n';
    std::cout <<'\t'<< "|  "<< show[3] <<"  |  "<< show[4] <<"  |  "<< show[5] <<"  |" << '\n';
    std::cout <<'\t'<< "|     |     |     |" << '\n';
    std::cout <<'\t'<< "+-----+-----+-----+" << '\n';
    std::cout <<'\t'<< "|     |     |     |" << '\n';
    std::cout <<'\t'<< "|  "<< show[6] <<"  |  "<< show[7] <<"  |  "<< show[8] <<"  |" << '\n';
    std::cout <<'\t'<< "|     |     |     |" << '\n';
    std::cout <<'\t'<< "+-----+-----+-----+" << '\n';
}

bool isValid(std::vector<int> plays, int move)
{
    if(move<1 || move >9)
        return false;
    else if(plays[move-1]!=0)
        return false;
    else{
    return true;
    }
}

bool winCondition(std::vector<int> plays)
{
    if (plays[4]!=0)
        {
            if(plays[0]==plays[4] && plays[4]==plays[8])
                return true;
            else if(plays[2]==plays[4] && plays[4]==plays[6])
                return true;
            else if(plays[1]==plays[4] && plays[4]==plays[7])
                return true;
            else if (plays[3]==plays[4] && plays[4]==plays[5])
                return true;
        }
    if(plays[0]!=0)
    {
        if (plays[0]==plays[1] && plays[1]==plays[2])
            return true;
        else if (plays[0]==plays[3] && plays[3]==plays[6])
            return true;
    }
    if(plays[8]!=0)
    {
        if(plays[6]==plays[7] && plays[7]==plays[8])
            return true;
        else if(plays[2]==plays[5] && plays[5]==plays[8])
            return true;
    }
    
    return false;
}

int main()
{  
    std::vector<int> plays (9,0);
    int i;
    /*------------/
    0 for Empty
    1 for Player 1 (X)
    2 for Player 2 (X)
    /------------*/
    for(i=0;i<9;i++)
    {
        int turn =(i%2)+1; // 1 for player 1, 2 for player 2
        render(plays);
        std::cout << "Player " << turn << " is now playing..." << '\n';
        int move;        
        while(true)
        {
            std::cin >> move;
            if(isValid(plays, move))
            {
                plays[move-1] = 1;
                break;
            }
        }
        if(winCondition(plays)==true)
        {
            render(plays);
            int win = ((i+1)%2)+1;
            std::cout << "Player " << win << " won!!!!";
            std::cin.ignore();
            std::cin.get();
            return 0;
        }
    }

    render(plays);
    std::cout << "It's a draw!!!";
    std::cin.ignore();
    std::cin.get(); 
    return 0;
}