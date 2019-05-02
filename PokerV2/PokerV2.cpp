#include <iostream>
#include "card_class.hpp"
#include "hand_class.hpp"
#include "player_class.hpp"
#include "table_class.hpp"
#include "deck_class.hpp"
#include "score_class.hpp"

int main()
{	

	Table table1(5);

	Deck deck1;

	deck1.deal_cards(table1.get_all_players(), 5, table1);

	//std::cout << table1;

	//std::cout << deck1;

	// for(int i = 0; i < 10; i++)
	// {
	// 	std::cout << table1.get_player(i);
	// }

	for(int i = 0; i < 5; i++)
	{
		table1.players_turn(i);
	}
	for(int i = 0; i < 5; i++)
	{
		table1.players_turn(i);
	}


}
