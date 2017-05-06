#ifndef GAMESTATESNAKE_H_
#define GAMESTATESNAKE_H_

#include "gameapi/GameState.h"
#include <vector>

struct Point {
    int32_t x;
    int32_t y;
};

enum class Direction { UP,DOWN,LEFT,RIGHT };

class GameStateSnake : public GameState {
private:
    // TODO: Fill in
    GameManager* gameManager;
    bool gameSpaceInitNeeded;
    bool newGame;
    std::vector<Point> snake;
    Direction dir;
    struct Point food;
    bool newFoodNeeded;
    int32_t xmin;
    int32_t xmax;
    int32_t ymin;
    int32_t ymax;
public:
    GameStateSnake() {
        gameSpaceInitNeeded = true;
        std::srand(time(NULL));
        newGame = true;
        newFoodNeeded = true;
        dir = Direction::UP;
    }

    void tick(GameManager* gameManager);

    void handleInput(Key key);

    std::vector<Point> createSnake(int size, int32_t x, int32_t y );

    bool isInBoundsOfFood(int32_t x, int32_t y);

    void generateNextFood();

    void initGameSpace(AnsiImage* img);

    bool isInBoundsOfSnake(int32_t x, int32_t y);

    bool isInBoundsOfSnakeNotHead(int32_t x, int32_t y);
};

#endif
