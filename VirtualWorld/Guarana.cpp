#include <iostream>
#include "Guarana.h"

using namespace std;

Guarana::Guarana(World& world, Point point, int turnOfBirth, OrganismType organismType)
	: Plant(world, point, turnOfBirth, organismType, GUARANA_SYMBOL) {}

Organism* Guarana::CreateNewOrganism(Point point) {
	return new Guarana(this->world, point, this->world.GetTurn(), OrganismType::GUARANA);
}

void Guarana::SpecialMoveAfterDeath(Organism* killer) {
	killer->SetPower(killer->GetPower() + EXTRA_POWER);
	killer->Print();
	cout << " zwiekszyl sile o " << EXTRA_POWER << " po zjedzeniu ";
	this->Print();
	cout << endl;
}

Guarana::~Guarana() {}