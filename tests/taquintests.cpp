#include "catch.hpp"
#include "taquin.h"

TEST_CASE("Init Board method Tests")
{
    SECTION("Init Board check with chosenSize")
    {
        Taquin taquin;
        unsigned chosenSize = 4;
        taquin.initBoard(chosenSize);
        REQUIRE(taquin.chosenSize() == chosenSize);
    }
}

TEST_CASE("Move Cells Board method Tests")
{
    SECTION("Move cell check with numberOfMoves")
    {
        Taquin taquin;
        taquin.initBoard(4);
        taquin.start(0);
        taquin.moveCellBoard(3, 2);
        REQUIRE(taquin.getNumberOfMoves() == 1);
    }

    SECTION("Move cell check with numberOfMoves 2 moves")
    {
        Taquin taquin;
        taquin.initBoard(4);
        taquin.start(0);
        taquin.moveCellBoard(3, 2);
        taquin.moveCellBoard(3, 1);
        REQUIRE(taquin.getNumberOfMoves() == 2);
    }
}

TEST_CASE("Is Over method Tests")
{
    SECTION("Is Over check without shuffle")
    {
        Taquin taquin;
        taquin.initBoard(4);
        taquin.start(0);
        REQUIRE(taquin.isOver());
    }

    SECTION("Is Over check with shuffle")
    {
        Taquin taquin;
        taquin.initBoard(4);
        taquin.start(10);
        REQUIRE(!taquin.isOver());
    }
}

TEST_CASE("Get Cell At method Tests")
{
    SECTION("Get zero cell")
    {
        Taquin taquin;
        taquin.initBoard(4);
        taquin.start(0);
        REQUIRE(taquin.getCellAt(3, 3) == 0);
    }

    SECTION("Get Cell At check with shuffle")
    {
        Taquin taquin;
        taquin.initBoard(4);
        taquin.start(10);
        REQUIRE(taquin.getCellAt(3, 3) != 0);
    }
}

TEST_CASE("Get Move Options method Tests")
{
    SECTION("Get number ove options without shuffle == 2")
    {
        Taquin taquin;
        taquin.initBoard(4);
        taquin.start(0);
        REQUIRE(taquin.getMovesOptions().size() == 2);
    }

    SECTION("Get move options at 0 == pair(2, 3) without shuffle")
    {
        Taquin taquin;
        taquin.initBoard(4);
        taquin.start(0);
        std::pair<unsigned, unsigned> pTest(2, 3);
        REQUIRE(taquin.getMovesOptions().at(0) == pTest);
    }

    SECTION("Get move options at 1 == pair(3, 2) without shuffle")
    {
        Taquin taquin;
        taquin.initBoard(4);
        taquin.start(0);
        std::pair<unsigned, unsigned> pTest(3, 2);
        REQUIRE(taquin.getMovesOptions().at(1) == pTest);
    }
}
