#ifndef BOARD
#define BOARD

#include "space.h"
#include <stdlib.h>	// contains srand
#include <time.h>		// used for seeding random numbers

#define DEFAULT_HEIGHT 16
#define DEFAULT_WIDTH 30
#define DEFAULT_NUM_BOMBS 130

class CBoard {
public:

  // Constructor
  // Creates new board with dimensions uiSize x uiSize
  // Randomly plants <uiBombs> bombs into the board
  // Dynamically creates CSpaces, which are deleted in the destructor
  CBoard(unsigned int uiHeight = DEFAULT_HEIGHT, unsigned int uiWidth = DEFAULT_WIDTH, unsigned int uiBombs = DEFAULT_NUM_BOMBS);

  // Destructor
  // Clears m_spaces
  ~CBoard();

  char** Dump();

  // IsSpaceChecked()
  // Peeks the space at the given coordinates
  // If the space has been "checked", return true
  // False if the space has not been checked
  bool IsSpaceChecked(unsigned int y, unsigned int x);

  // GetSpaceBomb()
  // Checks if the current space has a bomb
  // Returns true if bomb is present
  // Returns false if not
  bool GetSpaceBomb(unsigned int y, unsigned int x);

  // IsInBounds()
  // Checks if the given coordinates are in bounds in the board
  // Returns true if a valid board position
  // false if not
  bool IsInBounds(unsigned int y, unsigned int x);

  unsigned int GetWidth() {return m_uiWidth;}
  unsigned int GetHeight() {return m_uiHeight;}
  char **GetDisplay() {return m_display;}
	bool CheckSpace(unsigned int y, unsigned int x);
	bool IsCleared();

private:

  // populateBoard()
  // Generates the board based on provided parameters
  // Generates bomb locations
  // Places bombs in their given locations
  void populateBoard();

  CSpace **m_spaces;  // 2d array representing all spaces of the board
  char **m_display; // 2d array depicting the board in readable text
  unsigned int m_uiBombs; // the number of bombs present on the board
  unsigned int m_uiHeight; // the length of the vertical side of the board
  unsigned int m_uiWidth; // the length of the horizontal side of the board
	unsigned int m_uiSafeSpaces;	// The number of spaces not containing bombs
	unsigned int m_uiRevealedSpaces;	// The number of currently-revealed spaces
};

#endif
