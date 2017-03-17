/*
Author: 
Course: {135,136}
Instructor: Ilya
Assignment: CS135 HW

Creating and checking sentences
*/

/*
<sentence> ::= <noun><verb><noun>
<sentence> ::= <noun><verb><adjective><noun>
<sentence> ::= <pronoun><verb><noun>
<sentence> ::= <pronoun><verb><adjective><noun>
<sentence> ::= <pronoun><verb><pronoun>
*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

/*
int nvn(string, ifstream, ifstream, ifstream)
int nvan(string, ifstream, ifstream, ifstream, ifstream)
int pvn(string, ifstream, ifstream, ifstream, ifstream)
int pvan(string, ifstream, ifstream, ifstream, ifstream)
int pvp(string, ifstream, ifstream)
int nvn(sentence, nouns, verbs) {
  return 0;
}

int nvan(sentence, nouns, verbs, adjectives) {
  return 0;
}

int pvn(sentence, pronouns, verbs, nouns) {
  return 0;
}

int pvan(sentence, pronouns, verbs, adjectives, nouns) {
  return 0;
}

int pvp(sentence, pronouns, verbs) {
  return 0;
}

int checkSentence(sentence, verbs, nouns, adjectives, pronouns) {
  int nvn, nvan, pvn, pvan, pvp;
  nvn = nvn(sentence, nouns, verbs);
  nvan = nvan(sentence, nouns, verbs, adjectives);
  pvn = pvn(sentence, pronouns, verbs, nouns);
  pvan = pvan(sentence, pronouns, verbs, adjectives, nouns);
  pvp = pvp(sentence, pronouns, verbs);

  if(nvn || pvn || pvan || pvp)
    return 1;
  else
    return 0;
}
*/

int main() {
	string sentence, line;
  int x, sum = 0, n = 0;
  ofstream verbs, nouns, adjectives, pronouns;
  verbs.open("verbs");
  nouns.open("nouns");
  adjectives.open("adjectives");
  pronouns.open("pronouns");
	cout << "Insert your sentence \n";
	getline(cin,sentence);
  //cout << sentence;

  cout << verbs;

  while ( getline (verbs, line) )
    {
      cout << line << '\n';
    }
  //checkSentence(sentence, verbs, nouns, adjectives, pronouns);
}