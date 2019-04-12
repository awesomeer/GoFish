gofish: go_fish.cpp card.o deck.o player.o
	g++ -std=gnu++11 -g -o gofish go_fish.cpp card.o deck.o player.o
card.o: card.cpp
	g++ -std=gnu++11 -g -c card.cpp
deck.o: deck.cpp
	g++ -std=gnu++11 -g -c deck.cpp
player.o: player.cpp
	g++ -std=gnu++11 -g -c player.cpp
