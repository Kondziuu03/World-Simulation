#pragma once
#include <iostream>
#include "Point.h"
#include "World.h"
#include "Enums.h"

#define BASIC_MOVEMENT_RANGE 1
#define DIRECTIONS 4
#define DIRECTION_BLOCKED 1
#define DIRECTION_OPEN 0

class World;
class Punkt;

class Organism {
protected:
	int power;
	int initiative;
	int turnOfBirth;
	int pause;
	int extraMoves;
	char organismSymbol;
	bool isAlive;
	OrganismType organismType;
	Point point;
	World& world;
	void KillLoser(Organism* winner, Organism* loser);
	void PrintFightResult(Organism* winner, Organism* loser);
	void MoveOrganism(Organism* organismToMove, Directions direction, int movementRange);
	void CreateChild(Organism* attacker);
	virtual void PrintCreateChildResult(Organism* otherOrganism, Organism* newOrganism) = 0;
	void MoveAttackerToLoserField(Organism* winner, Organism* loser);
	void MakeMove(bool moveToEmptyField, int movementRange);
	void Attack(Point& tmpPoint);
	virtual bool IsAttackDefended(Organism* attacker);
public:
	Organism(World& world, Point point,int turnOfBirth,OrganismType organismType ,char symbol, int power, int initiative);
	int GetX();
	int GetY();
	void SetY(int y);
	void SetX(int x);
	int GetPower();
	int GetInitiative();
	int GetPause();
	int GetTurnOfBirth();
	int GetExtraMoves();
	void SetExtraMoves(int extraMoves);
	void SetPause(int pause);
	void SetPower(int power);
	bool IsAlive();
	void SetOrganismIsAlive(bool isAlive);
	virtual void SpecialMoveAfterDeath(Organism* killer) {};
	OrganismType GetOrganismType();
	virtual void Action() = 0;
	virtual void Collision(Organism* attacker) = 0;
	virtual Organism* CreateNewOrganism(Point point) = 0;
	void Draw();
	void Print();
	virtual ~Organism();
};

