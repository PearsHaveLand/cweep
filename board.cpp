#include "board.h"

// Constructor
// Creates new board with dimensions uiSize x uiSize
// Randomly plants <uiBombs> bombs into the board
// Dynamically creates CSpaces, which are deleted in the destructor
CBoard::CBoard(unsigned int uiSize, unsigned int uiBombs) :
  m_uiBombs(uiBombs),
  m_uiSideLen(uiSize)
{
  // First, initialize the array of pointers
  m_spaces = new CSpace*[m_uiSideLen];

  // Then, initialize each row of spaces
  for (unsigned int i = 0; i < m_uiSideLen; i++)
  {
    m_spaces[i] = new CSpace[m_uiSideLen];
  }

  // Place bombs in board
  populateBoard();
}

// populateBoard()
// Generates the board based on provided parameters
// Generates bomb locations
// Places bombs in their given locations
void CBoard::populateBoard()
{
  unsigned int uiRandx, // Randomized coordinates for bombs
    uiRandy,            // Randomized coordinates for bombs
    uiPlacedBombs = 0;      // Current number of bombs placed on board

  // Seed random number generator
  srand(time(NULL));

  // Generate random bomb locations
  while (uiPlacedBombs < m_uiBombs)
  {
    // Generate random coordinates
    uiRandy = rand() % m_uiSideLen;
    uiRandx = rand() % m_uiSideLen;

    // If no bomb in space
    if (!m_spaces[uiRandy][uiRandx].GetBomb())
    {
      // Bomb is placed in space
      uiPlacedBombs++;
      m_spaces[uiRandy][uiRandx].SetBomb(true);
    }
  }
}

// Destructor
// Deletes m_spaces
CBoard::~CBoard()
{
  if (m_spaces)
  {

    // First, delete each row
    for (unsigned int i = 0; i < m_uiSideLen; i++)
    {
      if (m_spaces[i])
      delete [] m_spaces[i];
    }

    // Then, delete the whole board
    delete [] m_spaces;
  }
}

// GetDisplay()
// Returns board in the form of null-terminated char*s
// Used for debugging, will be removed later
char** CBoard::Dump()
{
  char **csDisplay = new char*[m_uiSideLen];

  // Initialize rows
  for (unsigned int i = 0; i < m_uiSideLen; i++)
  {
    // Needs the +1 for null terminator
    csDisplay[i] = new char[m_uiSideLen+1];
    csDisplay[i][m_uiSideLen] = '\0';

    // Populate row with displays
    for (unsigned int j = 0; j < m_uiSideLen; j++)
    {
      csDisplay[i][j] = m_spaces[i][j].Dump();
    }
  }

  return csDisplay;
}
