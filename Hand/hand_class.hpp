
//--------------------------------------------------------------------//
//																	  //
//			The Hand Class - Holds two randomised card objects	  	  //
//																	  // 
//--------------------------------------------------------------------//

//Copyright: Matthew Haywood

//The Hand Class will consist of:
								
//							- Two card Objects which have been dealt randomly.

class Hand
{

private:

	Card A; //Card A

	Card B; //Card B

public:

	friend class Player;

	Hand(const Card& a, const Card& b); 						//Constructor

	Hand();

	~Hand();													//Destructor

	Hand(const Hand& a);										//Copy Constructor

	Hand& operator=(const Hand& a);								//Assigment Operator

	friend std::ostream& operator<<(std::ostream &os, const Hand& a);	//Operator for cout << (hand)

	Card& get_A();												//Get card function

	Card& get_B();												//Get card function

	void set_A(Card& _The_Card);								//Set A card function

	void set_B(Card& _The_Card);								//Set B card function

	void display_hand() const;									//Display hand to console function

};

Hand::Hand()
{
	A.suit = 'N';
	A.value = 'N';

	B.suit = 'N';
	B.value = 'N';
}

Hand::Hand(const Card& a, const Card& b)
{
	A.suit = a.suit;
	A.value = a.value;

	B.suit = b.suit;
	B.value = b.value;
}

Hand::~Hand()
{

}

Hand::Hand(const Hand& a)
{
	A.suit = a.A.suit;
	A.value = a.A.value;

	B.suit = a.B.suit;
	B.value = a.B.value;
}

Hand& Hand:: operator=(const Hand& a)
{
	A.suit = a.A.suit;
	A.value = a.A.value;

	B.suit = a.B.suit;
	B.value = a.B.value;

	return *this;
}

Card& Hand::get_A()
{
	return A;
}

Card& Hand::get_B()
{
	return B;
}

void Hand::set_A(Card& _The_Card)
{
	A = _The_Card;
}

void Hand::set_B(Card& _The_Card)
{
	B = _The_Card;
}

void Hand::display_hand() const
{
	std::cout << A.value << " " << A.suit;
	std::cout << B.value << " " << B.suit;
}

std::ostream& operator<<(std::ostream &os, const Hand& a)
{
	return std::cout << a.A << " " << a.B;
}

