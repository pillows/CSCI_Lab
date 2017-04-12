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

/*
void impossibleSpaces(vector<vector<int> > grid, int cols, int rows, int r, int c, Screen &screen){
  //int start = 1;
  //bool single;
  if(grid[r][c] == 2){

    // If the row will go out of bounds then make sure it's not
    if( !((r+1) >= rows) ){
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
*/

void impossibleSpaces(vector<vector<int> > grid, int cols, int rows, int r, int c, Screen &screen, ostream &log){
  log << "impossibleSpaces" << endl;
  int left, right, top, bottom;
  left = r - 1;
  right = r + 1;
  top = c + 1;
  bottom = c - 1;

  if(left < 0)
    left++;
  if(right > COLS)
    right--;
  if(top < 0)
    top++;
  if(bottom > ROWS)
    bottom--;

  log << "left: ("<< left << "," << c << ")\n";
  log << "right: ("<< right << "," << c << ")\n";
  log << "top: ("<< r << "," << top << ")\n";
  log << "bottom: ("<< r << "," << bottom << ")\n";

  
  if( (grid[left][c] == 5 || grid[left][c]== 0 ) && (grid[right][c] == 0 || grid[right][c] == 5) && (grid[r][top] == 0 || grid[r][top] == 5) && (grid[r][bottom] == 0 || grid[r][bottom] == 5) ){
    grid[left][c] = 0;
    screen.mark(left, c, 'X', GREEN);

    grid[right][c] = 0;
    screen.mark(right, c, 'X', GREEN);

    grid[r][top] = 0;
    screen.mark(r, top, 'X', GREEN);

    grid[r][bottom] = 0;
    screen.mark(r, bottom, 'X', GREEN);
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

bool checkBadCoordinate(vector<vector<int> > grid, int r, int c){
  if(grid[r][c] == 5 || grid[r][c] == 0)
    return true;
  else
    return false;
}

void continousShot(vector<vector<int> > grid, int ROWS, int COLS, int r, int c, Gun &gun, Screen &screen, ostream &log){
  log << "cont shoot" << endl;
  int left, right, top, bottom;
  int contshot = 1;
  bool stopshot = true;
  left = r - 1;
  right = r + 1;
  top = c + 1;
  bottom = c - 1;



  if(left < 0)
    left++;
  if(right > COLS)
    right--;
  if(top < 0)
    top++;
  if(bottom > ROWS)
    bottom--;

  log << "left: ("<< left << "," << c << ")\n";
  log << "right: ("<< right << "," << c << ")\n";
  log << "top: ("<< r << "," << top << ")\n";
  log << "right: ("<< r << "," << bottom << ")\n";

  result res = gun.shoot(left,c);
  if(res == HIT || res == HIT_N_SUNK){
    if(res == HIT)
      screen.mark(left, c, '@', GREEN);
    if(res == HIT_N_SUNK)
      screen.mark(left, c, 'S', RED); 

    grid[left][c] = res;
    
    while(stopshot){
      result res2 = gun.shoot(left-contshot,c);
      if(res2 == HIT){
        grid[left-contshot][c] = 1;
        grid[left-contshot][c+1] = 0;
        screen.mark(left-contshot, c+1, 'X', GREEN);
        grid[left-contshot][c-1] = 0;
        screen.mark(left-contshot, c-1, 'X', GREEN);
      }

      else if(res2 == HIT_N_SUNK){
        grid[left-contshot][c] = 2;
        screen.mark(left-contshot, c+1, 'S', RED);
        stopshot = true;
      } 
      else if(res2 == MISS){
        grid[left-contshot][c] = 0;
        screen.mark(left-contshot, c, 'X', GREEN);
        stopshot = true;
      }
    }
    
  }
  else if(res == MISS){
    grid[left][c] = 0;
  }



}

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
      continousShot(grid,ROWS,COLS,r,c,gun,screen,log);
  }

  else if (res == HIT_N_SUNK){
      screen.mark(r, c, 'S', RED); 
      grid[r][c] = 2;
      impossibleSpaces(grid,COLS,ROWS,r,c,screen,log);
  }
}