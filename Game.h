#include <vector>
#include "GameEntity.h"
#include "Utils.h"
#include "Ship.h"
#include "Mine.h"
class Game
{
private:
    std::vector<GameEntity *> entities;

public:
    std::vector<GameEntity *> get_entities() const
    {
        return entities;
    }

    void initGame(int numShips, int numMines, int gridWidth, int gridHeight)
    {
        for (int i = 0; i < numShips; ++i)
        {
            auto randomPos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Ship(std::get<0>(randomPos), std::get<1>(randomPos)));
        }
        for (int i = 0; i < numMines; ++i)
        {
            auto randomPos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Mine(std::get<0>(randomPos), std::get<1>(randomPos)));
        }
    }

    void gameLoop(int maxIterations, double mineDistanceThreshold)
    {
        for (int iter = 0; iter < maxIterations; ++iter)
        {
            for (auto &entity : entities)
            {
                Ship *ship = dynamic_cast<Ship *>(entity);
                if (ship)
                {
                    ship->move(1, 0); // Moving all ships by (1, 0)
                }

                // Check distance between ships and mines
                for (auto &mineEntity : entities)
                {
                    Mine *mine = dynamic_cast<Mine *>(mineEntity);
                    if (mine)
                    {
                        double distance = Utils::calculateDistance(ship->getPos(), mine->getPos());
                        if (distance <= mineDistanceThreshold)
                        {
                            Explosion explosion = mine->explode();
                            explosion.apply(*ship); // Apply explosion to the ship
                        }
                    }
                }
            }

            // Termination condition if all ships are destroyed or max iterations are reached
            bool allShipsDestroyed = true;
            for (auto &entity : entities)
            {
                if (dynamic_cast<Ship *>(entity))
                {
                    allShipsDestroyed = false;
                    break;
                }
            }

            if (allShipsDestroyed)
            {
                break;
            }
        }
    }
};
