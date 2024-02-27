#pragma once

// SPEED, SHIFT_SPEED, & CROUCH_SPEED can be applied onto MovementSpeed
class Player
{
public:
	Player(const float SPEED, const float SHIFT_SPEED, const float CROUCH_SPEED);
	void Shift_Walk();
	void Crouch_Walk();

public:
	float MovementSpeed;
	bool ShiftWalking;
	bool Crouched;
	bool Moving;

	const float SPEED;
	const float SHIFT_SPEED;
	const float CROUCH_SPEED;
};