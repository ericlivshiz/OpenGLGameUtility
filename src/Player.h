#pragma once

// SPEED, SHIFT_SPEED, & CROUCH_SPEED can be applied onto MovementSpeed
class Player
{
public:
	Player(const float PLAYER_HEIGHT, const float SPEED, const float SHIFT_SPEED, const float CROUCH_SPEED);
	void Shift_Walk();
	void Crouch_Walk();

public:
	float MovementSpeed;
	bool ShiftWalking;
	bool Crouched;
	bool Moving;
	bool Jumping;
	unsigned int Health;
	float Velocity;

	const float SPEED;
	const float SHIFT_SPEED;
	const float CROUCH_SPEED;
	const float HEIGHT;
};