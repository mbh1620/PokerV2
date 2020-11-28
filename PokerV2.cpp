#include <iostream>
#include "./Game/poker_game_class.hpp"


int main()
{	
	bool game_flag = true;

	Poker_Game game1;

	game1.initialise_game();

	game1.game_run();

	while(game_flag)
	{	
		char input = 'a';
		game_flag = false;
		game1.game_run(game1.get_current_players());
		std::cout << "Press 'y' to continue";
		std::cin >> input;
		if(input == 'y')
		{
			game_flag = true;
		}
	}
}
