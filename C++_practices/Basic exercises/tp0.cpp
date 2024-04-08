/* Exercice 1
#include <iostream>
#include <string>
int main()
{
	std::cout << "Comment vous appellez vous ? ";
	std::string name;
	std::cin >> name;
	std::cout << "Salut " << name << std::endl
		<< "Et quel est le votre ? ";
	std::cin >> name;
	std::cout << "Enchante " << name << std::endl;
	return 0;
}
*/
/*Exercice 2
#include <iostream>
int main()
{
	int n;
	float y;
	std :: cout << "Type an integer and float " << std::endl;
	std::cin >> n; 


	std::cin >> y ;

	std :: cout <<"n"<< n <<"y"<< y << std::endl ;

	std :: cout<<"the product of "<< n<<"with"<< y <<"is" << n*y << std::endl;
	return 0;
}
*/
 /*Exercice 3
#include <iostream>
#include <iomanip>
	 int main() {
	 std::cout << "Comment vous appellez vous ? ";
	 std::string name;
	 float midgrade;
	 float finalgrade;
	 float homework  ; 
	 float quarante(0.4);
	 float vingt(0.2);
	 std::cin >> name;
	 std::cout << "Quel est votre note de mi semestre ";
	 std::cin >>midgrade;
	 std::cout << "Quel est votre note d'examen";
	 std::cin >>finalgrade;
	 std::cout << "Quel est votre note de homework";
	 std::cin >>homework;

	 float end_score;
	 end_score = finalgrade * vingt + midgrade * quarante + homework * quarante ;
	 std::cout << std::fixed;
	 std::	cout << "Votre note du semestre est "<< std::setprecision(4)<<end_score << std::endl;


 }
*/

/*Exercice 4 a.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
	std::ifstream inputFile("travail.txt"); // Open the text file

	if (inputFile.is_open()) {
		std::string line;
		int wordCount = 0;
		while (std::getline(inputFile, line)) {
			std::stringstream ss(line);
			std::string word;

			while (ss >> word) {
				wordCount++;
			}
		}

		inputFile.close();

		std::cout << "Number of words in the said file: " << wordCount << std::endl;
	}
	else {
		std::cout << "Failed to open the file." << std::endl;
	}

	return 0;
}
*/
/*Exercice 4 b.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
bool contains(const std::string& str, char targetChar)
{
	return str.find(targetChar) != std::string::npos;
}
int main() {
	std::ifstream inputFile("prenom.txt"); // Open the text file
	std::ofstream outputFile("prenomA.txt");

	char targetChar = 'A';
	if (inputFile.is_open()) {
		std::string line;
		while (std::getline(inputFile, line)) {
			std::stringstream ss(line);
			std::string word;

			while (ss >> word) {
				if (contains(word, targetChar)) {
					std::cout << word << std::endl;
					outputFile << word << std::endl;

				}
				else {
				}
			}
		}
	outputFile.close();

	return 0;
	}
}
*/

/* Exercice 5*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
float max_length = 20;
int booleen = 0;
int main()
{

	cout << "Ecrivez une phrase avec maximum d'une taille de 20 espaces: ";
	string sentence;
	getline(cin, sentence); 
	while (booleen == 0) {
		if (sentence.size() >= max_length) {
			cout << "Réecrivez une phrase avec maximum d'une taille de 20 espaces: ";
			getline(cin, sentence); 
			booleen = 0;
		}
		else {
			booleen = 1;
			ifstream file;
			char line[30];

			file.open("lapin.txt", ios::in);
			cout << " ______________________ " << endl;
			int espace = (max_length + 3 - sentence.size()) / 2;
			cout << "|";
			for (int i = 0; i < espace; i++) {
				cout << " ";
			}
			cout << sentence;
			for (int i = 0; i < espace; i++) {
				cout << " ";
			}
			cout << "|" << endl;
			cout << " ______________________ " << endl;
			cout << "         \\ " << endl;
			cout << "          \\ " << endl;

			while (file.getline(line, sizeof line)) {
				cout << line << endl;
			}
		}
	}
	return 0;
}