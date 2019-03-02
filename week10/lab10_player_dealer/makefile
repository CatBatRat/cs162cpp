#CC=PlayingCard.cpp PlayingCardDeck.cpp PlayingCardDeckTest.cpp
CC= BlackJackGame.cpp BlackJackHand.cpp PlayingCard.cpp PlayingCardDeck.cpp
HEADERS= BlackJackHand.h Dealer.h Player.h PlayingCardDeck.h PlayingCard.h
TESTS= PlayingCardTest.cpp BlackJackHandTest.cpp PlayerTest.cpp DealerTest.cpp PlayingCardDeckTest.cpp
ALL=$(CC) $(HEADERS) $(TESTS)
OUT=out

setup:
	touch $(ALL)

tags: $(ALL)
	ctags $(ALL)

c: $(CC)
	clang++ -Wall -Wextra -Werror -std=c++11 $(CC) $(TESTS) -o $(OUT)

cd: $(CC)
	clang++ -d -Wall -Wextra -Werror -std=c++11 $(CC) $(TESTS) -o $(OUT)

rd: $(OUT)
	gdb $(OUT)

t: $(OUT)
	clear
	kitty --hold ./$(OUT)

r:
	clear
	./$(OUT)
