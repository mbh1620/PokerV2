#include "score_calculations.hpp"
//--------------------------------------------------------------------//
//																	  //
//					The Table Class - Used to display the game 	      //
//																	  // 
//--------------------------------------------------------------------//

//Copyright: Matthew Haywood

//The Table class will be used to keep the current player in order, to display the bets, display the end cards and display the winner.

//The Table class will consist of:

//								- an organised way to initiate the amount of players.
//								- an organised method to let the next player take a turn.
//								- player objects based on how many people are playing.
//								- An object which holds the table cards. (flop and river).
// 								- A score object



class Table
{

private:

//private data
	Player *Players;							//Create a pointer to a 'Player' array.

	int player_num;								//The integer number for how many players are playing.

	Card Flop_Cards[3];							//An array of 3 cards used to store the dealt flop cards.

	Card River_Cards[2];						//An array of 2 cards to store the turn and river cards.

	int game_flag;								//The game flag decides what cards are to be shown when the table is printed.

	float highest_bet;							//A float used to store the highest current bet that has been placed.

	float pot_total;							//A float used to express the pot to be won.

public:

	Table(int player_num); 											//Constructor - The number of players has to be provided.

	Table(Player *old_players, int _player_num);					//Constructor - An array of players has to be supplied and the amount of players.

	~Table();														//Destructor

	Table(const Table& a);											//Copy Constructor

	Table& operator=(const Table& a);								//Assigment Operator

	Player& get_player(int player_id);								//Get player function

	void set_Flop_cards(Card& flop1, Card& flop2, Card& flop3);		//Set_Flop_Card function

	void set_River_cards(Card& river1, Card& river2);				//Set_River_Card function

	Card * get_Flop();												//Get Flop card function

	Card * get_River();												//Get River Card function

	int get_player_num();

	float get_highest_bet();										//Get Highest Bet function

	void set_highest_bet(float bet);

	float get_pot();												//Get pot function

	void set_game_flag(int _game_flag);								//Set the game flag. 0 (no cards shown), 1 (show flop), 2 (show turn) and 3 (show river).

	void players_turn(int current_player);							//Function to allow players to take a turn.

	void print_table();												//Used to print table GUI.

	Player * get_all_players();										//Get all players function

	friend void operator<<(std::ostream &os, const Table& a);		//Operator for doing cout << (Table)

	
};

Table::Table(int _player_num)												//Constructor for when the int number_of_players is supplied
{
	player_num = _player_num;

	game_flag = 0;

	pot_total = 0;

	highest_bet = 0;

	Players = new Player[player_num];										//Create a new 'Player' array which has the name 'Players' which is pointed to. 

	for( int i = 0; i < player_num; i++)
	{
		Players[i].id = i;				//Assign each player an id.
	}
}

Table::Table(Player *old_players, int _player_num)							//A constructor for when a players array is supplied from an old table.
{
	player_num = _player_num;

	pot_total = 0;

	game_flag = 0;

	highest_bet = 0;

	Players = old_players;

	
}

Table::~Table()																//Destructor which deletes the dynamically allocated array 'Players'.
{
	delete[] Players;
}

Table::Table(const Table& a)
{
	
}

Player& Table::get_player(int player_id)									//Get player function which returns the 'Player' object which is being requested.
{
	
	return Players[player_id];

}

void Table::set_Flop_cards(Card& _flop1, Card& _flop2, Card& _flop3)		//Set flop cards function. 
{
	Flop_Cards[0] = _flop1;
	Flop_Cards[1] = _flop2;
	Flop_Cards[2] = _flop3;
}

void Table::set_River_cards(Card& _river1, Card& _river2)					//Set river cards function.
{
	River_Cards[0] = _river1;
	River_Cards[1] = _river2;
}

Card * Table::get_Flop()													//Get flop function.
{
	return Flop_Cards;
}

Card * Table::get_River()
{
	return River_Cards;
}

int Table::get_player_num()
{
	return player_num;
}

float Table::get_highest_bet()
{
	return highest_bet;
}

void Table::set_highest_bet(float bet)
{
	this -> highest_bet = bet;
}

float Table::get_pot()
{
	return pot_total;
}

void Table::set_game_flag(int _game_flag)
{
	game_flag = _game_flag;
}

void Table::players_turn(int current_player)
{	
	
	bool flag = true;

	while(flag)
	{
		//system("clear");
		char ans;
		float bet;
		char f;

		print_table();
		std::cout << "The total pot is: £" << pot_total << "\n";
		std::cout << "Your Cards: " << Players[current_player].get_hand() << "\n";
		std::cout << "Your balance: £" << Players[current_player].get_balance() << "\n"; 
		std::cout << "Would you like to Check(c), Fold(f), Raise(r) or Match(m)? \n";
		std::cin >> ans;


		flag = false;
		if(ans == 'c' && highest_bet == 0)
		{
			bet = 0;
		}
		else if(ans == 'c' && highest_bet != 0)
		{
			std::cout << "You have to match or raise the bet which is currently at: " << highest_bet;
			flag = true;
		}
		else if(ans == 'f')
		{
			Players[current_player].set_fold_flag(true);
		}
		else if( ans == 'r')
		{
			float raise_bet;
			std::cout << "What would you like to raise the current bet to? \n";
			std::cin >> raise_bet;
			if(raise_bet <= Players[current_player].get_balance() && raise_bet >= highest_bet)
			{
				highest_bet = raise_bet;
				float _players_updated_balance = Players[current_player].get_balance()-raise_bet;
				pot_total = pot_total + raise_bet;
				Players[current_player].set_balance(_players_updated_balance);
			}
			else if(raise_bet > Players[current_player].get_balance())
			{
				char all_in;
				std::cout << "You do not have enough money for that bet, would you like to go all in? (y/n) \n";
				std::cin >> all_in;
				flag = true;
			}
			else if(raise_bet < highest_bet)
			{
				std::cout << "Your bet is smaller than the current bet, raise, match or fold \n";

				std::cin.ignore();

				flag = true;
				
			}
		}

		else if(ans == 'm' && Players[current_player].get_balance() >= highest_bet )
		{
			bet = highest_bet;
			float new_balance = Players[current_player].get_balance() - bet;
			pot_total = pot_total + bet;
			Players[current_player].set_balance(new_balance);
		}

		else if(ans == 'm' && Players[current_player].get_balance() < highest_bet)
		{
			char all_in;
			flag = true;
			std::cout << "You do not have enough money left, Do you want to go all in? (y/n)";
			std::cin >> all_in;
		}

		system("clear");
		system("clear");
	}
}

Player * Table::get_all_players()
{
	return Players;
}

void operator<<(std::ostream &os, const Table& a)					//Function for cout << (Table). Simply prints out the number of players.
{
	std::cout << "Player number: "<< a.player_num << "\n";

	std::cout << "Table Cards: \n";
	for(int i = 0; i < 3; i++)
	{
		std::cout << a.Flop_Cards[i] << "\n";
	}
	for(int i = 0; i < 2; i++)
	{
		std::cout << a.River_Cards[i] << "\n";
	}
}

void Table::print_table()
{
	if(game_flag == 0)
	{
		std::cout << "X-X-X   X-X \n";
	}

	if(game_flag == 1)
	{
		std::cout << Flop_Cards[0] << "-" << Flop_Cards[1] << "-" << Flop_Cards[2] << " "<<"X-X \n"; 
	}

	if(game_flag == 2)
	{
		std::cout << Flop_Cards[0] << "-" << Flop_Cards[1] << "-" << Flop_Cards[2] << "   "<< River_Cards[0] << "-X \n";
	}

	if(game_flag == 3)
	{
		std::cout << Flop_Cards[0] << "-" << Flop_Cards[1] << "-" << Flop_Cards[2] << "   "<< River_Cards[0] << "-" << River_Cards[1] << "\n";
	}

	std::cout << "The highest bet: £" <<  highest_bet << "\n";
}

float Player::calculate_score(Table& _table)
{
	float score;

	Card Players_Cards[7];
	Players_Cards[0] = hand1.get_A();
	Players_Cards[1] = hand1.get_B();
	Players_Cards[2] = _table.get_Flop()[0];
	Players_Cards[3] = _table.get_Flop()[1];
	Players_Cards[4] = _table.get_Flop()[2];
	Players_Cards[5] = _table.get_River()[0];
	Players_Cards[6] = _table.get_River()[1];

	/* Winning Hands - 
				1 - Royal Flush
				2 - Straight Flush
				3 - Four of a Kind
				4 - Full House
				5 - Flush
				6 - Straight
				7 - Three of a Kind
				8 - Two Pair
				9 - Pair
				10 - High Card

	When Calculating score check in this order
	*/

	// Check for Royal Flush:

	if(royal_flush(Players_Cards))
	{
		score = 1;
		return 1;	
	}
		

	// Check for Straight Flush:

	if(straight_flush(Players_Cards))
	{
		score = 2;
		return 2;
	}

	// Check for Four of a Kind:

	if(four_of_a_kind(Players_Cards))
	{
		score = 3;
		return 3;
	}

	// Check for Full House:

	if(full_house(Players_Cards))
	{
		score = 4;
		return 4;
	}


	// Check for Flush:

	if(flush(Players_Cards))
	{
		score = 5;
		return 5;
	}


	// Check for Straight:

	if(straight(Players_Cards))
	{
		score = 6;
		return 6;
	}

	// Check for Three of a Kind:

	if(three_of_a_kind(Players_Cards))
	{
		score = 7; 
		return 7;
	}

	// Check for Two Pair:

	if(two_pair(Players_Cards))
	{
		score = 8;
		return 8;
	}

	// Check for Pair:

	if(pair(Players_Cards))
	{
		score = 9;
		return 9;
	}

	// Check for High Card:

	if(high_card(Players_Cards))
	{
		score = 10;
		return 10;
	}

return 0;

}



