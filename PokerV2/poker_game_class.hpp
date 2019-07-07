#include <iostream>
#include "card_class.hpp"
#include "hand_class.hpp"
#include "player_class.hpp"
#include "table_class.hpp"
#include "deck_class.hpp"


class Poker_Game
{

private:

	int _player_num;

	Player *Current_players;

//private data

public:

	Poker_Game(); 						//constructor

	~Poker_Game();						//Destructor

	Poker_Game(const Poker_Game& a);		//Copy Constructor

	Poker_Game& operator=(const Poker_Game& a);	//Assigment Operator

	void initialise_game();					//Initialise_game

	void game_run();				//Letter is used to assign new objects to

	void game_run(Player players[]);

	void set_current_players(Player *players);

	Player * get_current_players();

	
};

Poker_Game::Poker_Game()
{
	
}

Poker_Game::~Poker_Game()
{
	delete[] Current_players;
}

Poker_Game::Poker_Game(const Poker_Game& a)
{

}

Poker_Game& Poker_Game:: operator=(const Poker_Game& a)
{
	return *this;
}

void Poker_Game::initialise_game()
{
	int player_num = 0;

	std::cout << "Please input number of players";

	std::cin >> player_num;

	_player_num = player_num;

}

void Poker_Game::game_run()
{

		int lowest = 10;
		int num = 0;
		//Create the deck and table dynamically
		Deck* deck = new Deck();

		Table* table = new Table(_player_num);

		deck -> deal_cards(table->get_all_players(), _player_num, *table);

		for(int i = 0; i < 4; i++)
		{
			table -> set_game_flag(i);
			table -> set_highest_bet(0);

			for(int z = 0; z < table -> get_player_num(); z++)
			{
				table -> players_turn(z);
			}
		}

		for(int i = 0; i < table -> get_player_num(); i++)
		{
			if(table -> get_player(i).calculate_score(*table) < lowest)
			{
				num = i;
			}
		}

		std::cout << "The winner is player: " << num << "\n";
		std::cout << "The winner has won: £" << table -> get_pot() << "\n";

		//Add total pot to players cash

		float current_balance = table -> get_player(num).get_balance();

		float balance_after_win = current_balance + table -> get_pot();

		table -> get_player(num).set_balance(balance_after_win);

		std::cout << "Winners balance: £" << table -> get_player(num).get_balance();

		this -> Current_players = table -> get_all_players();

		


	
}

void Poker_Game::game_run(Player players[])
{
	int lowest = 10;
		int num = 0;
		//Create the deck and table dynamically
		Deck* deck = new Deck();

		Table* table = new Table(players, _player_num);

		deck -> deal_cards(table->get_all_players(), _player_num, *table);

		for(int i = 0; i < 4; i++)
		{
			table -> set_game_flag(i);
			table -> set_highest_bet(0);

			for(int z = 0; z < table -> get_player_num(); z++)
			{
				table -> players_turn(z);
			}
		}

		std::cout << "done";

		for(int i = 0; i < table -> get_player_num(); i++)
		{
			if(table -> get_player(i).calculate_score(*table) < lowest)
			{
				num = i;
			}
		}

		std::cout << "The winner is player: " << num << "\n";
		std::cout << "The winner has won: £" << table -> get_pot() << "\n";

		//Add total pot to players cash

		float current_balance = table -> get_player(num).get_balance();

		float balance_after_win = current_balance + table -> get_pot();

		table -> get_player(num).set_balance(balance_after_win);

		std::cout << "Winners balance: £" << table -> get_player(num).get_balance() << "\n";

		set_current_players(table -> get_all_players());

	
}

void Poker_Game::set_current_players(Player *players)
{
	this -> Current_players = players;
}

Player * Poker_Game::get_current_players()
{
	return Current_players;
}







