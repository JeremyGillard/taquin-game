#include "board.h"
#include "catch.hpp"

TEST_CASE("Init Board Tests")
{
    SECTION("Init Board check with chosenSize")
    {
        unsigned chosenSize = 4;
        Board board(chosenSize);
        REQUIRE(board.size() == chosenSize);
    }
}

TEST_CASE("Get zero position method Tests")
{
    SECTION("Get zero position without shuffle")
    {
        Board board(3);
        std::pair<unsigned, unsigned> zeroPos(2, 2);
        REQUIRE(board.getZeroPosition() == zeroPos);
    }

    SECTION("Get zero position with shuffle")
    {
        Board board(5);
        board.shuffle(10);
        std::pair<unsigned, unsigned> zeroPos(4, 4);
        REQUIRE(board.getZeroPosition() != zeroPos);
    }
}

TEST_CASE("Get available movements method Tests")
{
    SECTION("Get available movements without shuffle")
    {
        Board board(3);
        std::vector<std::pair<unsigned, unsigned>> movements = {
            std::make_pair(1, 2), std::make_pair(2, 1)
        };
        REQUIRE(movements == board.getAvailableMovements());
    }

    SECTION("Get available movements with shuffle")
    {
        Board board(5);
        board.shuffle(10);
        std::vector<std::pair<unsigned, unsigned>> movements = {
            std::make_pair(3, 4), std::make_pair(4, 3)
        };
        REQUIRE(movements != board.getAvailableMovements());
    }
}

TEST_CASE("Are Coordinates Ok method Tests")
{
    SECTION("Are Coordinates Ok without shuffle")
    {
        Board board(3);
        std::pair<unsigned, unsigned> coord(1, 2);
        REQUIRE(board.areCoordinatesOk(coord.first, coord.second));
    }

    SECTION("Are Coordinates Ok with shuffle")
    {
        Board board(5);
        board.shuffle(10);
        std::pair<unsigned, unsigned> coord(4, 4);
        REQUIRE(!board.areCoordinatesOk(coord.first, coord.second));
    }

    SECTION("Are Coordinates Ok with shuffle and getAvailableMovements")
    {
        Board board(3);
        board.shuffle(10);
        std::pair<unsigned, unsigned> coord = board.getAvailableMovements().at(0);
        REQUIRE(board.areCoordinatesOk(coord.first, coord.second));
    }
}

TEST_CASE("operator== method Tests")
{
    SECTION("operator== method without shuffle")
    {
        Board board1(3);
        Board board2(3);
        REQUIRE(board1 == board2);
    }

    SECTION("operator== method with shuffle")
    {
        Board board1(3);
        Board board2(3);
        board2.shuffle(10);
        REQUIRE(!(board1 == board2));
    }

    SECTION("operator== method diff size")
    {
        Board board1(3);
        Board board2(4);
        REQUIRE(!(board1 == board2));
    }
}

TEST_CASE("Get cell at method Tests")
{
    SECTION("Get cell at without shuffle")
    {
        Board board(3);
        REQUIRE(0 == board.getCellAt(2, 2));
    }

    SECTION("Get cell at with shuffle 0 pos")
    {
        Board board(3);
        board.shuffle(10);
        REQUIRE(0 != board.getCellAt(2, 2));
    }

    SECTION("Get cell at with shuffle 1 pos")
    {
        Board board(3);
        board.shuffle(1);
        REQUIRE(1 == board.getCellAt(0, 0));
    }
}

TEST_CASE("Move cell method Tests")
{
    SECTION("Move cell wrong coords")
    {
        Board board(3);
        REQUIRE(!board.moveCell(0, 0));
    }

    SECTION("Move cell good coords")
    {
        Board board(3);
        REQUIRE(board.moveCell(2, 1));
    }

    SECTION("Move cell board equality")
    {
        Board board(3);
        Board boardTest(3);
        board.moveCell(2, 1);
        REQUIRE(!(board == boardTest));
    }
}
