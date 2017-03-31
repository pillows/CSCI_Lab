uthor: Phillip Chen
Course: 135
Instructor: Alex Nikolaev
Assignment: Project 1 Task A

This program ask for you to input a sentence, if the sentence has 5 words or more its illegal.
The sentence is only legal if you used words provided in the notepads given for this project in a specific order.
The word type and order is stated in the code 
This program allows uppercase letters and disregards multiple spaces between words
*/

#include <iostream>
#include <fstream>
using namespace std;


int main(){
string input;
cout<<"Please enter a setence: ";
getline (cin,input);

for(int i = 0;i<input.length();i++){	//converts sentence to lower case
	if (64<input[i] && input[i]<97){
		input[i]=input[i]+32;
		}
	}
	
string w1;		//strings to store the words 
string w2;
string w3;
string w4;
string w5; 		//if there is an extra word(s) then the sentence is illegal
						
int empty1 =0;	//empty(#) are counters for spaces in between sentences
int empty2 =0;
int empty3 =0;
int empty4 =0;

for(int i = 0; i<input.length();i++){		//extract the words in the getline sentence
											//(32 = space, 9 = horizontal tab , 11 = vertical tab)
											//activates counter when muliple spaces bewteen words	
	if((input[i] == 32 || input[i] ==9 || input[i] == 11) && (input[i+1] == 32 || input[i+1] ==9 || input[i+1] == 11 ) &!(w4.empty()))//multiple spaces after fourth word
		{empty4++;}	
	
	if((input[i] == 32 || input[i] ==9 || input[i] == 11) && (input[i+1] == 32 || input[i+1] ==9 || input[i+1] == 11 ) &!(w3.empty()))//multiple spaces after third word
		{empty3++;}
		
	if((input[i] == 32 || input[i] ==9 || input[i] == 11) && (input[i+1] == 32 || input[i+1] ==9 || input[i+1] == 11 ) &!(w4.empty()))//multiple spaces after second word
		{empty2++;}
		
	if((input[i] == 32 || input[i] ==9 || input[i] == 11) && (input[i+1] == 32 || input[i+1] ==9 || input[i+1] == 11 ))//multiple spaces after first word
		{empty1++;}
		
	//these "if loops" are to catch single space or spaces before the words
	if((input[i] == 32 || input[i] ==9 || input[i] == 11)//single or the last of "muliple spaces" after fourth word  
			&!(w4.empty()))
		{empty4++;}	
	
	if((input[i] == 32 || input[i] ==9 || input[i] == 11)//single or the last of "muliple spaces" after third word 
			&!(w3.empty()))
		{empty3++;}
		
	if((input[i] == 32 || input[i] ==9 || input[i] == 11)//single or the last of "muliple spaces" after second word 
			&!(w2.empty()))
		{empty2++;}
		
	if((input[i] == 32 || input[i] ==9 || input[i] == 11))//single or the last of "muliple spaces" after first word 
		{empty1++;}
		
	// these "if loops" are to store the words
	if((input[i] != 32 && input[i] !=9 && input[i] != 11 ) && empty4 !=0)//stores rest of the letters after fourth word in w5
		{w5= w5+input[i];}

	if((input[i] != 32 && input[i] !=9 && input[i] != 11 ) && empty4==0 && empty3 !=0)//stores fourth word in w4
		{w4= w4+input[i];}
		
	if((input[i] != 32 && input[i] !=9 && input[i] != 11 ) && empty3==0 && empty2 !=0 )//stores third word in w3
		{w3= w3+input[i];}

	if((input[i] != 32 && input[i] !=9 && input[i] != 11 ) && empty2 ==0 && empty1 !=0)//stores second word in w2
		{w2= w2+input[i];}

	if((input[i] != 32 && input[i] !=9 && input[i] != 11 ) && empty1==0 )//stores first word in w1
		{w1= w1+input[i];}
	}

/*	legal sentences - since order matters, some words dont need to be compared 
	to know if the sentence is legal; noun w1,w3,w4| pronoun w1,w3| verb w2| adj w3 
    <sentence> = <noun>		<verb>	<noun>
    <sentence> = <noun>		<verb>	<adjective>	<noun>
    <sentence> = <pronoun>	<verb>	<noun>
    <sentence> = <pronoun>	<verb>	<adjective>	<noun>
    <sentence> = <pronoun>	<verb>	<pronoun>
*/
	string notepad;
	ifstream MyFileInput;	
	//checks if w1,w3,w4 is in noun vocabulary
	MyFileInput.open("nouns"); 	//open and close files to reset the searching process to the top
	int counterw1noun = 0;		//counters to indicate if the word was found in the 4 list of words
	int counterw3noun = 0;
	int counterw4noun = 0;
	while(getline(MyFileInput,notepad)){
		if(w1==notepad){counterw1noun++;}
	}
	MyFileInput.close();
	MyFileInput.open("nouns");
	while(getline(MyFileInput,notepad)){
		if(w3==notepad){counterw3noun++;}
	}
	MyFileInput.close();
	MyFileInput.open("nouns");
	while(getline(MyFileInput,notepad)){
		if(w4==notepad){counterw4noun++;}
	}
	MyFileInput.close();

	//checks if w1,w3 words is in pronoun vocabulary
	MyFileInput.open("pronouns");
	int counterw1pro = 0;
	int counterw3pro = 0;
	while(getline(MyFileInput,notepad)){
		if(w1==notepad){counterw1pro++;}
	}
	MyFileInput.close();
	MyFileInput.open("pronouns");
	while(getline(MyFileInput,notepad)){
		if(w3==notepad){counterw3pro++;}
	}
	MyFileInput.close();
	
	//checks if w2 is in verb vocabulary
	MyFileInput.open("verbs");
	int counterw2verb = 0;
	while(getline(MyFileInput,notepad)){
		if(w2==notepad){counterw2verb++;}
	}
	MyFileInput.close();

	//checks if w3 is in adj vocabulary
	MyFileInput.open("adjectives");
	int counterw3adj = 0;
	while(getline(MyFileInput,notepad)){
		if(w3==notepad){counterw3adj++;}
	}
	MyFileInput.close();
	
	//displays results of success
	int fail = 0;	//counter will determine if sentence structure is wrong,by default it will show not legal but if 
					//the input sentence is found legal, then the counter will increase and the not legal statement will not display
	if(counterw1noun !=0 && counterw2verb !=0 && counterw3noun !=0 && w4.empty() && w5.empty())
		{fail++;cout<<"Your sentence is a legal sentence by rule {1}"<<endl;}
	if(counterw1noun !=0 && counterw2verb !=0 && counterw3adj !=0 && counterw4noun !=0 && w5.empty())
		{fail++;cout<<"Your sentence is a legal sentence by rule {2}"<<endl;}
	if(counterw1pro !=0 && counterw2verb !=0 && counterw3noun !=0 && w4.empty() && w5.empty())
		{fail++;cout<<"Your sentence is a legal sentence by rule {3}"<<endl;}
	if(counterw1pro !=0 && counterw2verb !=0 && counterw3adj !=0 && counterw4noun !=0 && w5.empty())
		{fail++;cout<<"Your sentence is a legal sentence by rule {4}"<<endl;}
	if(counterw1pro !=0 && counterw2verb !=0 && counterw3pro !=0 && w4.empty() && w5.empty())
		{fail++;cout<<"Your sentence is a legal sentence by rule {5}"<<endl;}
	if(fail ==0){cout<<"Your sentence is not a legal sentence"<<endl;}
	
