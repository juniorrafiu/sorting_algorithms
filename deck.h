#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>

/**
 * enum kind_e - different suits of cards
 * @SPADE: spade
 * @HEART: heart
 * @CLUB: club
 * @DIAMOND: diamond
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - card
 * @value: value of card
 * @kind: kind of card
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - deck of cards
 * @card: card of current node
 * @prev: previous node of the list
 * @next: next node of the list
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
int card_value(deck_node_t *node);
int _strcmp(const char *s1, const char *s2);
size_t list_len_deck(deck_node_t *list);

#endif
