/*
Author: Matthew Wong
Course: CSCI 135
Instructor: Eric Schweitzer, Raffi Khatchadourian
Assignment: CS135 Project Part B

Checking, converting, and writing sentences
*/
#include <iostream>
#include <fstream>

using namespace std;

string stripRepeatingSpaces(string);  // Unnecessary spaces make finding words harder

char toLower(char);  // To make checking easier for words

// To compare in the individual files whether a word is a noun, verb, pronoun,
// or adjective.
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
If any of these functions return 0 then it is not a sentence that follows the
rule
*/
int nvn(string);
int nvan(string);
int pvn(string);
int pvan(string);
int pvp(string);

// These functions will convert the sentence to elbonian
string elbnvn(string);
string elbnvan(string);
string elbpvn(string);
string elbpvan(string);
string elbpvp(string);

void checkSentence(string);

char toLower(char letter) {
  char newLetter;
  if ((int)letter < 97 &&
      (int)letter > 64) {  // If a letter has an ascii code greater than 64 or
                           // less than 97, then it is a capital letter
    newLetter =
        (int)letter + 32;  // To make it lowercase, add 32 to the ascii code
    return (char)newLetter;
  } else
    return letter;  // If it doesn't fall in that range, then it is lower case
                    // and just return
}
bool isVerb(string word) {
  ifstream verbs;
  string verb;
  cout << "word " << word << endl;
  verbs.open("verbs");
  while (verbs >> verb) {
    if (verb ==
        word) {  // If the word exists in the file then return true. Simple.
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
  while (getline(nouns, noun)) {  // Loops through the list and gives the
                                  // variable noun as a string to compare with
                                  // the word
    if (noun ==
        word) {  // If the word exists in the file then return true. Simple.
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
  while (pronouns >> pronoun) {  // Loops through the list and gives the
                                 // variable pronoun as a string to compare with
                                 // the word
    if (pronoun ==
        word) {  // If the word exists in the file then return true. Simple.
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
  while (adjectives >> adjective) {  // Loops through the list and gives the
                                     // variable adjective as a string to
                                     // compare with the word
    if (adjective ==
        word) {  // If the word exists in the file then return true. Simple.
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

    else if (sentence[i] == ' ') {  // If there is a space then it's a word
      spaces++;

      /*
      The checks the follow the rule of the sentence. In this example:
      <sentence> ::= <noun><verb><noun>
      isNoun
      isVerb
      isNoun

      If any return a false then it does not follow the rule of this sentence
      */
      if (currentLength ==
          0) {  // What word you are up to. Starting with 0 as an index.
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

      compare = "";  // Reset the variable on each loop to get a new word
    }
    if (i == sentence.length() - 1) {  // It's reached the end of the sentence
      if (!isNoun(compare)) {
        return 0;
      }
    }
  }

  if (spaces != 2)
    return 0;  // If there is not 2 spaces then it is not a proper nvn sentence

  return 1;  // Each function will return a different number that represents the
             // rule it follows
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

  /*
  Similar to the sentence type checking
  It follow the rules by word index
  Some comments in the code will not be repeated if it does the same function
  */
  string elbnvn(string sentence) {
    string begin, rest, compare;
    int word = 0;
    for (int i = 0; i < sentence.length(); i++) {
      if (sentence[i] != ' ') {
        compare += sentence[i];
      } else if (sentence[i] == ' ') {
        switch (word) {
          case 0:
            rest += compare;  // First word is a noun so it's added in a
                              // variable to combine with another word
            break;
          case 1:
            begin = compare;  // This verb will be placed in the begin variable
                              // to prepend to the sentence
            break;
        }
        word++;
        compare = "";
      }
      if (i == sentence.length() - 1) {
        rest += " " + compare;  // Combine the first noun and third noun
      }
    }
    sentence = (begin + " " + rest);  // The verb goes first then the rest of
                                      // the sentence (verb noun noun)
    return sentence;
  }

  string elbnvan(string sentence) {
    string begin, rest, compare, restOfString, last;
    char firstLetter;
    int word = 0;
    for (int i = 0; i < sentence.length(); i++) {
      if (sentence[i] != ' ') {
        compare += sentence[i];
      } else if (sentence[i] ==
                 ' ') {  // 4 word sentences follow a different set of rules
        switch (word) {
          case 0:
            rest += compare;  // Store noun in variable
            break;
          case 1:
            begin = compare;  // Verb is stored in another variable to become
                              // the first word
            break;
          case 2:
            for (int j = 0; j < compare.length();
                 j++) {  // This loop will get the remaining letters in the
                         // adjective
              if (j == 0)
                firstLetter = compare[0];  // Collect the first letter
              else
                restOfString +=
                    compare[j];  // Rest of the letters in the adjective
            }

            break;
        }
        word++;
        compare = "";
      }
      if (i == sentence.length() - 1) {
        last = compare;
      }
    }
    sentence = (begin + " " + rest + " " + firstLetter + last +
                restOfString);  // The sentence is constructed as follows: verb,
                                // noun, [first letter of
                                // adjective]noun[remaining letters of
                                // adjective]
    return sentence;
  }

  string elbpvn(string sentence) {
    string begin, rest, compare;
    int word = 0;
    for (int i = 0; i < sentence.length(); i++) {
      if (sentence[i] != ' ') {
        compare += sentence[i];
      } else if (sentence[i] == ' ') {
        switch (word) {
          case 0:
            rest += compare;
            break;
          case 1:
            begin = compare;
            break;
        }
        word++;
        compare = "";
      }
      if (i == sentence.length() - 1) {
        rest += " " + compare;
      }
    }
    sentence = (begin + " " + rest);  // The verb goes first then the rest of
                                      // the sentence (verb pronoun noun)
    return sentence;
  }

  string elbpvan(string sentence) {
    string begin, rest, compare, restOfString, last;
    char firstLetter;
    int word = 0;
    for (int i = 0; i < sentence.length(); i++) {
      if (sentence[i] != ' ') {
        compare += sentence[i];
      } else if (sentence[i] == ' ') {
        switch (word) {
          case 0:
            rest += compare;
            break;
          case 1:
            begin = compare;
            break;
          case 2:

            for (int j = 0; j < compare.length(); j++) {
              if (j == 0)
                firstLetter = compare[0];
              else
                restOfString += compare[j];
            }
            break;
        }
        word++;
        compare = "";
      }
      if (i == sentence.length() - 1) {
        last = compare;
      }
    }
    sentence = (begin + " " + rest + " " + firstLetter + last +
                restOfString);  // The sentence is constructed as follows: verb,
                                // pronoun, [first letter of
                                // adjective]noun[remaining letters of
                                // adjective]
    return sentence;
  }

  string elbpvp(string sentence) {
    string begin, rest, compare;
    int word = 0;
    for (int i = 0; i < sentence.length(); i++) {
      if (sentence[i] != ' ') {
        compare += sentence[i];
      } else if (sentence[i] == ' ') {
        switch (word) {
          case 0:

            rest += compare;
            break;
          case 1:
            begin = compare;
            break;
        }
        word++;
        compare = "";
      }
      if (i == sentence.length() - 1) {
        rest += " " + compare;
      }
    }
    sentence = (begin + " " + rest);  // The verb goes first then the rest of
                                      // the sentence (verb pronoun pronoun)
    return sentence;
  }

  void checkSentence() {
    ifstream engsents;
    ofstream elbsents;
    string sentence;
    engsents.open("engsents");
    elbsents.open("elbsents");

    /*
    Get all the sentences from the engsents file and put them in a sentence
    variable
    to check/convert in the following functions
    */
    while (getline(engsents, sentence)) {
      int nvn_check, nvan_check, pvn_check, pvan_check, pvp_check, total;
      string oldSentence = sentence;  // Preserve sentence case
      sentence = stripRepeatingSpaces(sentence);
      string result;

      nvn_check = nvn(sentence);
      nvan_check = nvan(sentence);
      pvn_check = pvn(sentence);
      pvan_check = pvan(sentence);
      pvp_check = pvp(sentence);

      /*
     The function will run though each sentence checking function
     and then add up the reseults. It will be between 0 and 5.
     1 to 5 is the rule the sentence follows
     0 is not a legal sentence and will output "Illegal sentence found"
     Then the rule will follow it's elbonian converting function.
     e.g rule 1 (nvn) follows elbnvn()
     */
      total = nvn_check + nvan_check + pvn_check + pvan_check + pvp_check;

      switch (total) {
        case 0:
          result = "Illegal sentence found";
          elbsents << result + "\n";
          break;
        case 1:
          result = elbnvn(oldSentence);
          cout << result << endl;
          elbsents << result + "\n";
          break;
        case 2:
          result = elbnvan(oldSentence);
          cout << result << endl;
          elbsents << result + "\n";
          break;
        case 3:
          result = elbpvn(oldSentence);
          cout << result << endl;
          elbsents << result + "\n";
          break;
        case 4:
          result = elbpvan(oldSentence);
          cout << result << endl;
          elbsents << result + "\n";
          break;
        case 5:
          result = elbpvp(oldSentence);
          cout << result << endl;
          elbsents << result + "\n";
          break;
        default:
          cout << "Something went wrong.\n";
      }
    }
    engsents.close();
    elbsents.close();
  }

  int main() {
    checkSentence();
    return 0;
  }