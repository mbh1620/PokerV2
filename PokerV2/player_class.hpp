
//--------------------------------------------------------------------//
//																	  //
//					Player Class - used as an agent  	   			  //
//																	  // 
//--------------------------------------------------------------------//

//Copyright: Matthew Haywood

//Player class will consist of:

// 							- A hand object (Two cards) which can be returned by other functions
//							- A score object
//							- A Balance object
//							- A current bet object
//							- An id number
//							- The Big Four	


class Player
{

private:

//private data
	Hand hand1;									//The players Hand which holds two cards

	int id;										//The Players Id.

	//int score;								//The players score for each round

	float balance;								//The players current balance.

	int player_bet; 							//The players current bet

	bool fold_flag;


public:

	friend class Table;

	Player();									//Constructor for creating arrays of players

	Player(int _id); 							//constructor for when no data is supplied

	Player(int _id, const Hand& a);				//constructor for when a hand is supplied

	~Player();									//Destructor

	Player(const Player& a);					//Copy Constructor

	Player& operator=(const Player& a);			//Assigment Operator

	Hand& get_hand();							//get hand function

	float get_balance();						//get_balance function to return players balance

	int get_id() const;							//get_id

	void set_balance(float balance);			//Set_balance

	void set_fold_flag(bool set_to);			//Set_fold_flag

	void display() const;						//Display player function

	friend std::ostream& operator<<(std::ostream &os, const Player& a);				//Operator for doing cout << (Player)

	friend std::ostream& operator<<(std::ostream &os, const Player* a);				//Operator for doing cout << (*Player)

	
};

Player::Player()
{
	score1.set_score(0);
	balance = 100.00;
	player_bet = 0;
	fold_flag = false;
}

Player::Player(int _id)								//Constructor
{
	id = _id;
	score1.set_score(0);
	balance = 100.00;
	player_bet = 0;
	fold_flag = false;

}

Player::Player(int _id, const Hand& a)				//Constructor for when a Hand is supplied
{
	id = _id;
	hand1 = a;
	score1.set_score(0);
	balance = 100.00;
	player_bet = 0;
	fold_flag = false;
}

Player::~Player()									//Destructor
{

}

Player::Player(const Player& a)						//Copy Constructor
{
	id = a.id;
	hand1 = a.hand1;
	//score = a.score;
	balance = a.balance;
	player_bet = a.player_bet;
	fold_flag = a.fold_flag;

}

Player& Player:: operator=(const Player& a)			//Asignment Operator.
{	
	id = a.id;
	hand1 = a.hand1;
	//score = a.score;
	balance = a.balance;
	player_bet = a.player_bet;
	fold_flag = a.fold_flag;


	return *this;
}

Hand& Player::get_hand()							//Get hand function.
{
	return hand1;
}

float Player::get_balance()
{
	return balance;
}

int Player::get_id() const
{
	return id;
}

void Player::set_balance(float _balance)
{
	balance = _balance;
}

void Player::set_fold_flag(bool set_to)
{
	fold_flag = set_to;
}

void Player::display() const
{
	std::cout << "Player: "<< id << "\n" << hand1 << "\nBalance: £" << balance << "\n" << score1.get_score() << "\n" << player_bet << "\n";
}

std::ostream& operator<<(std::ostream &os, const Player& a)
{
	return std::cout << "Player: "<< a.id << "\n" <<a.hand1 << "\nBalance: £" << a.balance << "\n" << a.score1.get_score() << "\n" << a.player_bet << "\n";
}

std::ostream& operator<<(std::ostream &os, const Player* a)
{
	return std::cout << "Player: " << a -> get_id();
}













