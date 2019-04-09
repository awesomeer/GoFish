GoFish: card_demo.cpp card.o deck.o player.o
	g++ -o GoFish card_demo.cpp card.o deck.o player.o
card.o: card.cpp
	g++ -c card.cpp
deck.o: deck.cpp
	g++ -c deck.cpp
player.o: player.cpp
	g++ -c player.cpp
