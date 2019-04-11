Go_Fish: go_fish.cpp card.o deck.o player.o
	g++ -g -o Go_Fish go_fish.cpp card.o deck.o player.o
card.o: card.cpp
	g++ -g -c card.cpp
deck.o: deck.cpp
	g++ -g -c deck.cpp
player.o: player.cpp
	g++ -g -c player.cpp
