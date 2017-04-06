#include <cstdlib>
#include <iostream>
#include "bot.h"
#include "screen.h"
#include "ctime"
#include <vector>

using namespace std;

int ROWS;
int COLS;

int iter = 0;
vector<vector<int> > grid;

/* Initialization procedure, called when the game starts:

   init (rows, cols, num, screen, log) 
 
   Arguments:
    rows, cols = the boards size
    num        = the number of ships 
    screen     = a screen to update your knowledge about the game
    log        = a cout-like output stream
*/
void init(int rows, int cols, int num, Screen &screen, ostream &log) 
{
  srand(time(NULL));
  ROWS = rows;
  COLS = cols;
 
  grid.resize(rows, vector<int>(cols, 5));
  log << "Start." << endl;
}

void surroundingShips(vector<vector<int> > grid){

}

void impossibleSpaces(vector<vector<int> > grid, int cols, int r, int c, Screen &screen){
  //int start = 1;
  //bool single;
  if(grid[r][c] == 2){

    // If the row will go out of bounds then make sure it's not
    if( !((r+1) >= (int)grid[r].size()) ){
      if(grid[r+1][c] == 0 || grid[r+1][c] == 5){
        grid[r+1][c] = 0;
        screen.mark(r+1, c, 'X', GREEN);
      }
    }

    // Make sure it doesn't go negative horizontally
    else if(!((r-1) < 0)){
      if(grid[r-1][c] == 0 || grid[r-1][c] == 5){
        grid[r-1][c] = 0;
        screen.mark(r-1, c, 'X', GREEN);
      }
    }

    else if( !((c+1) >= cols) ){
      if(grid[r][c+1] == 0 || grid[r][c+1] == 5){
        grid[r][c+1] = 0;
        screen.mark(r, c+1, 'X', GREEN);
      }
    }

    else if( !((c-1) < 0) ){
      if(grid[r][c-1] == 0 || grid[r][c-1] == 5){
        grid[r][c-1] = 0;
        screen.mark(r, c-1, 'X', GREEN);
      }
    }

    else
      return;

  }
}





    /*
    if(grid[r-1][c] == 0 || grid[r-1][c] == 5)
    if(grid[r][c+1] == 0 || grid[r][c+1] == 5)
    if(grid[r][c-1] == 0 || grid[r][c-1] == 5)
    */
  

  /*
  if(grid[r][c+1] == 1){
    while(continued){
      if(grid[r][c+start] == 1){
        screen.mark(r, c+start, '@', GREEN);
        grid[r+1][c+start] = 1;
        if(r>0){
          grid[r-1][c+start] = 1;
          continued = false;
        }
          
        else {
          grid[r][c+start] = 1;
          continued = false;
        }
          
        start++;
      }
      // If the sunken ship is solo and in a corner
      if(grid[0][0] == 2){
        grid[0][1] = 0;
        grid[1][0] = 0;
        continued = false;
      }

      // If the sunken ship is on an edge
      else if(r == 0){
        if(grid[r][c] == 2 && (grid[r][c+1] == 0 || grid[r][c+1] == 5) && (grid[r][c-1] == 0 || grid[r][c-1] == 5) && (grid[r+1][c] == 0 || grid[r+1][c] == 5)){
          grid[r][c+1] = 0;
          grid[r][c-1] = 0;
          continued = false;
        }
      }
      else if(c == 0){
        if(grid[r][c] == 2 && (grid[r][c+1] == 0 || grid[r][c+1] == 5) && (grid[r+1][c] == 0 || grid[r+1][c] == 5) && (grid[r-1][c] == 0 || grid[r-1][c] == 5)){
          grid[r+1][c] = 0;
          grid[r-1][c] = 0;
          continued = false;
        }
      }
      else{
        continued = false;
        //if(grid[r][c] == 2 && (grid[r][c+1] == 0 || grid[r][c+1] == 5) && (grid[r][c-1] == 0 || grid[r][c-1] == 5) && (grid[r+1][c] == 0 || grid[r+1][c] == 5) && (grid[r-1][c] == 0 || grid[r-1][c] == 5)){
        // }
      

      }
    }
  }
  */

/* The procedure handling each turn of the game:
 
   next_turn(sml, lrg, num, gun, screen, log)
 
   Arguments:
    sml, lrg = the sizes of the smallest and the largest ships that are currently alive
    num      = the number of ships that are currently alive
    gun      = a gun.
               Call gun.shoot(row, col) to shoot: 
                  Can be shot only once per turn. 
                  Returns MISS, HIT, HIT_N_SUNK, ALREADY_HIT, or ALREADY_SHOT.
    screen   = a screen to update your knowledge about the game
    log      = a cout-like output stream
*/

void continousShot(vector<vector<int> > grid, int r, int c, Gun &gun, Screen &screen, ostream &log);
void next_turn(int sml, int lrg, int num, Gun &gun, Screen &screen, ostream &log)
{
  bool unique = true;
  int r,c;

  
  while(unique){
    r = rand() % ROWS;
    c = rand() % COLS;

    if(grid[r][c] == 5)
      unique = false;
  }

  result res = gun.shoot(r, c);

  log << "Shoot at " << r << " " << c << endl;
  // add result on the screen
  if (res == MISS){
    screen.mark(r, c, 'x', BLUE); 
    grid[r][c] = 0;
  }

  else if (res == HIT) {
      screen.mark(r, c, '@', GREEN); 
      grid[r][c] = 1;
  }

  else if (res == HIT_N_SUNK){
      screen.mark(r, c, 'S', RED); 
      grid[r][c] = 2;
      impossibleSpaces(grid,COLS,r,c,screen);
  }
}