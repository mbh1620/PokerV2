
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
	

	std::cout << Players_Cards[3];

	return 0;
}
