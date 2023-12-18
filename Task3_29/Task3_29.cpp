#include <iostream>
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
			CipheredText[i] = '*';
	}
}


int main()
{
	string PlainText = "MATOU TE TATALO MO KASA";
	string CipheredText = PlainText;
	char Samoan[] = {'A' , 'E' , 'I' , 'O' , 'U' , 'F' , 'G' , 'L' ,
					 'M' , 'N' , 'P' , 'S' , 'T' , 'V' , 'H' , 'K' ,
					 'R' , '’' , 'a' , 'e' , 'i' , 'o' , 'u' , 'f' ,
					 'g' , 'l' , 'm' , 'n' , 'p' , 's' , 't' , 'v' ,
					 'h' , 'k' , 'r' , '0' , '1' , '2' , '3' , '4' ,
					 '5' , '6' , '7' , '8' , '9' , '.' , ',' , '?' , 
					 ' '};

	int n = sizeof(Samoan);
	int a, b;
	cout << "Enter the Affine keys a and b\n";
	cout << "a : "; cin >> a;
	cout << "b : "; cin >> b;
	Cipher(Samoan, n, a, b, PlainText , CipheredText);
	cout << PlainText << endl;
	cout << CipheredText << endl;
}