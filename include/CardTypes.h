/**
 * \file CardTypes.h
 * \author
 * \brief
 */
#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_


#define TOTAL_CARDS = 104
/**
 * \brief Describes the rank of a card.
 */
typedef unsigned short int RankT;

/**
 * \brief RankT for an Ace.
 */
#define ACE    1

/**
 * \brief RankT for an Jack.
 */
#define JACK   11

/**
 * \brief RankT for a Queen.
 */
#define QUEEN  12

/**
 * \brief RankT for a King.
 */
#define KING   13

enum SuitT {Heart, Diamond, Club, Spade};

enum CategoryT {Tableau, Foundation, Deck, Waste};

struct CardT{
	SuitT s;
	RankT r;
};

#endif
