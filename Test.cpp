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







TEST_CASE("Same Inputs Names"){
	CHECK_NOTHROW(Player p1("Alice"));
	CHECK_NOTHROW(Player p2("Alice"));
	Player p1("Alice");
	Player p2("Alice");
	
}

TEST_CASE("didnt in a game"){
	Player p2("Alice");
	CHECK_THROWS(p2.cardesTaken());
	CHECK_THROWS(p2.cardesTaken());
	CHECK_THROWS(p2.cardesTaken());
	CHECK_THROWS(p2.cardesTaken());
	CHECK_THROWS(p2.cardesTaken());
}

TEST_CASE("Inputs Names"){
	CHECK_NOTHROW(Player p1("Alice"));
	CHECK_NOTHROW(Player p2("Alice"));
	Player p1("bob");
	Player p2("Alice");
	
}


TEST_CASE("Possible Situation"){
	Player p1("Alice");
	Player p2("bob");
	
	Game game(p1, p2);
	game.playAll();
	if(p1.cardesTaken() == p2.cardesTaken()){
		CHECK_THROWS(game.printWiner());
	}
	
	else {
		CHECK_NOTHROW(game.printWiner());
		CHECK_NOTHROW(game.printLog()); 
   		CHECK_NOTHROW(game.printStats());
	}
	
}

TEST_CASE("Not Possible Situation"){
	Player p1("Alice");
	Player p2("bob");
	
	Game game(p1, p2);
	game.playAll();
	CHECK_NOTHROW(game.printWiner());
	CHECK_NOTHROW(game.printLog()); 
	CHECK_NOTHROW(game.printStats());
	
}

TEST_CASE(" Situation"){
	Player p1("Alice");
	Player p2("bob");
	
	Game game(p1, p2);
	game.playAll();
	if(p1.cardesTaken() == p2.cardesTaken()){
		CHECK_THROWS(game.printWiner());
	}
	
	else {
		CHECK_NOTHROW(game.printWiner());
		CHECK_NOTHROW(game.printLog()); 
   		CHECK_NOTHROW(game.printStats());
	}
	
}
TEST_CASE("Ctos"){
	Player p1("Alice");
	Player p2("bob");
	
	Game game(p1, p2);
	game.playAll();
	CHECK_NOTHROW(game.printWiner());
	CHECK_NOTHROW(game.printLog()); 
	CHECK_NOTHROW(game.printStats());
	
}
TEST_CASE( "problem Situation"){
	Player p1("Alice");
	Player p2("bob");
	
	Game game(p1, p2);
	game.playAll();
	if(p1.cardesTaken() == p2.cardesTaken()){
		CHECK_THROWS(game.printWiner());
	}
	
	else {
		CHECK_NOTHROW(game.printWiner());
		CHECK_NOTHROW(game.printLog()); 
   		CHECK_NOTHROW(game.printStats());
	}
	
}
TEST_CASE("Possible Situation after winning"){
	Player p1("Alice");
	Player p2("bob");
	
	Game game(p1, p2);
	game.playAll();
	if(p1.cardesTaken() == p2.cardesTaken()){
		CHECK_THROWS(game.printWiner());
	}
	
	else {
		CHECK_NOTHROW(game.printWiner());
		CHECK_NOTHROW(game.printLog()); 
   		CHECK_NOTHROW(game.printStats());
	}
	
}
TEST_CASE("Possible Situ"){
	Player p1("Alice");
	Player p2("bob");
	
	Game game(p1, p2);
	game.playAll();
	CHECK_NOTHROW(game.printWiner());
	CHECK_NOTHROW(game.printLog()); 
	CHECK_NOTHROW(game.printStats());
	
}




