# All cpp files here.
BASE=Player.cpp Dealer.cpp PlayingCard.cpp BlackJackHand.cpp PlayingCardDeck.cpp
PLAYER=PlayerTest.cpp
DEALER=DealerTest.cpp
GAME=BlackJackGame.cpp
COMP=clang++ -Wall -Wextra -Werror -std=c++11 $(BASE)
CONSOLE=kitty --hold ./
# Additional files including hpp etc.
ALL=$(BASE) $(PLAYER) $(DEALER) $(GAME) #Dealer.hpp # All other files go here.
# Output file name.

setup:
	touch $(ALL)

tags: $(ALL)
	rm tags
	ctags $(ALL)

player: $(PLAYER)
	$(COMP) $(PLAYER) -o playertest
	$(CONSOLE)playertest

dealer: $(DEALER)
	$(COMP) $(DEALER) -o dealertest
	$(CONSOLE)dealertest

game: $(GAME)
	$(COMP) $(GAME) -o gametest
	$(CONSOLE)gametest

t: $(OUT)
	clear
	kitty --hold ./$(OUT)

r:
	clear
	./$(OUT)
