#pragma once

#include "Vector.hpp"

enum COLLISION {
    WALL,
    FOOD,
    NONE
};

class CollisionObserver {
    public:
        virtual COLLISION checkCollision(Vector) = 0;
};