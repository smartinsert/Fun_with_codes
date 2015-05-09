#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

using namespace std;

// General suits in a deck of cards
vector<string> suits = {"Club", "Diamond", "Heart", "Spade"};
// generic rankings of the cards
vector<string> ranks = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
// generic values to the ranks
unordered_map<string,int> values = {{"A", 1}, {"2",2}, {"3", 3}, {"4",4}, {"5",5}, 
				    {"6",6}, {"7",7}, {"8",8}, {"9",9}, {"10",10}, 
				    {"J",10}, {"Q",10}, {"K",10}};
struct card
{
	string suit;
	string rank;
	card(string s, string r) : suit(s), rank(r){}
};

class deck
{
	private:
	vector<card> cards; // each vector element now has two values(suits and rank)
	
	public:
	deck() // populate the deck of cards
	{
		for (auto si=suits.cbegin(); si != suits.cend(); ++si) // 4 
			for (auto ri=ranks.cbegin(); ri != ranks.cend(); ++ri) // 13
				cards.push_back(card(*si,*ri)); // 52
	}

	void shuffle()
	{
		random_shuffle(cards.begin(), cards.end());
	}

	card deal_card()
	{
		// Since we cannot both access and remove the top element in the vector
		// for convenience sake consider the dealt card is the last one
		card result = cards.back();
		cards.pop_back();
		return result;
	}
	
	void print_deck()
        {
                for (auto vi=cards.cbegin(); vi!=cards.cend(); ++vi)
                        cout << (*vi).suit << " " << (*vi).rank << " ";
                cout << endl;
        }

};


// class to represent the hands of members in the game
class hand
{
	private:
	vector<card> cards;
	
	public:
	void add_card(card c)
	{
		cards.push_back(c);
	}

	int get_value()
	{
		int value=0, has_ace=0;
		// const card iterator to just access the members of the card struct
		for (auto card=cards.cbegin(); card!=cards.cend(); ++card)
		{
			value+=values[(*card).rank];
			if ((*card).rank == "A")
				has_ace=1;
		}
		if (has_ace && value < 12) // if the queried value is less than 12 and the player has an ace 
			value+=10; // make the ace count as 11
		return value;
	}

	string print_cards()
	{
		
		string result = "";
		for (auto ci=cards.cbegin(); ci!=cards.cend(); ++ci)
			result+= (*ci).suit + " " + (*ci).rank + " ";
		return result;
	}

}; 
int main()
{
	srand(unsigned(time(0))); // time(0) seed value to the pseudo random number generator
	cout << endl << "-----------------Black Jack-----------------------" << endl;
	cout << " Game Starts! " << endl;
	bool newgame = true; // boolean to check the HIT 
	bool inplay = true; // boolean to change the state 
	char input;
	while(newgame)
	{
		deck dk; // Instance for the deck of cards
		hand player, dealer; // Instance for a player and a dealer respectively
	  	// Add two cards each one by one for dealer and player
		dk.shuffle();
		player.add_card(dk.deal_card());
		dealer.add_card(dk.deal_card());
		player.add_card(dk.deal_card());	
		dealer.add_card(dk.deal_card());
		cout << " You have : " <<  player.print_cards() << endl;
		while (inplay)
		{
			cout << " Hit(h) or Stand(s) ? ";
			cin >> input;
			if (input == 'h') 
			{
				player.add_card(dk.deal_card());
				cout << "You have : " << player.print_cards()  << endl;
				if (player.get_value() > 21)
				{
					cout << "You've been busted ... Dealer Wins !" << endl;
					inplay = false;
				}
			}
			else if (input == 's')
			{
				while (dealer.get_value() < 17)
					dealer.add_card(dk.deal_card());
				cout << "Dealer has : " << dealer.print_cards() << endl;
				if (dealer.get_value() > 21)
					cout << " Dealer is busted ... You Win !" << endl;
				else if (dealer.get_value() > player.get_value())
					cout << " Dealer Wins !" << endl;
				else
					cout << "You Win " << endl;
				inplay=false;
			}
			else
				cout << "Invalid Input! Hit(h) or Stand(s) ? ";  
		}
		input = ' ';
		while (!inplay)
		{
			cout << "New Game? (y/n) ";
			cin>>input;
		//	dk.shuffle();
		//	dk.print_deck();
			if (input == 'y') 
				inplay=true;
			else if (input == 'n')
			{
				inplay = false;
			 	newgame = false;
				exit(0);
			}
			else
				cout << endl <<"Invalid Input! New Game ? (y or n) ";
		}
	}
	return 0;
} 
