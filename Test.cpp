#include "doctest.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

TEST_CASE("Good Constructors"){
	for(int i =0; i<5; i++){
		std::string name1(((unsigned long)i*10), 'a');
		std::string name2(((unsigned long)i*10), 'b');
		CHECK_NOTHROW(new Player(name1));
		CHECK_NOTHROW(new Player(name2));
		Player p1(name1);
		Player p2(name2);
		
		CHECK_NOTHROW(new Game(name1, name2));
	}
}


TEST_CASE("Good Inputs"){
	CHECK_NOTHROW(new Player("Alice"));
	CHECK_NOTHROW(new Player("Bob"));
	
	Player p1("Alice");
	Player p2("Bob");
	
	CHECK_NOTHROW(new Game(p1,p2));
}	

TEST_CASE("Bad Inputs"){
	CHECK_NOTHROW(Player p1("Alice"));
	Player p1("Alice");
	
	CHECK_THROWS(new Player(""));
	Player p2("");
	Player p3("");
	CHECK_THROWS(new Game(p1, p2));
	CHECK_THROWS(new Game(p2, p1));
	CHECK_THROWS(new Game(p2, p3));
}

TEST_CASE("Same Inputs Names"){
	CHECK_NOTHROW(Player p1("Alice"));
	CHECK_NOTHROW(Player p2("Alice"));
	Player p1("Alice");
	Player p2("Alice");
	
	CHECK_THROWS(new Game(p1, p2));
	
}

TEST_CASE("Not Possible Situation"){
	Player p("Alice");
	CHECK_THROWS(new Game(p, p));
}

TEST_CASE("Player can't join another game while he play"){
	Player p1("Alice");
	Player p2("Bob");
	Player pTry("Carl");
	
	Game game(p1,p2); 
	for (int i=0;i<1;i++) {
    		game.playTurn();
   	} //the game didn't finished yet after 1 turns
	
	CHECK_THROWS(new Game(p1, p2));
	CHECK_THROWS(new Game(p1, pTry));
	CHECK_THROWS(new Game(pTry, p2));
}


TEST_CASE("Last turn can't be print if game hasn't start yet"){
	Player p1("Alice");
	Player p2("Bob");
	
	Game game(p1,p2);
	
	CHECK_NOTHROW(game.printLastTurn());
}

TEST_CASE("Before the end of the game, there is not a winner"){
	Player p1("Alice");
	Player p2("Bob");
	
	Game game(p1,p2);
	
	Game newGame(p1,p2); 
	for (int i=0;i<1;i++) {
    		game.playTurn();
   	} //the game didn't finished yet after 1 turns
	
	CHECK_NOTHROW(game.printWiner());
}




