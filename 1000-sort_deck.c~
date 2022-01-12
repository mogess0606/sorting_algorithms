#include "deck.h"
int (*cmp_cards)(const card_t *, const card_t *);
void insertion_sort_list(deck_node_t **list);
void sort_deck(deck_node_t **deck)
{
	
}
int (*cmp_cards)(const card_t *c1, const card_t *c2)
{
	int res = 0;

	if (
}
void insertion_sort_list(deck_node_t **list,
			 int (*cmp_cards)(const card_t *, const card_t *))
{
        deck_node_t *cand = NULL, *p = NULL, *nc = NULL, *np = NULL;

	if (!list || !*list || !(*list)->next)
		return;
	nc = *list;
	for (cand = (*list)->next; nc; cand = nc)
	{
		nc = cand->next;
		np = cand;
		for (p = cand->prev; np; p = np)
		{
			np = p->prev;
			if (cmp_cards(cand, p) == -1)
			{
				cand->prev = p->prev;
				p->next = cand->next;
				if (p->prev)
					p->prev->next = cand;
				if (cand->next)
					cand->next->prev = p;
				p->prev = cand;
				cand->next = p;
				if (!cand->prev)
					*list = cand;
				print_list(*list);
			}
		}
	}
}
