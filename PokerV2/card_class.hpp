
//--------------------------------------------------------------------//
//																	  //
//					The Card Class           						  //
//																	  // 
//--------------------------------------------------------------------//

//Copyright: Matthew Haywood

//The card class will consist of:
//								-	A value int which represents the value of the card from 2 - Ace
// 								-	A Suit char which represents the suit of the card.
//								- 	The Big Four.
//								- 	A function used to compare two cards (value and suit).




class Card
{

private:

//private data
	char value;							//Used to store the value of the card

	char suit;							//Used to store the suit of the card

public:

	friend class Hand;

	Card();

	Card(char _value, char _suit); 		//constructor for when values are supplied

	~Card();							//Destructor

	Card(const Card& a);				//Copy Constructor

	Card& operator=(const Card& a);		//Assigment Operator

	bool operator==(const Card& a); 	//Comparitive operator

	bool compare(const Card& a);        //Compare two cards

	bool suit_compare(const Card& a);	//Function to compare two cards to see if the suit is the same (helps with score calculating)

	bool value_compare(const Card& a);	//Function to compare two cards values (helps with score calculating)

	const char get_value() const ;		//Get Value of card

	const char get_suit() const;		//Get Suit of card

	void set_value(char _value);

	void set_suit(char _suit);

	void display_card();				//Display Card

	void display_value();				//Display Value of Card

	void display_suit();				//Display Suit of Card

	friend std::ostream& operator<<(std::ostream &os, const Card& a);  //operator for cout << (card) //makes displaying a card easier.

	friend void operator<<(std::ostream &os, const Card * a); //Operator for printing out arrays of cards.

};

Card::Card()
{
	
}

Card::Card(char _value, char _suit)		//Constructor
{
	if(suit != 'S' || suit != 'C' || suit != 'D' || suit != 'H')

	value = _value;
	suit = _suit; 
}

Card::~Card()							//Destructor
{

}

Card::Card(const Card& a) 				//Copy Constructor
{
	value = a.value;
	suit = a.suit;
}

Card& Card:: operator=(const Card& a) 	//Assigment Operator
{
	value = a.value;
	suit = a.suit;

	return *this;
}

bool Card::operator==(const Card& a) 	//Comparitive operator will compare two cards.
{
	if(a.value == value && a.suit == suit)
		return true;
	else 
		return false;
}

bool Card::compare(const Card& a)		
{
	if(a.value == value && a.suit == suit)
		return true;
	else
		return false;
}

bool Card::suit_compare(const Card& a) 	//Compare function to compare two suits of a card.
{
	if(suit == a.suit)
		return true;
	else 
		return false;

}

bool Card::value_compare(const Card& a) //Compare function to compare two values of a card.
{
	if(value == a.value)
		return true;
	else
		return false;
}

const char Card::get_value() const
{
	return value;
}

const char Card::get_suit() const
{
	return suit;
}

void Card::set_value(char _value)
{	
	value = _value;
}

void Card::set_suit(char _suit)
{
	suit = _suit;
}

void Card::display_card() 				//Function to display card to console
{
	std::cout << value;
	std::cout << suit;
}

void Card::display_suit()
{
	std::cout << suit;
}

void Card::display_value()
{
	std::cout << value;
}

std::ostream& operator<<(std::ostream &os, const Card& a)
{
	return os << a.value << a.suit;
}

void operator<<(std::ostream &os, const Card * a)						//For cout << (array of Cards)
{
	for(int i = 0; i < 25; i++)
	{
		std::cout << (a+i) -> value << (a+i) -> suit << "\n" ;
	}
}




















