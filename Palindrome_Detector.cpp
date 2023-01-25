#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string, int, int);
bool punctuationChecker(int);

int main() {

	cout << "The Palindrome Detector" << endl;
	cout << "-----------------------" << endl;

	cout << "This program runs a check on a word or sentence that you enter to see if it is a palindrome." << endl;
	cout << "A Palindrome is a word or phrase that is spelled the same forward and backward. Here are a few examples:" << endl;

	cout << "\nMom\n"
		<< "Racecar\n"
		<< "Now I won\n"
		<< "Desserts, I stressed\n"
		<< "On a clover, if alive, erupts a vast, pure evil; a fire volcano\n";


	cout << "\nYou can enter numbers and punctuation, as they will be ignored by the program."
		<< "\nNow, enter the word or phrase you would like to check:" << endl;

	string userPalindrome;
	while(true){
	getline(cin, userPalindrome);

	bool palindromeChecker = isPalindrome(userPalindrome, 0, size(userPalindrome) - 1);

	if (palindromeChecker == true)
		cout << "\n\"" << userPalindrome << "\" is a palindrome!" << endl;
	else
		cout << "\n\"" << userPalindrome << "\" is NOT a palindrome!" << endl;


	cout << "\nEnter another the word or phrase you would like to check:" << endl;


	} 


}

bool isPalindrome(string palindrome, int beginning, int end) {
	//Make each character lower case so they can be check against each other
	char palindromeStart = tolower(palindrome[beginning]);
	char palindromeEnd = tolower(palindrome[end]);

	//If the value is a space, number, punctuation mark, or a special character
	//add one to the position and run the loop again
	while (punctuationChecker(palindromeStart)) {
		beginning++;
		palindromeStart = tolower(palindrome[beginning]);
	}

	//Same as above while loop
	while (punctuationChecker(palindromeEnd)) {
		end--;
		palindromeEnd = tolower(palindrome[end]);
	}


	//If values are equal call the function again
	if (palindromeStart == palindromeEnd) {
		//Base case, if the index matches or beginning overtakes end, then return true
		if (beginning == end || beginning > end)
			return true;
		//Call the function again to check the next value in the string
		return isPalindrome(palindrome, beginning + 1, end - 1);

	}

	//returns false if the above if statement fails 
	return false;


}


bool punctuationChecker(int charToCheck) {
	//The function converts the char to an int and checks the value to see
	//If it is a space, number, punctuation mark, or a special character
	if (charToCheck <= 96 || charToCheck >= 123)
		//Returns true if it is one of the above, will cause the while loop to run again
		return true;
	else
		return false;
}