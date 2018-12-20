#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct card
{
	const char *face;//�w�qface(�P���j�p)
	const char *suit;//�w�qsuit(���)
};

typedef struct card Card;//�������c�@�Ӫ��W��

void fillDeck(Card * const wDeck, const char * wFace[],
	const char * wSuit[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);

int main(void)
{
	Card deck[52];

	const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
							"Six", "Seven", "Eight", "Nine", "Ten",
							"Jack", "Queen", "King" };

	const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	srand(time(NULL));//�ü�
	fillDeck(deck, face, suit);//���л\���P(�����P��)
	shuffle(deck);//�H�H�����ǩ�m(�~�P)
	deal(deck);//�o�P

	system("pause");
	return 0;
}

void fillDeck(Card *const wDeck, const char *wFace[], const char *wSuit[])
{//�N���Τj�p��J
	int i;
	for (i = 0; i <= 51; i++)
	{
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	}
}

void shuffle(Card * const wDeck)
{//�~�P
	int i, j;
	Card temp;
	for (i = 0; i <= 51; i++)
	{
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

void deal(const Card *const wDeck)
{//�o�P
	int i;
	for (i = 0; i <= 51; i++)
	{
		printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? " " : "\n");
	}
}