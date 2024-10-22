#ifndef GAMEENTITY_H
#define GAMEENTITY_H
#include <tuple>
#include <iostream>
class GameEntity
{
protected:
    enum GameEntityType
    {
        ExplosionType,
        MineType,
        NoneType,
        ShipType
    };
    std::tuple<int, int> position;
    GameEntityType type;

public:
    GameEntity() {}
    GameEntity(int x, int y, char type) : position(x, y)
    {
        switch (type)
        {
        case 'E':
            type = ExplosionType;
            break;
        case 'M':
            type = MineType;
            break;
        case 'N':
            type = NoneType;
            break;
        case 'S':
            type = ShipType;
            break;
        default:
            type = NoneType;
            break;
        }
    };
    std::tuple<int, int> getPos() { return position; };
    GameEntityType getType() { return type; }
    void set_Pos(int x, int y)
    {
        std::get<0>(position) = x;
        std::get<1>(position) = y;
    }
    void set_type(char a)
    {
        switch (a)
        {
        case 'E':
            type = ExplosionType;
            break;
        case 'M':
            type = MineType;
            break;
        case 'N':
            type = NoneType;
            break;
        case 'S':
            type = ShipType;
            break;
        default:
            type = NoneType;
            break;
        }
    }
};

#endif