#include <iostream>
#include "card_class.hpp"
#include "hand_class.hpp"
#include "player_class.hpp"
#include "table_class.hpp"
#include "deck_class.hpp"


int main()
{	

	//ALL OF THIS WILL EVENTUALLY GO IN A GAME CLASS

	int player_num = 0;

	std::cout << "Please input number of players";

	std::cin >> player_num;



	//Create the deck and table dynamically
	Deck* deck = new Deck();

	Table* table = new Table(player_num);

	//Deal players and table their cards

	deck -> deal_cards(table->get_all_players(), player_num, *table);

	table -> set_game_flag(0);

	for(int i = 0; i < player_num; i++)
	{
		table -> players_turn(i);
	}

	table -> set_game_flag(1);

	for(int i = 0; i < player_num; i++)
	{
		table -> players_turn(i);
	}

	table -> set_game_flag(2);

	for(int i = 0; i < player_num; i++)
	{
		table -> players_turn(i);
	}

	table -> set_game_flag(3);

	for(int i = 0; i < player_num; i++)
	{
		table -> players_turn(i);
	}

	for(int i = 0; i < player_num; i++)
	{
		int score = table -> get_player(i).calculate_score(*table);
		std::cout << score << "\n";
	}

	//Player with lowest score wins



	

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
