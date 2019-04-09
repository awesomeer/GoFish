GoFish: card_demo.cpp card.o deck.o
	g++ -o GoFish card_demo.cpp card.o deck.o
card.o: card.cpp
	g++ -c card.cpp
deck.o: deck.cpp
	g++ -c deck.cpp
