#ifndef BOARD
#define BOARD

#include "space.h"
#include <stdlib.h>
#include <time.h>

#define DEFAULT_BOARD_SIZE 10
#define DEFAULT_NUM_BOMBS 10

class CBoard {
public:

  // Constructor
  // Creates new board with dimensions uiSize x uiSize
  // Randomly plants <uiBombs> bombs into the board
  // Dynamically creates CSpaces, which are deleted in the destructor
  CBoard(unsigned int uiSize = DEFAULT_BOARD_SIZE, unsigned int uiBombs = DEFAULT_NUM_BOMBS);

  // Desctructor
  // Clears m_spaces
  ~CBoard();

  char** Dump();
private:

  // populateBoard()
  // Generates the board based on provided parameters
  // Generates bomb locations
  // Places bombs in their given locations
  void populateBoard();

  CSpace **m_spaces;  // 2d array representing all spaces of the board
  unsigned int m_uiBombs; // the number of bombs present on the board
  unsigned int m_uiSideLen; // the length of each side of the board
};

#endif
