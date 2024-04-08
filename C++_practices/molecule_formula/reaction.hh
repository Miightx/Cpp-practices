#include <iostream>
#include <string>
#include <vector>
using namespace std;
class reaction {
	public:
		reaction (string a);
		string to_string() ;
		void print_left() const;
		void print_right() const;
		string normalise() const;
	private :
		string _val;
		vector <string> _left;
		vector <string> _right;
};
