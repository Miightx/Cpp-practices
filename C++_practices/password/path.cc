#include "path.hh"
#include <iostream>
#include <ctime>
#include <string>

Path::Path(size_t n, size_t x_max, size_t y_max){
	size = n;
	start_x = x_max;
	start_y = y_max;
	path = new Direction [size];
	for (size_t i = 0; i < size; i++){
		path[i] = static_cast<Direction>(rand() % 7);


		
		
	}
}



Path::~Path()
{
  delete [] path;

  
}

std::string Path::toString() const
{
  std:: string s = "((" + std::to_string(start_x) + "," + std::to_string(start_y) + ")";
  s = s + ' ';
  for (size_t i = 0; i < size  ; i++){
	  switch (path[i]) {
	  case N: s += "N"; break;
	  case NE: s += "NE"; break;
	  case NW: s += "NW"; break;
	  case E: s += "E"; break;
	  case SE: s += "SE"; break;
	  case S: s += "S"; break;
	  case SW: s += "SW"; break;
	  case W: s += "W"; break;
	  }

	  s += '-';
  }
  s.pop_back();
  s+= ")";
  return s;
}

void Path::print() const
{
  std::cout << toString()<< std::endl;
}
