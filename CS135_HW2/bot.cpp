/*
  Author: Matthew Wong
  Course: CSCI 135
  Instructors: Schweitzer/Khatchadourian
  Assignment: Project 2
  Battleship AI
*/

#include <cstdlib>
#include <iostream>
#include "bot.h"
#include "screen.h"
#include "ctime"
#include <vector>

using namespace std;

int ROWS;
int COLS;

vector<vector<char> > grid;

bool checkBadCoordinate(int, int);
int hitRight(int, int, Gun &, Screen &, ostream &);
int hitLeft(int, int, Gun &, Screen &, ostream &);
int hitUp(int, int, Gun &, Screen &, ostream &);
int hitDown(int, int, Gun &, Screen &, ostream &);


int contShot(int, int, Gun &, Screen &, ostream &);
int ifEdge(int, int);
void singleShip(int, int, Gun &, Screen &, ostream &);



/* Initialization procedure, called when the game starts:

   init (rows, cols, num, screen, log)

   Arguments:
    rows, cols = the boards size
    num        = the number of ships
    screen     = a screen to update your knowledge about the game
    log        = a cout-like output stream
*/
void init(int rows, int cols, int num, Screen &screen, ostream &log) {
  srand(time(NULL));
  ROWS = rows;
  COLS = cols;

  grid.resize(rows, vector<char>(cols, '5'));
  log << "Start." << endl;
}

/* The procedure handling each turn of the game:

   next_turn(sml, lrg, num, gun, screen, log)

   Arguments:
    sml, lrg = the sizes of the smallest and the largest ships that are
   currently alive
    num      = the number of ships that are currently alive
    gun      = a gun.
               Call gun.shoot(row, col) to shoot:
                  Can be shot only once per turn.
                  Returns MISS, HIT, HIT_N_SUNK, ALREADY_HIT, or ALREADY_SHOT.
    screen   = a screen to update your knowledge about the game
    log      = a cout-like output stream
*/

bool checkBadCoordinate(int r, int c) {
  if (grid[r][c] == '5' || grid[r][c] == '0')
    return true;
  else
    return false;
}

/* Key
0 - Miss
1 - Hit
2 - Hit and sink
3 - Hit in the opposite direction

*/

int hitRight(int r, int c, Gun &gun, Screen &screen, ostream &log) {
  int increase = 1;
  grid[r][c] = '1';
  bool shot = true;
  result res = gun.shoot(r, c + increase);

  if (res == HIT_N_SUNK) {
    grid[r][c + increase] = '1';
    screen.mark(r, c + increase, 'S', RED);
    if (r > 0) {
      grid[r + 1][c + increase] = '0';
      screen.mark(r + 1, c + increase, 'T',
                  BLUE);  // Bottom of the sunken ship coordinate
      grid[r - 1][c - increase] = '0';
      screen.mark(r - 1, c + increase, 'T',
                  BLUE);  // Top of the sunken ship coordinate
    } else {
      grid[r + 1][c + increase] = '0';
      screen.mark(r + 1, c - increase, 'T',
                  BLUE);  // Right to the sunken ship coordinate
    }
    return 2;
  } else if (res == HIT) {
    increase++;
    result shot2 = gun.shoot(r, c + increase);
    while (shot) {
      if (shot2 == HIT_N_SUNK) {
        grid[r][c + increase] = '1';
        screen.mark(r, c + increase, 'S', RED);

        if (c > 0 && c < (COLS - 1) && r > 0 && r < (ROWS - 1)) {
          grid[r - 1][c + increase] = '0';
          screen.mark(r + 1, c + increase, 'T', BLUE);
          grid[r + 1][c + increase] = '0';
          screen.mark(r - 1, c + increase, 'T', BLUE);

          grid[r - 1][c] = '0';
          screen.mark(r - 1, c, 'T', BLUE);
          grid[r + 1][c] = '0';
          screen.mark(r + 1, c, 'T', BLUE);
        } else if (c == 0 && r == 0) {  // (0,0)
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
        } else if (c == (COLS - 1) && r > 0) {  // (r > 0, maxcols - 1)
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
          grid[r - 1][c] = 'F';
          screen.mark(r - 1, c, 'T', BLUE);
        } else if (r > 0) {
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
          grid[r - 1][c] = 'F';
        }
      } else if (shot2 == HIT) {
        grid[r][c + increase] = '1';
        screen.mark(r, c + increase, '@', GREEN);
        if (c > 0 && c < (COLS - 1) && r > 0 && r < (ROWS - 1)) {
          grid[r - 1][c + increase] = 'F';
          screen.mark(r + 1, c + increase, 'T', BLUE);
          grid[r + 1][c + increase] = 'F';
          screen.mark(r - 1, c + increase, 'T', BLUE);

          grid[r - 1][c] = 'F';
          screen.mark(r - 1, c, 'T', BLUE);
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
        } else if (c == 0 && r == 0) {  // (0,0)
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
        } else if (c == (COLS - 1) && r > 0) {  // (r > 0, maxcols - 1)
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
          grid[r - 1][c] = 'F';
          screen.mark(r - 1, c, 'T', BLUE);
        } else if (r > 0) {
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
          grid[r - 1][c] = 'F';
        }
      } else if (shot2 == MISS) {
        shot = false;
        return 3;
      }
    }
  } else if (res == MISS) {
    return 0;
  }
}

int hitLeft(int r, int c, Gun &gun, Screen &screen, ostream &log) {
  int increase = 1;
  grid[r][c] = '1';
  bool shot = true;
  result res = gun.shoot(r, c - increase);

  if (res == HIT_N_SUNK) {
    grid[r][c - increase] = '1';
    screen.mark(r, c - increase, 'S', RED);

    if (r > 0) {
      grid[r + 1][c - increase] = 'F';
      screen.mark(r + 1 - increase, c - increase, 'T',
                  BLUE);  // Bottom of the sunken ship coordinate
      grid[r - 1][c - increase] = 'F';
      screen.mark(r - 1, c - increase, 'T',
                  BLUE);  // Top of the sunken ship coordinate
    } else {
      grid[r + 1][c - increase] = 'F';
      screen.mark(r + 1, c - increase, 'T',
                  BLUE);  // Right to the sunken ship coordinate
    }

    if (c > 1) {  // Can only happen if there's a space left
      screen.mark(r, c - 1, 'T', BLUE);
      grid[r][c - 1] = 'F';  // on the top of the sunken ship
    }

    return 2;
  } else if (res == HIT) {
    increase++;
    result shot2 = gun.shoot(r, c - increase);
    while (shot) {
      if (shot2 == HIT_N_SUNK) {
        grid[r][c - increase] = '1';
        screen.mark(r, c - increase, 'S', RED);

        if (c > 0 && c < (COLS - 1) && r > 0 && r < (ROWS - 1)) {
          grid[r - 1][c + increase] = 'F';
          screen.mark(r + 1, c + increase, 'T', BLUE);
          grid[r + 1][c + increase] = 'F';
          screen.mark(r - 1, c + increase, 'T', BLUE);

          grid[r - 1][c] = 'F';
          screen.mark(r - 1, c, 'T', BLUE);
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
        } else if (c == 0 && r == 0) {  // (0,0)
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
        } else if (c == (COLS - 1) && r > 0) {  // (r > 0, maxcols - 1)
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
          grid[r - 1][c] = 'F';
          screen.mark(r - 1, c, 'T', BLUE);
        } else if (r > 0) {
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
          grid[r - 1][c] = 'F';
        }
      } else if (shot2 == HIT) {
        grid[r][c - increase] = '1';
        screen.mark(r, c - increase, '@', GREEN);
        if (c > 0 && c < (COLS - 1) && r > 0 && r < (ROWS - 1)) {
          grid[r - 1][c - increase] = 'F';
          screen.mark(r + 1, c + increase, 'T', BLUE);
          grid[r + 1][c - increase] = 'F';
          screen.mark(r - 1, c + increase, 'T', BLUE);

          grid[r - 1][c] = 'F';
          screen.mark(r - 1, c, 'T', BLUE);
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
        } else if (c == 0 && r == 0) {  // (0,0)
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
        } else if (c == (COLS - 1) && r > 0) {  // (r > 0, maxcols - 1)
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
          grid[r - 1][c] = 'F';
          screen.mark(r - 1, c, 'T', BLUE);
        } else if (r > 0) {
          grid[r + 1][c] = 'F';
          screen.mark(r + 1, c, 'T', BLUE);
          grid[r - 1][c] = 'F';
        }
      } else if (shot2 == MISS) {
        return 3;
      }
    }
  } else if (res == MISS) {
    return 0;
  }
}

int hitUp(int r, int c, Gun &gun, Screen &screen, ostream &log) {
  int increase = 1;
  grid[r][c] = '1';
  bool shot = true;
  result res = gun.shoot(r - increase, c);

  if (res == HIT_N_SUNK) {
    grid[r - increase][c] = '1';
    screen.mark(r - increase, c, 'S', RED);

    if (c > 0) {
      grid[r - increase][c - 1] = 'F';
      screen.mark(r - increase, c - 1, 'T',
                  BLUE);  // Left to the sunken ship coordinate
      grid[r - increase][c + 1] = 'F';
      screen.mark(r - increase, c + 1, 'T',
                  BLUE);  // Right to the sunken ship coordinate
    } else {
      grid[r - increase][c - 1] = 'F';
      screen.mark(r - increase, c - 1, 'T',
                  BLUE);  // Right to the sunken ship coordinate
    }

    if (r > 0) {  // Can only happen if there's a space left
      screen.mark(r - 1, c, 'T', BLUE);
      grid[r - 1][c] = 'F';  // on the top of the sunken ship
    }

    return 2;
  }

  else if (res == HIT) {
    increase++;
    result shot2 = gun.shoot(r - increase, c);
    while (shot) {
      if (shot2 == HIT) {
        if (c == 0) {  // If you are on the first column then there are no
                       // values to the left
          grid[r - increase][c + 1] = 'F';
          screen.mark(r - increase, c - 1, 'T', BLUE);
        } else if (c == (COLS - 1)) {  // If you are on the last column then
                                       // there are no values to the right
          grid[r - increase][c - 1] = 'F';
          screen.mark(r - increase, c - 1, 'T', BLUE);
        } else {
          grid[r - increase][c + 1] = 'F';
          screen.mark(r - increase, c + 1, 'T', BLUE);
          grid[r - increase][c - 1] = 'F';
          screen.mark(r - increase, c - 1, 'T', BLUE);
        }

        grid[r - increase][c] = '1';
        screen.mark(r - increase, c, '@', GREEN);

      } else if (shot2 == HIT_N_SUNK) {
        grid[r - increase][c] = '1';
        screen.mark(r - increase, c, 'S', RED);

        if (c > 0 && c < (COLS - 1) && r > 0 && r < (ROWS - 1)) {
          grid[r - increase][c + 1] = 'F';  // Right
          grid[r - increase][c - 1] = 'F';  // left
          grid[r - increase - 1][c] = 'F';  // top
        }
        if (c == 0 && r > 0) {                  // (r>0,0)
          grid[r - increase][c + 1] = 'F';      // Right
          grid[r - increase - 1][c] = 'F';      // top
        } else if (c == 0 && r == 0) {          // (0,0)
          grid[r - increase][c + 1] = 'F';      // Right
        } else if (c == (COLS - 1) && r > 0) {  // (r > 0, maxcols - 1)
          grid[r - increase][c - 1] = 'F';      // left
        } else if (r > 0) {
          grid[r - increase - 1][c] = 'F';  // top
        }
        shot = false;
      } else if (shot2 == MISS) {
        shot = false;
        return 3;
      }
    }
    grid[r][c + increase] = '1';

    return 1;
  } else if (res == MISS) {
    return 0;
  }
}

int hitDown(int r, int c, Gun &gun, Screen &screen, ostream &log) {
  int increase = 1;
  grid[r][c] = '1';
  bool shot = true;
  result res = gun.shoot(r + increase, c);
  if (res == HIT_N_SUNK) {
    grid[r + increase][c] = '1';  // New shot is good
    screen.mark(r + increase, c, 'S', RED);

    grid[r - 1][c] = 'F';  // The point above the given coordinate is also bad

    if (c > 0) {
      grid[r][c - 1] = 'F';
      screen.mark(r, c - 1, 'T', BLUE);  // Left to the sunken ship coordinate
      grid[r][c + 1] = 'F';
      screen.mark(r, c + 1, 'T', BLUE);  // Right to the sunken ship coordinate
    } else {
      grid[r][c + 1] = 'F';
      screen.mark(r, c + 1, 'T', BLUE);  // Right to the sunken ship coordinate
    }

    if (r != (ROWS - 1)) {  // Can only happen if there's a space left
      screen.mark(r + 1, c, 'T', BLUE);
      grid[r + 1][c] = 'F';  // on the bottom of the sunken ship
    }

    return 2;
  } else if (res == HIT) {
    while (shot) {
      increase++;

      if (c > 0) {
        grid[r + increase][c - 1] = 'F';
        screen.mark(r, c - 1, 'T', BLUE);  // Left to the sunken ship coordinate
        grid[r + increase][c + 1] = 'F';
        screen.mark(r, c + 1, 'T',
                    BLUE);  // Right to the sunken ship coordinate
      } else if (c == (COLS - 1)) {
        grid[r + increase][c - 1] = 'F';
        screen.mark(r + increase, c - 1, 'T',
                    BLUE);  // Right to the sunken ship coordinate
      }

      result res2 = gun.shoot(r + increase, c);

      if (res == HIT) {
        grid[r - 1][c] =
            'F';  // The point above the given coordinate is also bad
        screen.mark(r - 1, c, 'T', BLUE);

        if (c > 0) {
          grid[r][c - 1] = 'F';
          screen.mark(r, c - 1, 'T', BLUE);  // Left to the SHOT ship coordinate
          grid[r][c + 1] = 'F';
          screen.mark(r, c + 1, 'T',
                      BLUE);  // Right to the SHOT ship coordinate
        } else {
          grid[r][c + 1] = 'F';
          screen.mark(r, c + 1, 'T',
                      BLUE);  // Right to the sunken ship coordinate
        }
      } else if (res2 == HIT_N_SUNK) {
        if (c > 0) {
          grid[r][c - 1] = 'F';
          screen.mark(r, c - 1, 'T',
                      BLUE);  // Left to the sunken ship coordinate
          grid[r][c + 1] = 'F';
          screen.mark(r, c + 1, 'T',
                      BLUE);  // Right to the sunken ship coordinate
        } else {
          grid[r][c + 1] = 'F';
          screen.mark(r, c + 1, 'T',
                      BLUE);  // Right to the sunken ship coordinate
        }

        if (r != (ROWS - 1)) {  // Can only happen if there's a space left
          screen.mark(r + 1, c, 'T', BLUE);
          grid[r + 1][c] = 'F';  // on the bottom of the sunken ship
        }
      } else if (res2 == MISS)
        return 3;
    }
    return 1;
  } else if (res == MISS) {
    return 0;
  }
}

/*
This function is meant to get the surrounding areas of the ship to ignore
It would save rounds to make the bot finish faster

It is incomplete because I can't figure out why the shots
are counted as ALREADY_SHOT
*/
int contShot(int r, int c, Gun &gun, Screen &screen, ostream &log) {
  log << "I have made it to contShot" << endl;
  int edgeValue = ifEdge(r, c);
  int shootRight, shootDown, shootUp, shootLeft;
  switch (edgeValue) {
   case 0: // middle of the grid
    {
      log << "I am on case 0 middle of grid" << endl;
      result testShot = gun.shoot(r-1,c); // Shooting up
      log << "testshot is " << testShot << endl;
      if(testShot == HIT_N_SUNK){
        grid[r-1][c] = '1';
        screen.mark(r-1,c,'S',RED);

        grid[r-1][c-1] = '0'; // Shot to left is bad
        screen.mark(r-1,c-1,'T',BLUE);
        grid[r-1][c+1] = '0'; // Shot to right is bad
        screen.mark(r-1,c+1,'T',BLUE);
        grid[r-2][c] = '0'; // Shot on top is bad
        screen.mark(r-2,c,'T',BLUE);
        return 0;
      } 
      else if(testShot == HIT){ // If shooting up is a good shot
        screen.mark(r-1,c,'@',GREEN);
        grid[r-1][c] = '1';
        shootUp = hitUp(r, c, gun, screen, log);
        if(shootUp == 3){ // It it stops and doesn't finish
          shootDown = hitDown(r, c, gun, screen, log);
        }
        return 0;
      }
      else if(testShot == MISS){
        screen.mark(r-1,c,'T',BLUE);
        grid[r-1][c] = 'F';
      }
      else
        break;

      // ------------------------------------------

      testShot = gun.shoot(r,c-1); // Shoot left
      if(testShot == HIT_N_SUNK){
        grid[r][c-1] = '1';
        screen.mark(r,c-1,'S',RED);

        grid[r+1][c] = '0'; // Shot bottom is bad
        screen.mark(r+1,c,'T',BLUE);
        grid[r-1][c] = '0'; // Shot top is bad
        screen.mark(r-1,c,'T',BLUE);
        grid[r][c-2] = '0'; // Shot to the left is bad
        screen.mark(r,c-2,'T',BLUE);
        return 0;
      }
      else if(testShot == HIT){ // Continue shooting
        screen.mark(r,c-1,'@',GREEN);
        shootLeft = hitLeft(r, c, gun, screen, log);
        if(shootLeft == 3){
          shootRight = hitRight(r, c, gun, screen, log); 
        }
        return 0;
      }
      else if(testShot == MISS){
        screen.mark(r,c-1,'T',BLUE);
        grid[r][c-1] = 'F';
      }

      testShot = gun.shoot(r,c+1); // Shoot right
      if(testShot == HIT_N_SUNK){
        return 0;
      }
      else if(testShot == HIT){
        screen.mark(r,c+1,'@',GREEN);
        shootLeft = hitLeft(r, c, gun, screen, log);
        if(shootLeft == 3){
          shootRight = hitRight(r, c, gun, screen, log); 
        }
      }
      else
        break;
    }
    case 1:  // Top left corner
    {
      if(gun.shoot(r,c+1) == 1){
        grid[r][c+1] = '1';
        screen.mark(r,c+1,'@',GREEN);
        shootRight = hitRight(r, c, gun, screen, log);

      }
      
      if (shootRight == 3) 
      break;
    }

    case 2:  // Bottom left corner
    {
      shootRight = hitRight(r, c, gun, screen, log);
      if (shootRight == 3) shootUp = hitUp(r, c, gun, screen, log);
      break;
    }

    case 3:  // top right corner
    {
      shootLeft = hitLeft(r, c, gun, screen, log);
      if (shootLeft == 3) {
        shootDown = hitDown(r, c, gun, screen, log);
      }
      break;
    }

    case 4:  // bottom right corner
    {
      shootLeft = hitLeft(r, c, gun, screen, log);
      if (shootLeft == 3) shootUp = hitUp(r, c, gun, screen, log);

      break;
    }
    case 5:  // top edge
    {
      shootLeft = hitLeft(r, c, gun, screen, log);
      if (shootLeft == 3) {  // If left fail then go down
        shootDown = hitDown(r, c, gun, screen, log);

        if (shootDown == 3) {  // If down fail then go right
          shootRight = hitRight(r, c, gun, screen, log);
        }
      }

      break;
    }

    case 6:  // bottom edge
    {
      shootLeft = hitLeft(r, c, gun, screen, log);
      if (shootLeft == 3) {  // If left fail then go up
        shootUp = hitUp(r, c, gun, screen, log);
        if (shootUp == 3) {  // If up fail then hit right
          shootRight = hitRight(r, c, gun, screen, log);
        }
      }

      break;
    }
    case 7:  // left edge
    {
      result testShot = gun.shoot(r-1,c);
      if(testShot == HIT){
        screen.mark(r-1,c,'@',GREEN);
      }
      else if(testShot == HIT_N_SUNK){
        screen.mark(r-1,c,'S',RED);
      }
      else if(testShot == MISS){
        screen.mark(r-1,c,'T',BLUE);
      } 
    }
    case 8:  // right edge
    {
      shootUp = hitUp(r, c, gun, screen, log);
      if (shootUp == 3) {
        shootLeft = hitLeft(r, c, gun, screen, log);
        if (shootLeft == 3) {
          shootDown = hitDown(r, c, gun, screen, log);
        }
      }
      break;
    }
  }
}

/*
Key:
1: top left corner
2: bottom left corner
3: top right corner
4: bottom right corner
5: Top edge
6: Bottom edge
7: Left edge
8: Right edge
*/
int ifEdge(int r, int c) {
  if(r > 0 && r < (ROWS - 1) && c > 0 && c < (COLS - 1)) // if middle of the grid
    return 0;
  else if (r == 0 && c == 0)  // Origin (0,0)
    return 1;
  else if (r == (ROWS - 1) && c == 0)  // Bottom Left corner (MAXROWS - 1,0)
    return 2;
  else if (r == 0 && c == (COLS - 1))  // Top right corner (0, MAXCOLS - 1)
    return 3;
  else if (r == (COLS - 1) &&
           c == (COLS - 1))  // Bottom right corner (MAXROWS - 1, MAXCOLS - 1)
    return 4;
  else if (r == 0)  // Top edge
    return 5;
  else if (r == (ROWS - 1))  // Bottom edge
    return 6;
  else if (c == 0)  // Left edge
    return 7;
  else if (c == (COLS - 1))  // Right edge
    return 8;

}

void singleShip(int r, int c, Gun &gun, Screen &screen, ostream &log) {
  // Cover surrounding areas
  int left, right, top, bottom;
  left = c - 1;
  right = c + 1;
  top = r - 1;
  bottom = r + 1;

  if (left < 0) left++;
  if (right == COLS) right--;
  if (top < 0) top++;
  if (bottom == ROWS) bottom--;

  /*
  All the if cases are a combination of top, bottom, left, right coordinates
  depending on where they need to
  be checked. For example on a left edge, only the top, right, and bottom
  coordinates need to be checked.
  Key map:
  (grid[r][right] == '0' || grid[r][right] == '5') - For checking to the right
  (grid[r][left] == '0' || grid[r][left] == '5') - For checking to the left
  (grid[top][c] == '0' || grid[top][c] == '5') - For checking the top
  (grid[bottom][c] == '0' || grid[bottom][c] == '5') - For checking the bottom

  grid[r][left] = '0';
  screen.mark(r,left, 'T', BLUE);

  grid[r][right] = '0';
  screen.mark(r,right, 'T', BLUE);

  grid[top][c] = '0';
  screen.mark(r,top, 'T', BLUE);

  grid[bottom][c] = '0';
  screen.mark(r,bottom, 'T', BLUE);
  */

  /* Lets do the corners first */
  if (r == 0 && c == 0) {  // top left corner

    screen.mark(r, right, 'T', BLUE);
    screen.mark(bottom, c, 'T', BLUE);

    grid[r][right] = 'F';
    grid[bottom][c] = 'F';

  } else if (r == (ROWS - 1) && c == 0) {  // This is the bottom left corner

    screen.mark(r, right, 'T', BLUE);
    screen.mark(top, c, 'T', BLUE);

    grid[r][right] = 'F';
    grid[top][c] = 'F';

  } else if (r == (ROWS - 1) && c == 0) {  // top right corner

    grid[r][left] = 'F';
    screen.mark(r, left, 'T', BLUE);

    grid[bottom][c] = 'F';
    screen.mark(bottom, c, 'T', BLUE);

  } else if (r == (ROWS - 1) && c == (COLS - 1)) {  // bottom right corner

    grid[top][c] = 'F';
    grid[r][left] = 'F';
    screen.mark(r, left, 'T', BLUE);
    screen.mark(top, c, 'T', BLUE);

  } else if (left == 0) {  // left edge

    screen.mark(top, c, 'T', BLUE);
    screen.mark(r, right, 'T', BLUE);
    screen.mark(bottom, c, 'T', BLUE);

    grid[top][c] = 'F';
    grid[r][right] = 'F';
    grid[bottom][c] = 'F';

  } else if (right == COLS - 1) {  // right edge

    screen.mark(top, c, 'T', BLUE);
    screen.mark(r, left, 'T', BLUE);
    screen.mark(bottom, c, 'T', BLUE);

    grid[top][c] = 'F';
    grid[r][left] = 'F';
    grid[bottom][c] = 'F';

  } else if (top == 0) {  // top edge

    grid[r][right] = 'F';
    screen.mark(r, right, 'T', BLUE);

    grid[bottom][c] = 'F';
    screen.mark(bottom, c, 'T', BLUE);

    grid[r][left] = 'F';
    screen.mark(r, left, 'T', BLUE);

  } else if (bottom == (ROWS - 1)) {  // bottom edge

    grid[top][c] = 'F';
    screen.mark(top, c, 'T', BLUE);

    grid[r][left] = 'F';
    screen.mark(r, left, 'T', BLUE);

    grid[r][right] = 'F';
    screen.mark(r, right, 'T', BLUE);
  }

  // For all other center cases
  if ((grid[r][right] == 'F' || grid[r][right] == '5') &&
      (grid[r][left] == 'F' || grid[r][left] == '5') &&
      (grid[top][c] == 'F' || grid[top][c] == '5') &&
      (grid[bottom][c] == 'F' || grid[bottom][c] == '5')) {
    grid[r][left] = 'F';
    screen.mark(r, left, 'T', BLUE);

    grid[r][right] = 'F';
    screen.mark(r, right, 'T', BLUE);

    grid[top][c] = 'F';
    screen.mark(top, c, 'T', BLUE);

    grid[bottom][c] = 'F';
    screen.mark(bottom, c, 'T', BLUE);
  }
}

void next_turn(int sml, int lrg, int num, Gun &gun, Screen &screen,
               ostream &log) {
  bool unique = true;
  int r, c;

  /*
  Hit is: 1
  Miss is: 0
  HIT_N_SUNK is: 2
  ALREADY_HIT is:  3
  ALREADY_SHOT is: 4

*/
  while (unique) {
    r = rand() % ROWS;
    c = rand() % COLS;

    if (grid[r][c] == '5') unique = false;
  }

  result res = gun.shoot(r, c);

  log << "Shoot at " << r << " " << c << endl;
  // add result on the screen
  if (res == MISS) {
    screen.mark(r, c, 'x', BLUE);
    grid[r][c] = '0';
  }

  else if (res == HIT) {
    screen.mark(r, c, '@', GREEN);
    grid[r][c] = '1';
    contShot(r, c, gun, screen, log);
  }

  else if (res == HIT_N_SUNK) {
    screen.mark(r, c, 'S', RED);
    grid[r][c] = '2';
    singleShip(r, c, gun, screen, log);
  }
}