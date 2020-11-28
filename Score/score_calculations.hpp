				
// 1 - Royal Flush

bool royal_flush(Card Cards[7])
{
	//Royal Flush is A, K, Q, J, 10 of all the same suit.

	Card royal_flush[5]; //Create an array of cards for the royal flush to fill up.

	for(int i = 0; i < 5; i++)
	{
		royal_flush[i].set_value('N');
		royal_flush[i].set_suit('N');
	}

	//Check that the cards are A, K, Q, J and T. 

	for(int i = 0; i < 7; i++)
	{
		if(Cards[i].get_value() == 'A')
		{
			royal_flush[0] = Cards[i];
		}

		if(Cards[i].get_value() == 'K')
		{
			royal_flush[1] = Cards[i];
		}

		if(Cards[i].get_value() == 'Q')
		{
			royal_flush[2] = Cards[i];
		}

		if(Cards[i].get_value() == 'J')
		{
			royal_flush[3] = Cards[i];
		}

		if(Cards[i].get_value() == 'T')
		{
			royal_flush[4] = Cards[i];
		}

	}

	for(int i = 0; i < 5; i++)
	{
		if(royal_flush[0].get_suit() != royal_flush[i].get_suit())
			return false;
		else if(royal_flush[i].get_suit() == 'N')
			return false;
	}

	return true;

}

// 2 - Straight Flush

bool straight_flush(Card Cards[7])
{
	Card straight_flush[5][3];

	char ordered_vals[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

	int count = 0;

	int array_flag = 0;

	//A straight flush is 5 Cards that are in a sequence that are of the same suit.
	//A sequence is 5 cards which values are in a row.
	//Go through each card to see if it has 4 Cards with the corresponding values above it.
	//First check 

	/* 

	*/

	for(int i = 0; i < 7; i++)
	{
		for(int z = 0; z < 13; z++)
		{
			if(Cards[i].get_value() == ordered_vals[z])
			{
				for(int c = 0; c < 7; c++)
				{
					if(c != i && Cards[c].get_value() == ordered_vals[z+1])
					{
						for(int d = 0; d < 7; d++)
						{
							if(d != c && d != i && Cards[d].get_value() == ordered_vals[z+2])
							{
								for(int e = 0; e < 7; e++)
								{
									if( e != d && e != c && e != i && Cards[e].get_value() == ordered_vals[z+3])
									{
										for(int f = 0; f < 7; f++)
										{
											if(f != e && f != d && f !=c && f != i && Cards[f].get_value() == ordered_vals[z+4])
											{
												//std::cout << Cards[i] << " " << Cards[c] << " " << Cards[d] << " " << Cards[e] << " " << Cards[f] << "\n";

												straight_flush[0][count] = Cards[i];
												straight_flush[1][count] = Cards[c];
												straight_flush[2][count] = Cards[d];
												straight_flush[3][count] = Cards[e];
												straight_flush[4][count] = Cards[f];

												count++;

												

											}
										}
									}	
								}
							}
						}
					}
				}
			}
		}
	}

	if(straight_flush[0][0].get_value() > straight_flush[0][1].get_value() && straight_flush[0][0].get_value() > straight_flush[0][2].get_value())
	{
		array_flag = 0;
	}

	if(straight_flush[0][1].get_value() > straight_flush[0][0].get_value() && straight_flush[0][1].get_value() > straight_flush[0][2].get_value())
	{
		array_flag = 1;
	}

	if(straight_flush[0][2].get_value() > straight_flush[0][1].get_value() && straight_flush[0][2].get_value() > straight_flush[0][0].get_value())
	{
		array_flag = 2;
	}

	//std::cout << array_flag;

	for(int i = 0; i < 5; i++)
	{
		if( straight_flush[0][array_flag].get_suit() != straight_flush[i][array_flag].get_suit())
		{
			return false;
		}
	}

	return true;
}

// 3 - Four of a Kind

bool four_of_a_kind(Card Cards[7])
{
	Card four_of_a_kind[4];

	//Four of a kind is four cards with the same value.
	//This function will return true if it finds four cards with the same value ie AS, AD, AH and AC = 1

	for(int a = 0; a < 7; a++)
	{
		for(int b = 0; b < 7; b++)
		{
			if(b != a && Cards[a].get_value() == Cards[b].get_value())
			{
				for(int c = 0; c < 7; c++)
				{
					if(c != a && c != b && Cards[c].get_value() == Cards[b].get_value())
					{
						for(int d = 0; d < 7; d++)
						{
							if(d != c && d != b && d != a && Cards[d].get_value() == Cards[c].get_value())
							{
								four_of_a_kind[0] = Cards[a];
								four_of_a_kind[1] = Cards[b];
								four_of_a_kind[2] = Cards[c];
								four_of_a_kind[3] = Cards[d];
								return true;
								//std::cout << four_of_a_kind[0] << " " << four_of_a_kind[1] << " " << four_of_a_kind[2] << " " << four_of_a_kind[3] << "\n";
							}
						}
					}
				}
			}
		}
	}

	return false;

}

// 4 - Full House

bool full_house(Card Cards[7])
{
	//A full house is a Pair and a Three of a kind.
	// AD, AH and KH, KD and KC = 1.
	//The pair can be of any value and the three of a kind can be of any value.

	Card full_house[5][2];
	Card pair_array[2][6];

	for(int i = 0; i < 2; i++)
	{
		for(int z = 0; z < 6; z++)
		{
			pair_array[i][z].set_value('N');
			pair_array[i][z].set_suit('N');
		}
	}

	for(int i = 0; i < 5; i++)
	{
		full_house[i][0].set_value('N');
		full_house[i][0].set_suit('N');

		full_house[i][1].set_value('N');
		full_house[i][1].set_suit('N');
	} 

	int count = 0; 
	int count2 = 0;
 
	//First search for Three of a kind.
	for(int a = 0; a < 7; a++)
	{
		for(int b = 0; b < 7; b++)
		{
			if(b != a && Cards[a].get_value() == Cards[b].get_value())
			{
				for(int c = 0; c < 7; c++)
				{
					if(c != b && c != a && Cards[c].get_value() == Cards[b].get_value())
					{
						for(int d = 0; d < 7; d++)
						{
							if(d != c && d != b && d != a && Cards[d].get_value() == Cards[c].get_value())
							{
								//The hand is a four of a kind and therefore not a full house so false needs to be returned
								
								//std::cout << Cards[a] << " " << Cards[b] << " " << Cards[c] << " " << Cards[d];

								return false;
							}
						}

						//Three of a kind has been found, so these cards can go into the array.

						full_house[0][count] = Cards[a];
						full_house[1][count] = Cards[b];
						full_house[2][count] = Cards[c];

						for(int i = 0; i < count; i++)
						{
							//std::cout << full_house[0][count] << " " << full_house[1][count] << " " << full_house[2][count]<< "\n";
						}

						count++;
					}
				}
			}
		}
	}
	

	for(int x = 0; x < 7; x++)
	{
		for(int y = 0; y < 7; y++)
		{
			if(y != x && Cards[x].get_value() != full_house[0][0].get_value() && Cards[x].get_value() != full_house[0][1].get_value() && Cards[x].get_value() == Cards[y].get_value())
			{
				//This is a pair however we need the highest pair to be added to the array

				//std::cout << Cards[x] << " " <<Cards[y] << "\n";

				pair_array[0][count2] = Cards[x];
				pair_array[1][count2] = Cards[y];
				
				count2++;
			}
		}
	}
	//Now the Pair needs to be found in order to make it a full house.

	// for(int x = 0; x < count2; x++)
	// {
	// 	std::cout << pair_array[0][x] << " " << pair_array[1][x] << "\n";
	// } 
	Card biggest_pair[2];

	biggest_pair[0] = pair_array[0][0];
	biggest_pair[1] = pair_array[1][0];

	for(int i = 0; i < count2; i++)
	{
		//std::cout << pair_array[0][i] << " " << pair_array[1][i] << "\n";
 
		if(pair_array[0][i] > biggest_pair[0])
		{
			biggest_pair[0] = pair_array[0][i];
			biggest_pair[1] = pair_array[1][i];
		}
	}

	//std::cout << biggest_pair[0] << " " << biggest_pair[1] << " ";

	full_house[3][0] = biggest_pair[0];
	full_house[4][0] = biggest_pair[1];
	full_house[3][1] = biggest_pair[0];
	full_house[4][1] = biggest_pair[1];

	for(int i = 0; i < 5; i++)
	{
		if(full_house[i][0].get_value() == 'N')
		{
			return false;
		}
	}

return true;
}

// 5 - Flush

bool flush(Card Cards[7])
{
	//A flush is any hand with 5 cards of the same suit

	Card flush[5];

	for(int a = 0; a < 7; a++)
	{
		for(int b = 0; b < 7; b++)
		{
			if(b != a && Cards[a].get_suit() == Cards[b].get_suit())
			{
				for(int c = 0; c < 7; c++)
				{
					if(c != b && c != a && Cards[b].get_suit() == Cards[c].get_suit())
					{
						for(int d = 0; d < 7; d++)
						{
							if(d != c && d != b && d!= a && Cards[c].get_suit() == Cards[d].get_suit())
							{
								for(int e = 0; e < 7; e++)
								{
									if(e != d && e != c && e != b && e != a && Cards[d].get_suit() == Cards[e].get_suit())
									{
										flush[0] = Cards[a]; 
										flush[1] = Cards[b];
										flush[2] = Cards[c];
										flush[3] = Cards[d];
										flush[4] = Cards[e];

										return true;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return false;
}

// 6 - Straight

bool straight(Card Cards[7])
{
	char ordered_vals[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	Card straight[5][3];
	int count = 0;

	//A straight is any 5 cards that values are in a sequence.


	for(int i = 0; i < 7; i++)
	{
		for(int z = 0; z < 13; z++)
		{
			if(Cards[i].get_value() == ordered_vals[z])
			{
				for(int c = 0; c < 7; c++)
				{
					if(c != i && Cards[c].get_value() == ordered_vals[z+1])
					{
						for(int d = 0; d < 7; d++)
						{
							if(d != c && d != i && Cards[d].get_value() == ordered_vals[z+2])
							{
								for(int e = 0; e < 7; e++)
								{
									if( e != d && e != c && e != i && Cards[e].get_value() == ordered_vals[z+3])
									{
										for(int f = 0; f < 7; f++)
										{
											if(f != e && f != d && f !=c && f != i && Cards[f].get_value() == ordered_vals[z+4])
											{
												//std::cout << Cards[i] << " " << Cards[c] << " " << Cards[d] << " " << Cards[e] << " " << Cards[f] << "\n";

												straight[0][count] = Cards[i];
												straight[1][count] = Cards[c];
												straight[2][count] = Cards[d];
												straight[3][count] = Cards[e];
												straight[4][count] = Cards[f];

												count++;
												return true;

												

											}
										}
									}	
								}
							}
						}
					}
				}
			}
		}
	}
return false;
}

// 7 - Three of a Kind
bool three_of_a_kind(Card Cards[7])
{
	//A three of a kind is 3 cards of the same value.

	Card three_of_a_kind[3][2];
	int count = 0;

	for(int i = 0; i < 7; i++)
	{
		for(int b = 0; b < 7; b++)
		{
			if(b != i && Cards[i].get_value() == Cards[b].get_value())
			{
				for(int c = 0; c < 7; c++)
				{
					if(c != b && c != i && Cards[b].get_value() == Cards[c].get_value())
					{
						three_of_a_kind[0][count] = Cards[i];
						three_of_a_kind[1][count] = Cards[b];
						three_of_a_kind[2][count] = Cards[c];
						count++;
						return true;

					}
				}
			}
		}
	}
return false;
}

// 8 - Two Pair
bool two_pair(Card Cards[7])
{
	//A Two pair is two pairs.
	//find first pair
	Card first_pair[2][3];
	Card second_pair[2][3];
	int count = 0;
	int count2 = 0;

	for(int i = 0; i < 2; i++)
	{
		for(int z = 0; z < 3; z++)
		{
			first_pair[i][z].set_value('N');
			first_pair[i][z].set_suit('N');

			second_pair[i][z].set_value('N');
			second_pair[i][z].set_suit('N');
		}
	}

	for(int i = 0; i < 7; i++)
	{
		for(int z = 0; z < 7; z++)
		{
			if(z != i && Cards[i].get_value() == Cards[z].get_value())
			{
				first_pair[0][count] = Cards[i];
				first_pair[1][count] = Cards[z];
				//std::cout << first_pair[0][count] << " " << first_pair[1][count] << "\n";
				count++;
			}
		}
	}

	for(int i = 0; i < 7; i++)
	{
		for(int z = 0; z < 7; z++)
		{
			if(z != i && Cards[i].get_value() != first_pair[0][0].get_value() && Cards[i].get_value() == Cards[z].get_value())
			{
				second_pair[0][count2] = Cards[i];
				second_pair[1][count2] = Cards[z];
				//std::cout << second_pair[0][count2] << " second pair" << second_pair[1][count2] << "\n";
				count2++;
			}
		}
	}
	//std::cout << first_pair[0][0] << first_pair[1][0] << "\n" ;
	//std::cout << second_pair[0][0] << second_pair[1][0] << "\n" ;

	for(int i = 0; i < 2; i++)
	{
		if(first_pair[i][0].get_value() == 'N')
		{
			return false;
		}

		if(second_pair[i][0].get_value() == 'N')
		{
			return false;
			
		}
	}

return true;
}

// 9 - Pair
bool pair(Card Cards[7])
{
	//A pair is two cards of the same value.

	Card first_pair[2][4];
	int count = 0; 

	for(int i = 0; i < 2; i++)
	{
		for(int z = 0; z < 4; z++)
		{
			first_pair[i][z].set_value('N');
			first_pair[i][z].set_suit('N');
		}
	}

	for(int i = 0; i < 7; i++)
	{
		for(int z = 0; z < 7; z++)
		{
			if(i != z && Cards[i].get_value() == Cards[z].get_value())
			{
				first_pair[0][count] = Cards[i];
				first_pair[1][count] = Cards[z];
				count++;
			}
		}
	}

	for(int i = 0; i < 2; i++)
	{
		if(first_pair[i][0].get_value() == 'N')
		{
			return false;
		}
	}

return true;
}

// 10 - High Card
bool high_card(Card Cards[7])
{
return true;
}