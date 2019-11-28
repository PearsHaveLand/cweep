#include "board.h"
#include <iostream>
using namespace std;
int main()
{
  CBoard myBoard(10, 30);
  char** boardStr = myBoard.Dump();

  for (int i = 0; i < DEFAULT_BOARD_SIZE; i++)
  {
    cout << boardStr[i] << endl;
  }

  cout << "\n======================================\n";

  for (int i = 0; i < DEFAULT_BOARD_SIZE; i++)
  {
    for (int j = 0; j < DEFAULT_BOARD_SIZE; j++)
    {
      if (!myBoard.IsSpaceChecked(j, i))
      {
        cout << "?";
      }
    }
    cout << endl;
  }

  for (int i = 0; i < DEFAULT_BOARD_SIZE; i++)
  {
    delete [] boardStr[i];
  }
  delete [] boardStr;

  return 0;
}
