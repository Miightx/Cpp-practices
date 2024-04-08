#pragma once
#include<string>
#include<iostream>
using namespace std;

class atome {
	public :

		atome(string a) : _val(a) {};
		string  to_string() const; 
	private : 
		string _val;

};
