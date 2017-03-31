/*
  Author: Matthew Wong
  Course: CSCI 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 7

  Image Manipulation
*/


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

const int MAXWIDTH = 512;
const int MAXHEIGHT = 512;

// reads a PPM file.
// Notice that: width and height are passed by reference!
void readImage(int image[][MAXHEIGHT], int &width, int &height) {
  char c;
  int x;
  ifstream instr;
  instr.open("city.pgm");
  
  // read the header P2
  instr >> c;  assert(c == 'P');
  instr >> c;  assert(c == '2');

  // skip the comments (if any)
  while ((instr>>ws).peek() == '#') { instr.ignore(4096, '\n'); }

  instr >> width; 
  instr >> height;

  assert(width <= MAXWIDTH);
  assert(height <= MAXHEIGHT);
  int max;
  instr >> max;
  assert(max == 255);

  for (int row = 0; row < height; row++) 
    for (int col = 0; col < width; col++) 
      instr >> image[col][row];
  instr.close();
  return;
}

void writeImage(int image[][MAXHEIGHT], int width, int height) {
  ofstream ostr;
  ostr.open("outImage.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };
  
  // print the header
  ostr << "P2" << endl;
  // width, height
  ostr << width << ' '; 
  ostr << height << endl;
  ostr << 255 << endl;

  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      assert(image[col][row] < 256);
      assert(image[col][row] >= 0);
      ostr << image[col][row] << ' ';
      // lines should be no longer than 70 characters
      if ((col+1)%16 == 0) ostr << endl;
    }
    ostr << endl;
  }
  ostr.close();
  return;
}

void highlight(int image[][MAXHEIGHT],int width, int height, int t1, int t2) {
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {
      if (image[i][j] < t1) // If the pixel value is less than t1 then make it 0
        image[i][j] = 0;

      if (image[i][j] > t2) // If the pixel value is greater than t2 then make it 255
        image[i][j] = 255;
    }
  }
}


int main() {

  int image[MAXWIDTH][MAXHEIGHT]; // first array
  int image2[MAXWIDTH][MAXHEIGHT]; // second array that will copy info from the first
  
  int width, height;

  readImage(image,width,height);

  for (int i = 0; i < MAXWIDTH; i++)
  {
    for (int j = 0; j < MAXHEIGHT; j++)
    {
      image2[i][j] = image[i][j];
    }
  }

  writeImage(image2,width,height); // Task 0
  
  // Task 1
  int t1, t2;
  cout << "Insert t1 value: ";
  cin >> t1;
  cout << "Insert t2 value: ";
  cin >> t2;

  highlight(image, width, height, t1, t2);

  writeImage(image, width, height); // Image output for Task 1

  return 0;

}
