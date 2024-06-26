// Let DocTest provide main():
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
//#include "test_matcher.hh"
#include "passgrid.hh"
#include "path.hh"
#include <fstream>


bool notEqualGrids (PassGrid& p0, PassGrid& p1)
{
  for (std::size_t i = 0 ; i < p0.getH(); i++ )
    for (std::size_t j = 0 ; j < p0.getW(); j++)
      if ((p0(i,j) != p1(i,j)))
        return true;
  return false;
}

TEST_SUITE("grid") {
  TEST_CASE("1: Size of the grid"){
    PassGrid p0(0,0);
    CHECK(p0.getW() == 0);
    CHECK(p0.getH() == 0);
    PassGrid p1(10,8);
    CHECK(p1.getW() == 10);
    CHECK(p1.getH() == 8);
  }

  TEST_CASE("2: copy same grid"){
    PassGrid p0(0,0);
    PassGrid p1(p0);
    CHECK(!notEqualGrids(p0,p1));
  }
}

TEST_CASE("3: Grid contents"){
  PassGrid p0(10,10);
  SUBCASE("All characters are printable character"){
    for (std::size_t i = 0 ; i < p0.getH(); i++ )
      for (std::size_t j = 0 ; j < p0.getW(); j++)
        {
          CHECK(p0(i,j)>=33);
          CHECK(p0(i,j)<=94);
        }
  }
  SUBCASE("Same grids are equals")
    {
      CHECK_FALSE(notEqualGrids(p0,p0));
    }
  SUBCASE("Two successively generated grid are different")
    {
      PassGrid p1(10,10);
      CHECK(notEqualGrids(p0,p1));
    }
  SUBCASE("reset make differences")
    {
      PassGrid p1(p0);
      p0.reset();
      CHECK(notEqualGrids(p0,p1));
    }
}
TEST_SUITE("grid save"){
  TEST_CASE("5: check save and load")
    {
      PassGrid p0(10,10);
      PassGrid p1(p0);
      std::fstream fs;
      fs.open ("grid.txt.out", std::fstream::out);
      p0.save(fs);
      fs.close();
      fs.open ("grid.txt.out", std::fstream::in);
      p0.load(fs);
      CHECK(!notEqualGrids(p0,p1));
      
      fs.close();

    }
}
TEST_SUITE("path"){
  TEST_CASE("3: check path start")
    {
      Path p(4,4,5);
      CHECK(p.getStartX() >= 0);
      CHECK(p.getStartX() <= 4);
      CHECK(p.getStartY() >= 0);
      CHECK(p.getStartY() <= 5);
    }

  TEST_CASE("7: Path Created correctly")
    {
      Path p(4,9,8);
      SUBCASE("Correct size")
        {
          CHECK(p.getSize() == 4);
        }
      SUBCASE(" starting point whithin bounds")
        {
          CHECK(p.getStartX() >= 0);
          CHECK(p.getStartX() <= 9);
          CHECK(p.getStartY() >= 0);
          CHECK(p.getStartY() <= 8);
        }
    }
}


TEST_SUITE("password generation") {
    TEST_CASE("8: Length password") {
        PassGrid passGrid(5, 5); 
        Path path(4, 5, 5);     
        std::string generatedPassword = passGrid.generate(path);
        CHECK(generatedPassword.length() == path.getSize());
        }
    TEST_CASE("8: Correct password") {
		PassGrid passGrid(5, 5);
		Path path(4, 4, 4);
		std::string generatedPassword = passGrid.generate(path);
		std::size_t x = path.getStartX();
		std::size_t y = path.getStartY();
		std::size_t _w = passGrid.getW();
		std::size_t _h = passGrid.getH();;

		for (std::size_t i = 0; i < path.getSize(); i++) {

			if (x >= _w && y >= _h) {
				switch (path(i))
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
			}
			else if (x >= _w && y <= 0) {
				switch (path(i))
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
			}
			else if (x >= _w)
			{
				switch (path(i))
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
			}
			else if (y >= _h)
			{
				switch (path(i))
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

			}
			else if (x <= 0 && y <= 0)
			{
				switch (path(i))
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

			}
			else if (x <= 0 && y >= _h)
			{
				switch (path(i))
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

			}

			else
			{
				switch (path(i))
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
			}
			char expectedChar = passGrid(y - 1, x - 1);
			CHECK(generatedPassword[i] == expectedChar);

		}

	}
}

