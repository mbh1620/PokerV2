
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

	Card Flop_Cards[3];

	Card River_Cards[2];

	int game_flag;								//The game flag decides what cards are to be printed when the table is printed.

	float highest_bet;


public:

	Table(int player_num); 											//Constructor

	~Table();														//Destructor

	Table(const Table& a);											//Copy Constructor

	Table& operator=(const Table& a);								//Assigment Operator

	Player& get_player(int player_id);								//Get player function

	void set_Flop_cards(Card& flop1, Card& flop2, Card& flop3);		//Set_Flop_Card function

	void set_River_cards(Card& river1, Card& river2);				//Set_River_Card function

	Card * get_Flop();

	Card * get_River();

	void set_game_flag(int _game_flag);

	void players_turn(int current_player);						//Function to allow players to take a turn.

	void print_table();

	Player * get_all_players();										//Get all players function

	friend void operator<<(std::ostream &os, const Table& a);		//Operator for doing cout << (Table)

	
};

Table::Table(int _player_num)												//Constructor for when the int number_of_players is supplied
{
	player_num = _player_num;

	game_flag = 0;

	highest_bet = 0;

	Players = new Player[player_num];										//Create a new 'Player' array which has the name 'Players' which is pointed to. 

	for( int i = 0; i < player_num; i++)
	{
		Players[i].id = i;				//Assign each player an id.
	}
}

Table::~Table()																//Destructor which deletes the dynamically allocated array 'Players'.
{
	delete[] Players;
}

Player& Table::get_player(int player_id)									//Get player function which returns the 'Player' object which is being requested.
{
	
	return Players[player_id];

}

void Table::set_Flop_cards(Card& _flop1, Card& _flop2, Card& _flop3)
{
	Flop_Cards[0] = _flop1;
	Flop_Cards[1] = _flop2;
	Flop_Cards[2] = _flop3;
}

void Table::set_River_cards(Card& _river1, Card& _river2)
{
	River_Cards[0] = _river1;
	River_Cards[1] = _river2;
}

Card * Table::get_Flop()
{
	return Flop_Cards;
}

Card * Table::get_River()
{
	return River_Cards;
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
		system("clear");
		char ans;
		float bet;
		char f;

		print_table();
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
			Players[current_player].set_balance(new_balance);
		}

		else if(ans == 'm' && Players[current_player].get_balance() < highest_bet)
		{
			char all_in;
			flag = true;
			std::cout << "You do not have enough money left, Do you want to go all in? (y/n)";
			std::cin >> all_in;
		}
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



