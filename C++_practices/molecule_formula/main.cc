#include <iostream>
#include "molecule.hh"
#include "reaction.hh"
using namespace std; 
int main() {
    ifstream in("molecules/molecules.txt");
    ofstream out("res_normalisation.txt");
    string line;
    cout << "Molecules: \n";
    while (getline(in, line)) {
        molecule mol(line);
        vector<string> separate = mol.separate();
        for (string s : separate) {
            cout << s << " ";
        };
        cout << "\n";
        string norm = mol.normalise();
        out << norm << "\n";
    }
    in.close();
    out.close();

    ifstream in2("molecules/reactions.txt");
    ofstream out2("res_reactions.txt");
    string line2;
    while (getline(in2, line2)) {
        reaction react(line2);
        //std ::cout << react.to_string() << "\n";
        string norm = react.normalise();
        out2 << norm << "\n";
    }
    in2.close();
    out2.close();

    return 0;
}