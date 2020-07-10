#include "../include/GameBoard.h"

#include <vector>

#include "../include/Stack.h"

bool BoardT::foundation_placeable(CardT c, CardT d) {
	return (c.s == d.s && c.r == d.r + 1);
}

bool BoardT::tab_placeable(CardT c, CardT d) {
	return (c.s == d.s && c.r == d.r - 1);
}

bool BoardT::valid_waste_foundation(unsigned int n) {
	if (this->F[n].size() > 0)
		return foundation_placeable(this->W.top(), this->F[n].top());
	else if (this->F[n].size() == 0)
		return (this->W.top().r == ACE);
	return false;
}

bool BoardT::valid_waste_tab(unsigned int n) {
	if (this->T[n].size() > 0)
		return tab_placeable(this->W.top(), this->T[n].top());
	else if (this->T[n].size() == 0)
		return true;
	return false;
}

bool BoardT::valid_tab_foundation(unsigned int n0, unsigned int n1) {
	if (this->T[n0].size() > 0) {
		if (this->F[n1].size() > 0)
			return foundation_placeable(this->T[n0].top(), this->F[n1].top());
		else if (this->F[n0].size == 0)
			return (this->T[n0].top().r == ACE);
	} else
		return false;
	return false;
}

bool BoardT::valid_tab_tab(unsigned int n0, unsigned int n1) {
	if (this->T[n0].size() > 0) {
		if (this->T[n1].size() > 0)
			return foundation_placeable(this->T[n0].top(), this->T[n1].top());
		else if (this->T[n0].size == 0)
			return true;
	} else
		return false;
	return false;
}

bool BoardT::is_valid_pos(CategoryT c, unsigned int n) {
	if (c == Tableau) {
		return (n >= 0 && n < 10);
	} else if (c == Foundation) {
		return (n >= 0 && n < 8);
	}
	return true;
}

SeqCrdStckT BoardT::tab_deck(vector<CardT> deck) {
	CardStackT s[10] = { };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			s[i].push(deck[4 * 1 + j]);
		}
	}
	return s;
}

SeqCrdStckT BoardT::init_seq(unsigned int n) {
	CardStackT s[n] = {};
	for(auto i:s){
		i = CardStackT();
	}
	return s;
}

unsigned int BoardT::cnt_cards_stack(CardStackT s, const bool& f) {
	CardT tempCardArray[] = s.toSeq();
	unsigned int stack_count = 0;
	for (auto i : tempCardArray) {
		if (f(i)) {
			stack_count++;
		}
	}
	return stack_count;
}

unsigned int BoardT::cnt_cards_seq(SeqCrdStckT S, const bool& f) {
	unsigned int seq_count = 0;
	for (auto s : S) {
		seq_count += cnt_cards_stack(s, f);
	}
	return seq_count;
}

unsigned int BoardT::cnt_cards(SeqCrdStckT T, SeqCrdStckT F, CardStackT D,
		CardStackT W, const bool& f) {
	unsigned int count = 0;
	count += cnt_cards_seq(T, f);
	count += cnt_cards_seq(F, f);
	count += cnt_cards_stack(D, f);
	count += cnt_cards_stack(W, f);
	return count;
}

bool BoardT::two_decks(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W) {
	for (int s = Heart; s <= Spade; s++) {
		for (int r = ACE; r <= KING ; r++) {
			if (cnt_cards(T, F, D, W,
					[](CardT in) {return in.r == r && in.s == s;}) != 2) {
				return false;
			}

		}
	}
	return true;
}

BoardT::BoardT(CardT deck[]){
	if(!two_decks(init_seq(10), init_seq(8), CardStackT(deck),CardStackT())){
		throw std::invalid_argument("deck not valid");
	}

	vector<CardT> TableauCard;
	vector<CardT> DeckCard;
	for(int i = 0 ; i < 40; i++){
		TableauCard.push_back(deck[i]);
	}
	for(int i = 40; i < 104; i++){
		DeckCard.push_back(deck[i]);
	}
	this->T = tab_deck(TableauCard);
	this->F = init_seq(8);
	this->D = CardStackT(DeckCard);
	this->W = CardStackT(empty);
}

bool BoardT::is_win_state(){
	for(int i = 0; i < 8; i++){
		if (!(this->F[i].size() > 0 && F[i].top() == KING)){
			return false;
		}
	}
	return true;
}
