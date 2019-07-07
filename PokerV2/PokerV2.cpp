#include <iostream>
#include "poker_game_class.hpp"


int main()
{	

	Poker_Game game1;

	game1.initialise_game();

	game1.game_run();

	game1.game_run(game1.get_current_players());

	game1.game_run(game1.get_current_players());

	game1.game_run(game1.get_current_players());

	return 0;
	

	// Card A('2','H');
	// Card B('K','H');	
	// Card C('J','S');
	// Card D('9','C');
	// Card E('7','D');
	// Card F('9','D');
	// Card G('7','H');

	// Card Cards[7];

	// Cards[0] = A;
	// Cards[1] = B;
	// Cards[2] = C;
	// Cards[3] = D;
	// Cards[4] = E;
	// Cards[5] = F;
	// Cards[6] = G;

	//QD-TH-8S   6C-4D  6D 4H

	//JC-9D-7H   5S-3C  5C 3D

	// Deck deck1;
	// Table table1(10);
	// table1.set_game_flag(3);
	// deck1.deal_cards(table1.get_all_players(), 10, table1);

	
	// for(int i = 0; i < 10; i++)
	// {
	// 	table1.print_table();
	// 	table1.players_turn(i);
	// 	std::cout << table1.get_player(i).calculate_score(table1) << "\n"; 
	// }




	


	//std::cout << two_pair(Cards);


	


}
