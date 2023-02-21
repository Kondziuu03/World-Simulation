#include <iostream>
#include "Antelope.h"

using namespace std;

Antelope::Antelope(World& world, Point point, int turnOfBirth, OrganismType organismType) 
	: Animal(world, point,turnOfBirth, organismType ,ANTELOPE_SYMBOL, ANTELOPE_POWER, ANTELOPE_INITIATIVE) {}

Organism* Antelope::CreateNewOrganism(Point point) {
	return new Antelope(this->world, point, this->world.GetTurn(), OrganismType::ANTELOPE);
}



bool Antelope::IsAttackDefended(Organism* attacker) {
	int escapeFromFight = rand() % 100;
	if (escapeFromFight < 50) {
		Point tmpPoint = Point(this->GetX(), this->GetY());
		this->world.RemoveOrganismFromField(attacker);
		this->MakeMove(true,BASIC_MOVEMENT_RANGE);
		this->world.MoveOrganismToField(attacker, tmpPoint);
		this->Print();
		cout << " udalo sie uciec przed walka" << endl;
		return true;
	}
	else return false;
}

void Antelope::Action() {
	this->MakeMove(false, ANTELOPE_MOVEMENT_RANGE);
}

Antelope::~Antelope() {}