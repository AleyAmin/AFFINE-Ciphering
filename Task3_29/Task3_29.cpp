#include <iostream>
#include<string>
using namespace std;

int get_x(char Samaon[], int n, char element) {
	for (int i = 0; i < n; i++) {
		if (element == Samaon[i])
			return i;
	}
	return -1;
}

void Cipher(char Samoan[], int n, int a, int b, string& PlainText , string& CipheredText) {
	int cipheredIndex;
	for (int i = 0; i < PlainText.size(); i++) {
		int x = get_x(Samoan, n, PlainText[i]);
		if (x != -1) {
			cipheredIndex = (a * x + b) % n;
			CipheredText[i] = Samoan[cipheredIndex];
		}
		else
			CipheredText[i] = '#';
	}
}
// The next 2 commented functions (Decipher and modInverse) are to make sure the code runs correctly

//int modInverse(int a, int m) {
//	a = a % m;
//	for (int x = 1; x < m; x++)
//		if ((a * x) % m == 1)
//			return x;
//	return -1;
//}
//
//void Decipher(char Samoan[], int n, int a, int b, string& PlainText, string& CipheredText) {
//	int plainIndex;
//	for (int i = 0; i < CipheredText.size(); i++) {
//		int y = get_x(Samoan, n, CipheredText[i]);
//		if (y != -1) {
//			plainIndex = (modInverse(a, n) * (y - b + n)) % n; ;
//			PlainText[i] = Samoan[plainIndex];
//		}
//		else
//			PlainText[i] = '*';
//	}
//}

int main()
{
	string PlainText = "MATOU TE TATALO MO KASA";
	string CipheredText = PlainText;
	string PlainText_;
	string CipheredText_;
	char Samoan[] = {' ' , 'A' , 'E' , 'I' , 'O' , 'U' , 'F' , 'G' ,
					 'L' , 'M' , 'N' , 'P' , 'S' , 'T' , 'V' , 'H' ,
					 'K' , 'R' , '`' , 'a' , 'e' , 'i' , 'o' , 'u' ,
					 'f' , 'g' , 'l' , 'm' , 'n' , 'p' , 's' , 't' ,
					 'v' , 'h' , 'k' , 'r' , '0' , '1' , '2' , '3' ,
					 '4' , '5' , '6' , '7' , '8' , '9' , '.' , ',' ,
					 '?' , ';' , '!' , '-' , '(' , ')' , '+' , '=' ,
					 '/' , '*' , '%'};

	int n = sizeof(Samoan);
	int a, b , choice;
	cout << "Enter the Affine keys a and b. a = 11 and b = 13 is our original affine keys\n";
	cout << "a : "; cin >> a;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "please enter a number a : "; cin >> a;
	}
	cout << "b : "; cin >> b;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "please enter a number b : "; cin >> b;
	}

	Cipher(Samoan, n, a, b, PlainText , CipheredText);
	cout << "Plain Text      :    " << PlainText << endl;
	cout << "Ciphered Text   :    " << CipheredText << endl;

	/*string DecipheredText = CipheredText;
	Decipher(Samoan, n, a, b, DecipheredText, CipheredText);
	cout << "Deciphered Text :    " << DecipheredText << endl;*/

	cout << "If you want to enter your own text press 1 or anything else if not\n";
	cin >> choice;
	while (choice == 1) {
		cout << "Enter the text you want Ciphered\n";
		cin.ignore();
		getline(cin, PlainText_);
		CipheredText_ = PlainText_;
		Cipher(Samoan, n, a, b, PlainText_, CipheredText_);
		cout << CipheredText_ << endl;
		cout << "Do you want to enter another word ? Press 1 if Yes or anything else for No\n";
		cin >> choice;
	}
	return 0;
}