#include "Player.h"

// Sets our member functions SPEED, SHIFT_SPEED, CROUCH_SPEED = to paramaters somebody passes
Player::Player(const float HEIGHT, const float SPEED, const float SHIFT_SPEED, const float CROUCH_SPEED)
    : 
    HEIGHT{HEIGHT},
    SPEED(SPEED), 
    SHIFT_SPEED(SHIFT_SPEED), 
    CROUCH_SPEED(CROUCH_SPEED)
{
    MovementSpeed = SPEED;
    ShiftWalking = false;
    Crouched = false;
    Moving = false; 
    Health = 100;
}

void Player::Shift_Walk()
{
    MovementSpeed = SHIFT_SPEED;
}

void Player::Crouch_Walk()
{
    MovementSpeed = CROUCH_SPEED;
}
