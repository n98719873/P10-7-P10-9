#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct card
{
	const char *face;//定義face(牌面大小)
	const char *suit;//定義suit(花色)
};

typedef struct card Card;//給予結構一個的名稱

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
	srand(time(NULL));//亂數
	fillDeck(deck, face, suit);//填滿覆蓋的牌(給予牌值)
	shuffle(deck);//以隨機順序放置(洗牌)
	deal(deck);//發牌

	system("pause");
	return 0;
}

void fillDeck(Card *const wDeck, const char *wFace[], const char *wSuit[])
{//將花色及大小填入
	int i;
	for (i = 0; i <= 51; i++)
	{
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	}
}

void shuffle(Card * const wDeck)
{//洗牌
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
{//發牌
	int i;
	for (i = 0; i <= 51; i++)
	{
		printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? " " : "\n");
	}
}