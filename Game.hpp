//
// Created by nickobelic1999 on 2/08/2023.
//

#pragma once

#include "Snake.hpp"
#include "Food.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace CoreGame
{
    /*
    GameController is the central interface of the game.
    This class will monitor the working of game:
    *	Movement of snake
    *	Checking collisions
    *	When to play sound etc
    */


    const std::string MenuStrings[5] =
    {
        "Game Over!",
        "Do you wish to continue?",
        "Yes",
        "No",
        "Exit"
    }; //menu strings

    enum MenuText
    {
        GameOver,
        Continue,
        Yes,
        No,
        Exit,
    }; //menuText

    enum Fonts
    {};

    class GameController
    {
    public:

        void start();

        sf::Font* getFont(Fonts font);


        explicit GameController(sf::RenderWindow* w);

    private:

        //Main game loop
        void gameLoop();

        //Setup scene
        void setupScene();

        // Read scores in
        void readScores(const std::string& file);

        // Sort scores
        void sortScores(/* Possible parameters */);

        // Method to write a new score to the score file.
        void submitScore(const std::string& file);

        // Game over
        void gameOver();

        //load resources
        void loadResources();

        float                   scale;
        std::string             name;
        int                     score;
        bool                    loopInvarient;

        Snake                   snake;
        sf::RenderWindow*       screen;
        sf::Font                fontList[3];
        json                    scoresList;


    };

}


