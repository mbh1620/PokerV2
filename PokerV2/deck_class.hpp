
//--------------------------------------------------------------------//
//																	  //
//					The Deck class									  //
//																	  // 
//--------------------------------------------------------------------//

// Copyright: Matthew Haywood

//The Deck class will be used so that there are two "deck" objects during 
//one game. One will be a cards deck to allow the dealer to choose any random
//card from a normal playing deck. The other deck will be a 'Used cards' deck
//so that the dealer will also know which cards cant be used twice.

//The Deck class will consist of:
							
//							- 52 Card objects which need to be assigned a value and be the values of a normal playing card deck.
//							- The big four (initiator which will assign the cards with normal values)
//							- 


//Other functions associated with the class:

//							- 



class Deck
{

private:

//private data
	
	Card The_Deck[52];								//A Deck consists of an array of 52 cards.

	Card Used_Cards[25];							//A Deck of Cards which must NOT be used as they have been dealt to players or the table.

public:

	Deck(); 													//Constructor

	~Deck();													//Destructor

	Deck(const Deck& a);										//Copy Constructor

	Deck& operator=(const Deck& a);								//Assigment Operator

	Card& get_card(int array_index);							//Gets a card from 'The_deck'

	Card * get_Deck();											//Function for getting the whole deck

	Card * get_Used_Deck();										//Function for getting the used cards deck

	Card& new_random_card(int count);							//Returns a new random unused card.

	void deal_cards(Player Players[], int player_num, Table& table);			//Deals Randomly generated cards to each player within the player array.

	friend void operator<<(std::ostream &os, const Deck& a);	//Operator for cout << (Deck)

};

Deck::Deck()													//Function to initialise the Decks
{
	int c = 0;

	for(int i = 0; i<25; i++)
	{
		Used_Cards[i].set_value('N');
		Used_Cards[i].set_suit('N');
	}

	for(int i = 0; i < 4; i++)
	{
		for(int z = 0; z < 13; z++)
		{
			

			if(i == 0)						//Suit is Clubs
			{
				The_Deck[c].set_suit('C');
				
				int t = z+2;

				char val = '0' + t;
				
				
				The_Deck[c].set_value(val);
				
				switch(z)
				{
					case 8:
					The_Deck[c].set_value('T');
					break;

					case 9:
					The_Deck[c].set_value('J');
					break;

					case 10:
					The_Deck[c].set_value('Q');
					break;

					case 11:
					The_Deck[c].set_value('K');
					break;

					case 12:
					The_Deck[c].set_value('A');
					break;

				}
			}

			if(i == 1)						//Suit is Diamonds
			{
				The_Deck[c].set_suit('D');

				int t = z+2;

				char val = '0' + t;
				
				
				The_Deck[c].set_value(val);
				
				switch(z)
				{
					case 8:
					The_Deck[c].set_value('T');
					break;

					case 9:
					The_Deck[c].set_value('J');
					break;

					case 10:
					The_Deck[c].set_value('Q');
					break;

					case 11:
					The_Deck[c].set_value('K');
					break;

					case 12:
					The_Deck[c].set_value('A');
					break;

				}
			}

			if(i == 2)						//Suit is Hearts
			{
				The_Deck[c].set_suit('H');

				int t = z+2;

				char val = '0' + t;
				
				
				The_Deck[c].set_value(val);
				
				switch(z)
				{
					case 8:
					The_Deck[c].set_value('T');
					break;

					case 9:
					The_Deck[c].set_value('J');
					break;

					case 10:
					The_Deck[c].set_value('Q');
					break;

					case 11:
					The_Deck[c].set_value('K');
					break;

					case 12:
					The_Deck[c].set_value('A');
					break;

				}
			}

			if(i == 3) 						//Suit is Spades
			{
				The_Deck[c].set_suit('S');

				int t = z+2;

				char val = '0' + t;
				
				
				The_Deck[c].set_value(val);
				
				switch(z)
				{
					case 8:
					The_Deck[c].set_value('T');
					break;

					case 9:
					The_Deck[c].set_value('J');
					break;

					case 10:
					The_Deck[c].set_value('Q');
					break;

					case 11:
					The_Deck[c].set_value('K');
					break;

					case 12:
					The_Deck[c].set_value('A');
					break;

				}
			}
			c++;
		}
	}

}

Deck::~Deck()									//Destructor
{

}

Deck::Deck(const Deck& a)						//Copy Constructor
{

}

Deck& Deck:: operator=(const Deck& a)			//Assignment Operator
{
	return *this;
}

Card& Deck::get_card(int array_index)			//Get Card function
{
	return The_Deck[array_index];
}

Card * Deck::get_Deck()							//Get Deck function
{
	return The_Deck;
}

Card * Deck::get_Used_Deck()					//Get Used Deck function
{
	return Used_Cards;
}

Card& Deck::new_random_card(int count)			//Function used to get a random card which hasnt already been drawn.
{
	int new_card;

	bool flag = true;

	while(flag == true)
	{
		flag = false;
		new_card = rand() % 52 + 1;

		for(int i = 0; i < 25; i++)
		{
			//std::cout << The_Deck[new_card] << " ";
			//std::cout << Used_Cards[i] << " ";
			if(The_Deck[new_card] == Used_Cards[i])
			{
				flag = true;
				//std::cout << The_Deck[new_card];
			}
		}
	}

	//std::cout << count;
	
	Used_Cards[count] = The_Deck[new_card];
	count++;
	return The_Deck[new_card];
}

void Deck::deal_cards(Player players[], int player_num, Table& table)					//Function used to deal random cards to players in the array
{
	int count = 0;
	for(int i = 0; i < player_num; i++)
	{
		players[i].get_hand().set_A(Deck::new_random_card(count));
		count++;
		//std::cout << players[i].get_hand().get_A();
		players[i].get_hand().set_B(Deck::new_random_card(count));
		count++;
	}

	table.set_Flop_cards(new_random_card(count), new_random_card(count+1), new_random_card(count+2));
	count = count + 3;
	table.set_River_cards(new_random_card(count), new_random_card(count+1));
	count = count + 2;
}



void operator<<(std::ostream &os, const Deck& a)						//Function for cout << (Table).
{
	std::cout << "Used cards: \n";
	for(int i = 0; i < 25; i++)
	{
		std::cout << a.Used_Cards[i] << "\n";
	}

}











