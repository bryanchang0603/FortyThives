#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include "CardTypes.h"
#include "CardStack.h"

typedef CardStackT SeqCrdStckT[];

using namespace std;
class BoardT {
public:
	BoardT(CardT s[]);
	bool is_valid_tab_mv(CategoryT c, unsigned int n0, unsigned int n1);
	bool is_valid_waste_mv(CategoryT, unsigned int n);
	bool is_valid_deck_mv();
	void tab_mv(CategoryT c, unsigned int n0, unsigned int n1);
	void waste_mv(CategoryT c, unsigned int n);
	void deck_mv();
	CardStackT get_tab(unsigned int n);
	CardStackT get_foundation(unsigned int n);
	CardStackT get_deck();
	CardStackT get_waste();
	bool valid_mv_exists();
	bool is_win_state();
private:
	SeqCrdStckT T, F;
	CardStackT W, D;
	bool two_decks(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W);
	unsigned int cnt_cards_seq(SeqCrdStckT S, const bool& f);
	unsigned int cnt_cards_stack(CardStackT s, const bool& f);
	unsigned int cnt_cards(SeqCrdStckT T, SeqCrdStckT F, CardStackT D,
			CardStackT W, const bool& f);
	SeqCrdStckT init_seq(unsigned int n);
	SeqCrdStckT tab_deck(vector<CardT> deck);
	bool is_valid_pos(CategoryT c, unsigned int n);
	bool valid_tab_tab(unsigned int n0, unsigned int n1);
	bool valid_tab_foundation(unsigned int n0, unsigned int n1);
	bool valid_waste_tab(unsigned int n);
	bool valid_waste_foundation(unsigned int n);
	bool tab_placeable(CardT c, CardT d);
	bool foundation_placeable(CardT c, CardT d);
};

#endif
