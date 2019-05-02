
//--------------------------------------------------------------------//
//																	  //
//			The Score class - Used to keep a players score	  		  //
//																	  // 
//--------------------------------------------------------------------//

//Copyright: Matthew Haywood

//The score class will be used to hold the value of a score
//Extra functions will also be used to calculate the score of a player.


class Score
{

private:

//private data
	float score;

public:

	Score(); 							//constructor

	~Score();							//Destructor

	Score(const Score& a);				//Copy Constructor

	Score& operator=(const Score& a);	//Assigment Operator

	float Calculate_Score(Table& _table, Player& _player);

};

Score::Score()
{
	float score = 0;
}

Score::~Score()
{

}

Score::Score(const Score& a)
{
	float score = score;
}

Score& Score:: operator=(const Score& a)
{
	return *this;
}

float Score::Calculate_Score(Table& _table, Player& _player)
{
	Card Players_Cards[7];
	Players_Cards[0] = _player.get_hand().get_A();
	Players_Cards[1] = _player.get_hand().get_B();
	Players_Cards[2] = _table.get_Flop()[0];
	Players_Cards[3] = _table.get_Flop()[1];
	Players_Cards[4] = _table.get_Flop()[3];
	Players_Cards[5] = _table.get_River()[0];
	Players_Cards[6] = _table.get_River()[1];

	std::cout << Players_Cards[3];

	return 0;
}
