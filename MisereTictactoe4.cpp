#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()

void clear()
{
    int i;
    for (i=0; i<50;i++)
    {
        std::cout << '\n';
    }
}

class board
{
    private:
        std::vector<std::vector<bool>> plays;
        bool dead;

    public:
        board()
        {
			int i;
			dead = false;
			plays.resize(3);
            for (i=0;i<3;i++)
			{
				plays.at(i).resize(3);
			}
        }

		std::vector<std::vector<bool>> showPlay()
		{
			return plays;
		}

		bool validateMove(int move)
		{
			int i;
			int j;
			int x;
			int y;
			if(move<0 || move > 8)
			{
				return false;
			}
			x=(move/3);
			y=(move%3);
			if(plays.at(x).at(y)==true)
			{
				return false;
			}else if(isDead())
			{
				return false;
			}else
			{
				return true;
			}
			
		}

		void makeMove(int move)
		{
			int x;
			int y;
			x=(move/3);
			y=(move%3);
			std::cout <<std::endl << "X:" << x << ' ' << "Y:" << y << std::endl; 
			plays.at(x).at(y)=true;
		}

		bool winCondition()
		{
			bool topleft = plays.at(0).at(0);
			bool mid = plays.at(1).at(1);
			bool botright = plays.at(2).at(2);

			if(topleft == mid && plays.at(2).at(2) == mid && mid == true)
			{
				return true;
			}else if(plays.at(0).at(2) == mid && plays.at(2).at(0) == mid && mid == true)
			{
				return true;
			}else if(plays.at(0).at(1) == mid && plays.at(2).at(1) == mid && mid == true)
			{
				return true;
			}else if(plays.at(1).at(0) == mid && plays.at(1).at(2) == mid && mid == true)
			{
				return true;
			}else if(topleft == plays.at(0).at(1) && topleft == plays.at(0).at(2) && topleft == true)
			{
				return true;
			}
			else if (topleft == plays.at(1).at(0) && topleft == plays.at(2).at(0) && topleft == true)
			{
				return true;
			}else if(botright == plays.at(1).at(2) && botright == plays.at(0).at(2) && botright == true)
			{
				return true;
			}
			else if(botright == plays.at(2).at(0) && botright == plays.at(2).at(1) && botright == true)
			{
				return true;
			}else
			{
				return false;
			}
			
		}

		void killBoard()
		{
			dead=true;
		}

		bool isDead()
		{
			return dead;
		}
};

void render(std::vector<std::vector<bool>> board1, std::vector<std::vector<bool>> board2, std::vector<std::vector<bool>> board3)
{
	std::cout << board1.at(0).at(0) << board1.at(0).at(1) << board1.at(0).at(2) << ' ' << board2.at(0).at(0) << board2.at(0).at(1) << board2.at(0).at(2) << ' ' << board3.at(0).at(0) << board3.at(0).at(1) << board3.at(0).at(2) << '\n';
	std::cout << board1.at(1).at(0) << board1.at(1).at(1) << board1.at(1).at(2) << ' ' << board2.at(1).at(0) << board2.at(1).at(1) << board2.at(1).at(2) << ' ' << board3.at(1).at(0) << board3.at(1).at(1) << board3.at(1).at(2) << '\n';
	std::cout << board1.at(2).at(0) << board1.at(2).at(1) << board1.at(2).at(2) << ' ' << board2.at(2).at(0) << board2.at(2).at(1) << board2.at(2).at(2) << ' ' << board3.at(2).at(0) << board3.at(2).at(1) << board3.at(2).at(2) << '\n';
}

int main()
{
	board board1;
	board board2;
	board board3;
	int i;
	int move;
	int turn;
	for(i=0;i<27;i++)
	{
		turn=(i%2)+1;
		
		clear();
		render(board1.showPlay(), board2.showPlay(), board3.showPlay());
		std::cout << std::endl << "Player " << turn << " is now playing..." << std::endl;
		std::cin >> move;
		int whichBoard;
		whichBoard = (move-1)/9;
		move = (move-1) % 9;
		switch(whichBoard)
		{
			case 0:
				if(board1.validateMove(move) && !board1.isDead())
					{
						board1.makeMove(move);
						if(board1.winCondition() == true)
						{
							board1.killBoard();
							std::cout << "Board 1 is dead!" << std::endl;
						}
					}else i--;
				break;

			case 1:
				if(board2.validateMove(move) && !board2.isDead())
				{
					board2.makeMove(move);
					if(board2.winCondition() == true)
					{
						board2.killBoard();
						std::cout << "Board 1 is dead!" << std::endl;
					}
				}else i--;
				break;
			
			case 2:
				if(board3.validateMove(move) && !board3.isDead())
				{
					board3.makeMove(move);
					if(board3.winCondition() == true)
					{
						board3.killBoard();
						std::cout << "Board 1 is dead!" << std::endl;
					}
				}else i--;
				break;
			}
		if(board1.winCondition() == true && board2.winCondition() == true && board3.winCondition() == true)
		{
			std::cout << "Player "<< turn << " won!!!";
			return 0;
		}
	}
	return 0;
}