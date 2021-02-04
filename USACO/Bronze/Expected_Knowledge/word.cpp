#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);

	//Read N and K.
	int N, K;
	cin >> N >> K;

	//Read the first word and print it immediately.
	string S;
	cin >> S;
	cout << S;

	//This variable is used for storing the number of characters
	//on the current line but NOT including the spaces characters.
	int Word_Length = 0;
	Word_Length += S.length();

	//Since there are N-1 words left, we only loop up to N-1.
	for (int i = 0; i < N - 1; ++i){
        cin >> S; //Read the next word.
		//Calculate the new length if we put the new word into the current line.
        Word_Length += S.length(); 
        if (Word_Length <= K) { //If it still satisfies the constraint then print that word.
            cout << " ";
            cout << S;
        }
        else { //Else we create a new line and print the word on that line.
            cout << "\n" << s;
			Word_Length = S.length();
        } 
    }	
	return 0;
}
