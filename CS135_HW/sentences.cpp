/*
Author: Matthew Wong
Course: CSCI 135
Instructor: Eric Schweitzer, Raffi Khatchadourian
Assignment: CS135 Project Part A

Comparing strings with words in file
*/

#include <iostream>
#include <fstream>
using namespace std;


string stripRepeatingSpaces(string); // Unnecessary spaces make finding words harder

char toLower(char); // To make checking easier for words

// To compare in the individual files whether a word is a noun, verb, pronoun, or adjective.
bool isNoun(string);
bool isVerb(string);
bool isPronoun(string);
bool isAdjective(string);

/*
The different types of sentences. The naming of the function follows:
(n)oun
(v)erb
(a)djective
(p)ronoun
If any of these functions return 0 then it is not a sentence that follows the rule
*/
int nvn(string);
int nvan(string);
int pvn(string);
int pvan(string);
int pvp(string);

void checkSentence(string); // Determines the type of sentence

string stripRepeatingSpaces(string sentence) {
  int lastLetter;
  string newSentence;
  char currentLetter;

  for (int i = 0; i < sentence.length(); i++) { // Loops by sentence length
    if (!(sentence[i] == ' ' && sentence[i + 1] == ' ')) // If two adjacent characters have a space then it's a repeating space
      newSentence += sentence[i]; // If there isn't, then add the character
  }
  sentence = newSentence;

  return sentence;
}

char toLower(char letter) {
  char newLetter;
  if ((int)letter < 97 && (int)letter > 64) { // If a letter has an ascii code greater than 64 or less than 97, then it is a capital letter
    newLetter = (int)letter + 32; // To make it lowercase, add 32 to the ascii code
    return (char)newLetter;
  } else
    return letter; // If it doesn't fall in that range, then it is lower case and just return
}
bool isVerb(string word) {
  ifstream verbs;
  string verb;
  cout << "word " << word << endl;
  verbs.open("verbs");
  while (verbs >> verb) {
    if (verb == word) { // If the word exists in the file then return true. Simple.
      verbs.close();
      return true;
    }
  }
  verbs.close();
  return false;
}

bool isNoun(string word) {
  ifstream nouns;
  string noun;
  nouns.open("nouns");
  while (getline(nouns, noun)) { // Loops through the list and gives the variable noun as a string to compare with the word
    if (noun == word) { // If the word exists in the file then return true. Simple.
      nouns.close();
      return true;
    }
  }

  nouns.close();
  return false;
}

bool isPronoun(string word) {
  ifstream pronouns;
  string pronoun;
  pronouns.open("pronouns");
  while (pronouns >> pronoun) { // Loops through the list and gives the variable pronoun as a string to compare with the word
    if (pronoun == word) { // If the word exists in the file then return true. Simple.
      pronouns.close();
      return true;
    }
  }
  pronouns.close();
  return false;
}

bool isAdjective(string word) {
  ifstream adjectives;
  string adjective;
  adjectives.open("adjectives"); 
  while (adjectives >> adjective) { // Loops through the list and gives the variable adjective as a string to compare with the word
    if (adjective == word) { // If the word exists in the file then return true. Simple.
      adjectives.close();
      return true;
    }
  }

  adjectives.close();
  return false;
}

/*
The sentence rule checking functions follow similar comments
Some comments in the code will not be repeated if it does the same function
*/
int nvn(string sentence) {
  string compare;

  int currentLength = 0;
  int spaces = 0;

  for (int i = 0; i < sentence.length(); i++) { 
    if (sentence[i] != ' ') {
      compare += toLower(sentence[i]);
    }

    else if (sentence[i] == ' ') { // If there is a space then it's a word
      spaces++; 

      /*
      The checks the follow the rule of the sentence. In this example:
      <sentence> ::= <noun><verb><noun>
      isNoun
      isVerb
      isNoun

      If any return a false then it does not follow the rule of this sentence
      */
      if (currentLength == 0) { // What word you are up to. Starting with 0 as an index.
        if (!isNoun(compare)) {
          return 0;             
        }
      }
      if (currentLength == 1) {
        if (!isVerb(compare)) {
          return 0;
        }
      }

      currentLength++;

      compare = ""; // Reset the variable on each loop to get a new word
    }
    if (i == sentence.length() - 1) { // It's reached the end of the sentence
      if (!isNoun(compare)) {
        return 0;
      }
    }
  }

  if (spaces != 2) return 0; // If there is not 2 spaces then it is not a proper nvn sentence

  return 1; // Each function will return a different number that represents the rule it follows
}

int nvan(string sentence) {
  string compare;

  int currentLength = 0;
  int spaces = 0;

  for (int i = 0; i < sentence.length(); i++) {
    if (sentence[i] != ' ') {
      compare += toLower(sentence[i]);
    }

    else if (sentence[i] == ' ') {
      spaces++;
      /*
      The checks the follow the rule of the sentence. In this example:
      <sentence> ::= <noun><verb><adjective><noun>
      isNoun
      isVerb
      isAdjective
      isNoun
      */
      if (currentLength == 0) {
        if (!isNoun(compare)) {
          return 0;
        }
      }
      if (currentLength == 1) {
        if (!isVerb(compare)) {
          return 0;
        }
      }

      if (currentLength == 2) {
        if (!isAdjective(compare)) {
          return 0;
        }
      }

      currentLength++;

      compare = "";
    }
    if (i == sentence.length() - 1) {
      if (!isNoun(compare)) {
        return 0;
      }
    }
  }

  if (spaces != 3) return 0; 

  return 2;
} 

int pvn(string sentence) {
  string compare;

  int currentLength = 0;
  int spaces = 0;

  for (int i = 0; i < sentence.length(); i++) {
    if (sentence[i] != ' ') {
      compare += toLower(sentence[i]);
    }

    else if (sentence[i] == ' ') { 
      spaces++;
      /*
      The checks the follow the rule of the sentence. In this example:
      <sentence> ::= <pronoun><verb><noun>
      isPronoun
      isVerb
      isNoun
      */
      if (currentLength == 0) {
        if (!isPronoun(compare)) {
          return 0;
        }
      }
      if (currentLength == 1) {
        if (!isVerb(compare)) {
          return 0;
        }
      }

      currentLength++; 

      compare = "";
    }
    if (i == sentence.length() - 1) {
      if (!isNoun(compare)) { 
        return 0;
      }
    }
  }

  if (spaces != 2) return 0;

  return 3;

int pvan(string sentence) {
  string compare;

  int currentLength = 0;
  int spaces = 0;

  for (int i = 0; i < sentence.length(); i++) {
    if (sentence[i] != ' ') {
      compare += toLower(sentence[i]);
    }

    else if (sentence[i] == ' ') {
      spaces++;
      /*
      The checks the follow the rule of the sentence. In this example:
      <sentence> ::= <pronoun><verb><adjective><noun>
      isPronoun
      isVerb
      isAdjective
      isNoun
      */
      if (currentLength == 0) {
        if (!isPronoun(compare)) {
          return 0;
        }
      }
      if (currentLength == 1) {
        if (!isVerb(compare)) {
          return 0;
        }
      }
      if (currentLength == 2) {
        if (!isAdjective(compare)) {
          return 0;
        }
      }

      currentLength++;

      compare = "";
    }
    if (i == sentence.length() - 1) {
      if (!isNoun(compare)) {
        return 0;
      }
    }
  }

  if (spaces != 3) return 0;

  return 4;
}

int pvp(string sentence) {
  string compare;

  int currentLength = 0;
  int spaces = 0;

  for (int i = 0; i < sentence.length(); i++) {
    if (sentence[i] != ' ') {
      compare += toLower(sentence[i]);
    }

    else if (sentence[i] == ' ') {
      spaces++;
      /*
      The checks the follow the rule of the sentence. In this example:
      <sentence> ::= <pronoun><verb><pronoun>
      isPronoun
      isVerb
      isPronoun
      */
      if (currentLength == 0) {
        if (!isPronoun(compare)) {
          return 0;
        }
      }
      if (currentLength == 1) {
        if (!isVerb(compare)) {
          return 0;
        }
      }

      currentLength++;

      compare = "";
    }
    if (i == sentence.length() - 1) {
      if (!isPronoun(compare)) {
        return 0;
      }
    }
  }

  if (spaces != 2) return 0; 

  return 5;
}

void checkSentence(string sentence) {
  int nvn_check, nvan_check, pvn_check, pvan_check, pvp_check, total;
  sentence = stripRepeatingSpaces(sentence);

  /*
  The function will run though each sentence checking function
  and then add up the reseults. It will be between 0 and 5.
  1 to 5 is the rule the sentence follows
  0 is not a legal sentence
  */
  nvn_check = nvn(sentence);
  cout << "nvn " << nvn_check << endl;

  nvan_check = nvan(sentence);
  cout << "nvan " << nvan_check << endl;

  pvn_check = pvn(sentence);
  cout << "pvn " << pvn_check << endl;

  pvan_check = pvan(sentence);
  cout << "pvan " << pvan_check << endl;
  pvp_check = pvp(sentence);
  cout << "pvp " << pvp_check << endl;

  total = nvn_check + nvan_check + pvn_check + pvan_check + pvp_check;

  if (total > 0)
    cout << "Your sentence is a legal sentence by rule " << total << endl;
  else
    cout << "Your sentence is not a legal sentence. \n";
}

int main() {
  string sentence;
  cout << "Insert your sentence \n";
  getline(cin, sentence);

  checkSentence(sentence);
  return 0;
}