#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    char letter;
    string w;
    cout<<"Choose a letter: ";
    cin>>letter;
    cout<<"Write a word: ";
    cin>>w;

    vector <char> word(w.begin(), w.end());

    int counter = 0;

    if (find(word.begin(), word.end(), letter) == word.end()){
        cout<<endl<<"The letter is not found";
    }

    else {
        cout<<"letter is found on position ";
        for(int i=0; i<word.size(); i++){
            if(word[i]==letter){
                cout<<i<<", ";
                counter++;
            }
        }
    cout<<"and that's "<<counter<<" times in the word";
    }

    return 0;
}
