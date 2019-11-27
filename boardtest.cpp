#include "board.h"
#include <iostream>
using namespace std;
int main()
{
  CBoard myBoard;
  char** boardStr = myBoard.Dump();

  for (int i = 0; i < DEFAULT_BOARD_SIZE; i++)
  {
    cout << boardStr[i] << endl;
  }

  for (int i = 0; i < DEFAULT_BOARD_SIZE; i++)
  {
    delete [] boardStr[i];
  }
  delete [] boardStr;

  return 0;
}
