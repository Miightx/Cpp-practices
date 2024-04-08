#include "passgrid.hh"
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <fstream>

// obtain a seed from the system clock:
std::default_random_engine PassGrid::_generator(std::chrono::system_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> PassGrid::_distribution(33,94);


PassGrid::PassGrid(const PassGrid & p)
{
	_w = p._w;
	_h = p._h;
	grid = new char* [_h];
	for (std::size_t i = 0; i < _h; i++)
	{
		grid[i] = new char[_w];
	}

	for (std::size_t i = 0; i < _h; i++)
	{
		for (std::size_t j = 0; j < _w; j++)
		{
			grid[i][j] = p.grid[i][j];
		}
	}
}



PassGrid::PassGrid(std::size_t w, std::size_t h)
{ 
	_w = w;
	_h = h;
	grid = new char*[h];
	for (std::size_t i = 0; i < _h; i++)
	{
		grid[i] = new char[w];
	}
	reset();
}

PassGrid::~PassGrid()
{ for (std:: size_t i = 0; i < _h; i++)
	{
		delete[] grid[i];
	}
	delete[] grid;
}


void PassGrid::save(std::ostream& out) const
{
	std::ostream& file = out;
	for (std::size_t i = 0; i < _h; i++)
	{
		for (std::size_t j = 0; j < _w; j++)
		{
			file << grid[i][j];
		}
		file << std::endl;
	}
}
void PassGrid::print() const
{
	for (std::size_t i = 0; i < _h; i++)
	{
		for (std::size_t j = 0; j < _w; j++)
		{
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}
	
}


void PassGrid::load(std::istream& in)
{
	std::istream& file = in; 
	std::string line;
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
	}
	

}
void PassGrid::reset()
{	
	for (std::size_t i = 0; i < _h; i++)
	{
		for (std::size_t j = 0; j < _w; j++)
		{
			grid[i][j] = _distribution(_generator);
		}
	}
}


std::string PassGrid::generate(const Path& p)const
{
	std::size_t x = p.getStartX();
	std::size_t y = p.getStartY();
	std::string password;
	std::string password2;


	for (std::size_t i = 0; i < p.getSize(); i++) {

		std::cout << password << std::endl;

		if (x >= _w && y >= _h) {
			switch (p(i))
			{
			case N: y--; break;
			case NE: y--; break;
			case NW: y--; x--; break;
			case S: y--; break;
			case SE: y--; x--; break;
			case SW: x--; break;
			case E: x--; break;
			case W: x--; break;
			}
			password += grid[y - 1][x - 1];
			password2 = grid[y - 1][x - 1];
		}
		else if (x >= _w && y <= 0) {
			switch (p(i))
			{
			case N: y++; break;
			case NE: y++; x--; break;
			case NW: y++; x--; break;
			case S: y--; break;
			case SE: y--; break;
			case SW: x--; y--; break;
			case E: x--; break;
			case W: x--; break;
			}
			if (y == 0)
			{
				password += grid[0][x - 1];
				password2 = grid[0][x - 1];
			}
			else
			{
				password += grid[y - 1][x - 1];
				password2 = grid[y - 1][x - 1];
			}

		}
		else if (x >= _w)
		{
			switch (p(i))
			{
			case N: y--; break;
			case NE: y--; break;
			case NW: y--; x--; break;
			case S: y++; break;
			case SE: y++; break;
			case SW: y++; x--; break;
			case E: x--; break;
			case W: x--; break;
			}
			password += grid[y - 1][x - 1];
			password2 = grid[y - 1][x - 1];
		}
		else if (y >= _h)
		{
			switch (p(i))
			{
			case N: y--; break;
			case NE: y--; x++; break;
			case NW: y--; x--; break;
			case S: y--; break;
			case SE:  x++; break;
			case SW:  x--; break;
			case E: x++; break;
			case W: x--; break;
			}
			password += grid[y - 1][x - 1];
			password2 = grid[y - 1][x - 1];

		}
		else if (x <= 0 && y <= 0)
		{
			switch (p(i))
			{
			case N: y++; break;
			case NE: y++; x++; break;
			case NW: y++; x++; break;
			case S: y++; break;
			case SE: y++; x++; break;
			case SW: y++; break;
			case E: x++; break;
			case W: x++; break;
			}
			if (x == 0)
			{
				password += grid[y - 1][0];
				password2 = grid[y - 1][0];
			}
			else if (y == 0)
			{
				password += grid[0][x - 1];
				password2 = grid[0][x - 1];
			}
			else
			{
				password += grid[y - 1][x - 1];
				password2 = grid[y - 1][x - 1];
			}

		}
		else if (x <= 0 && y >= _h)
		{
			switch (p(i))
			{
			case N: y--; break;
			case NE: y--; x++; break;
			case NW: y--; x++; break;
			case S: y--; break;
			case SE: y--; x++; break;
			case SW: y--; break;
			case E: x++; break;
			case W: x++; break;
			}
			if (x == 0)
			{
				password += grid[y - 1][0];
				password2 = grid[y - 1][0];
			}
			else
			{
				password += grid[y - 1][x - 1];
				password2 = grid[y - 1][x - 1];
			}
		}

		else
		{
			switch (p(i))
			{
			case N: y--; break;
			case NE: y--; x++; break;
			case NW: y--; x--; break;
			case S: y++; break;
			case SE: y++; x++; break;
			case SW: y++; x--; break;
			case E: x++; break;
			case W: x--; break;
			}
			password += grid[y - 1][x - 1];
			password2 = grid[y - 1][x - 1];
		}

	}
	return password;
}



void PassGrid::writeSVG(const std::string& filename) const
{
	std::ofstream svgFile(filename);
	if (!svgFile.is_open()) {
		std::cerr << "Error opening the file: " << filename << std::endl;
		exit(1);
	}
	svgFile << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";
	svgFile << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << _w * 20 << "\" height=\"" << _h * 20 << "\">\n";

	for (std::size_t i = 0; i < _h; i++) {
		for (std::size_t j = 0; j < _w; j++) {
			svgFile << "<rect x=\"" << j * 20 << "\" y=\"" << i * 20 << "\" width=\"20\" height=\"20\" fill=\"white\" />\n";
			svgFile << "<text x=\"" << (j * 20) + 10  << "\" y=\"" << (i * 20) + 15 << "\" fill=\"black\" font-size=\"12\" text-anchor=\"middle\">" << grid[i][j] << "</text>\n";
		}
	}
	svgFile << "</svg>\n";
	svgFile.close();
}

