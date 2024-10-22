#ifndef MINE_H
#define MINE_H
#include "GameEntity.h"
#include "Explosion.h"
// Mine Class
class Mine : public GameEntity
{
public:
    Mine(int x, int y) : GameEntity(x, y, static_cast<char>(GameEntityType::MineType)) {}

    Explosion explode()
    {
        type = GameEntityType::NoneType;
        return Explosion(std::get<0>(position), std::get<1>(position));
    }
};
#endif