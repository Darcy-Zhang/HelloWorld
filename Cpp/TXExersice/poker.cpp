/*
 * @Author       : Darcy
 * @Date         : 2021-03-30 11:11:45
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-03-31 21:33:56
 * @FilePath     : \HelloWorld\Cpp\TXExersice\poker.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const int COLOR = 4;
const int NUM = 13;
string RANKS[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
string SUITS[] = {"c", "d", "h", "s"};

class Poker
{
public:
   int rank;
   int suits;
   void init(void);
   void printcards(void);
   void shuffle(void);
};
Poker cards[52];
void Poker::init(void)
{
   int count = 0;
   for (int i = 0; i < 13; ++i)
      for (int n = 0; n < 4; ++n)
      {
         cards[count].rank = i;
         cards[count].suits = n;
         ++count;
      }
   return;
}

void Poker::printcards(void)
{
   for (int i = 0; i < 52; ++i)
   {
      cout << RANKS[cards[i].rank] << SUITS[cards[i].suits] << ' ';
   }
   return;
}

void Poker::shuffle(void)
{
   int random(void);
   int a, b;
   for (int i = 0; i < 1000; ++i)
   {
      a = rand() % 52;
      b = rand() % 52;
      swap(cards[a].rank, cards[b].rank);
      swap(cards[a].suits, cards[b].suits);
   }
   return;
}

int main()
{
   cards->init();
   cards->printcards();
   cout << endl;
   cards->shuffle();
   cards->printcards();
   cout << endl;
   return 0;
}