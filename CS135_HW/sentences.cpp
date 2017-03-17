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
#include <iomanip>
using namespace std;


// int nvn(string, ifstream, ifstream);
/*
int nvan(string, ifstream, ifstream, ifstream, ifstream)
int pvn(string, ifstream, ifstream, ifstream, ifstream)
int pvan(string, ifstream, ifstream, ifstream, ifstream)
int pvp(string, ifstream, ifstream)
*/


int nvn(string sentence) {
  // <sentence> ::= <noun><verb><noun>
  string compare, noun1, verb, noun2;
  bool done = false;
  ifstream nouns2, nouns, verbs;
  nouns.open("nouns");
  

  clock_t begin = clock();
  while( nouns >> noun1 ){
    
    verbs.open("verbs");
    while( verbs >> verb ){
      nouns2.open("nouns");
      while( nouns2 >> noun2 ){

        compare = noun1 + " " + verb + " " + noun2;

        if(compare == sentence)
        {
          cout << "Compare: " << compare << endl;
          cout << "Sentence: " << sentence << endl;
            clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << "time taken for function() " << elapsed_secs << " seconds.\n";
          return 1;
        }
        


      }
      nouns2.close();
    }
    verbs.close();
  }
  
  /*
  while(getline(nouns, noun1)) {

    while(getline(verbs, verb)) {

      while(getline(nouns2, noun2)) {
        
      compare = noun1 + " " + verb + " " + noun2;
      if(compare == sentence)
        return 1;
        
      }

    }
    
  }
  */

  cout << compare + "\n";
  nouns.close();
  return 0;
}

/*
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
*/

void checkSentence(string sentence) {
  int nvn_check, nvan_check, pvn_check, pvan_check, pvp_check;
  nvn_check = nvn(sentence);
  //nvan = nvan(sentence, nouns, verbs, adjectives);
  //pvn = pvn(sentence, pronouns, verbs, nouns);
  //pvan = pvan(sentence, pronouns, verbs, adjectives, nouns);
  //pvp = pvp(sentence, pronouns, verbs);

  if(nvn_check /*|| pvn || pvan || pvp*/)
    cout << "Valid sentence\n";
  else
    cout << "Invalid sentence\n";
  /*
  verbs.close();
  nouns.close();
  adjectives.close();
  pronouns.close();
  */
}


int main() {
	string sentence;
  //ifstream verbs, nouns, adjectives, pronouns;
  //verbs.open("verbs");
  //nouns.open("nouns");
  //adjectives.open("adjectives");
  //pronouns.open("pronouns");
	cout << "Insert your sentence \n";
	getline(cin,sentence);
  //cout << sentence << " Main \n";

  checkSentence(sentence);

  return 0;
  
  //checkSentence(sentence, verbs, nouns, adjectives, pronouns);
}