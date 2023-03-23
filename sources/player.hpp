#pragma once
#include <string>

namespace ariel {
	class Player{ 
		public:
			Player(std::string);
			int stacksize();
			int cardesTaken();
			bool isPlayedBefore;
			
		
	};

};
	
