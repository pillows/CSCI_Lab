#include <iostream>

#include <string>

#include <fstream>

#include <sstream>

using namespace std;





int main(){

    

    string input;

    string word;

   

    cout<<"Enter a word: "<<endl;

    getline(cin, input);

    

    for(int i= 0; i<input.length(); i++){

        

        cout<<input.at(i)<<endl;

        

        word = word+input.at(i);

        

    }

    

    

   cout<<"the word is: \n" <<word<<endl;

    

    ifstream file;

    file.open("nouns.txt");

    

    //Check for file error

    if(file.fail()){

        

        cerr<<"error opening file"<<endl;


    }

    

    string word1;

    int count =0;

    //read a file until the end

    

    while(!file.eof()){

        

        file>>word1;

        

        count++;

    

        if(word1 == word){

           

            cout<<"found!"<<endl;

        

        }

        else

            

            cout<<"not found"<<endl;

        }



    return 0;

}
