#ifndef Explosion_h
#define Explosion_h
#include "GameEntity.h"
#include "Effect.h"
// Explosion Class
class Explosion : public GameEntity, public Effect
{
public:
    Explosion(int x, int y) : GameEntity(x, y, static_cast<char>(GameEntityType::ExplosionType)) {}

    void apply(GameEntity &entity) override
    {
        entity = GameEntity(-1, -1, static_cast<char>(GameEntityType::NoneType));
    }
};

#endif