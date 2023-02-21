#include "Organism.h"

using namespace std;

Organism::Organism(World& world, Point point,int turnOfBirth, OrganismType organismType,char symbol, int power, int initiative) 
	: world(world), point(point),turnOfBirth(turnOfBirth),organismType(organismType),organismSymbol(symbol), power(power), initiative(initiative) {
	this->isAlive = true;
	this->pause = 0;
	this->extraMoves = 0;
}

int Organism::GetX() {
	return this->point.GetX();
}

int Organism::GetY() {
	return this->point.GetY();
}

void Organism::SetX(int x) {
	this->point.SetX(x);
}

void Organism::SetY(int y) {
	this->point.SetY(y);
}

int Organism::GetPower() {
	return this->power;
}

int Organism::GetInitiative() {
	return this->initiative;
}

int Organism::GetPause() {
	return this->pause;
}

int Organism::GetTurnOfBirth() {
	return this->turnOfBirth;
}

int Organism::GetExtraMoves() {
	return this->extraMoves;
}

void Organism::SetExtraMoves(int extraMoves) {
	this->extraMoves = extraMoves;
}

void Organism::SetPower(int power) {
	this->power = power;
}

void Organism::SetPause(int pause) {
	this->pause = pause;
}

bool Organism::IsAlive() {
	if (this->isAlive == true) return true;
	else return false;
}

void Organism::SetOrganismIsAlive(bool isAlive) {
	this->isAlive = isAlive;
}

OrganismType Organism::GetOrganismType() {
	return this->organismType;
}

void Organism::Draw() {
	cout << this->organismSymbol;
}

void Organism::Print() {
	cout << this->organismSymbol << "(" << this->point.GetX() << "," << this->point.GetY() << ")";
}

void Organism::MakeMove(bool moveToEmptyField, int movementRange = BASIC_MOVEMENT_RANGE) {
	Point tmpPoint(this->GetX(), this->GetY());

	while (true) {
		int direction = rand() % 4;
		int directionsBlocked[DIRECTIONS] = {0,0,0,0};
		if (direction == Directions::UP && directionsBlocked[Directions::UP] == DIRECTION_OPEN) {
			if (this->GetX() > movementRange - 1) {
				if (this->world.isEmptyField(this->GetX() - movementRange, this->GetY()) == true) MoveOrganism(this, Directions::UP, movementRange);
				else if (moveToEmptyField == false) {
					tmpPoint.SetX(this->GetX() - movementRange);
					this->Attack(tmpPoint);
				}
				else if (moveToEmptyField == true) {
					directionsBlocked[Directions::UP] = DIRECTION_BLOCKED;
				}
				else continue;
				break;
			}
			else directionsBlocked[Directions::UP] = DIRECTION_BLOCKED;
		}
		else if (direction == Directions::DOWN && directionsBlocked[Directions::DOWN] == DIRECTION_OPEN) {
			if (this->GetX() < this->world.GetBoardHeight() - movementRange) {
				if (this->world.isEmptyField(this->GetX() + movementRange, this->GetY()) == true) MoveOrganism(this, Directions::DOWN, movementRange);
				else if (moveToEmptyField == false) {
					tmpPoint.SetX(this->GetX() + movementRange);
					this->Attack(tmpPoint);
				}
				else if (moveToEmptyField == true) {
					directionsBlocked[Directions::DOWN] = DIRECTION_BLOCKED;
				}
				else continue;
				break;
			}
			else directionsBlocked[Directions::DOWN] = DIRECTION_BLOCKED;
		}
		else if (direction == Directions::LEFT && directionsBlocked[Directions::LEFT] == DIRECTION_OPEN)
		{
			if (this->GetY() > movementRange - 1) {
				if (this->world.isEmptyField(this->GetX(), this->GetY() - movementRange) == true) MoveOrganism(this, Directions::LEFT, movementRange);
				else if (moveToEmptyField == false) {
					tmpPoint.SetY(this->GetY() - movementRange);
					this->Attack(tmpPoint);
				}
				else if (moveToEmptyField == true) {
					directionsBlocked[Directions::LEFT] = DIRECTION_BLOCKED;
				}
				else continue;
				break;
			}
			else directionsBlocked[Directions::LEFT] = DIRECTION_BLOCKED;
		}
		else if (direction == Directions::RIGHT && directionsBlocked[Directions::RIGHT] == DIRECTION_OPEN) {
			if (this->GetY() < this->world.GetBoardWidth() - movementRange) {
				if (this->world.isEmptyField(this->GetX(), this->GetY() + movementRange) == true) MoveOrganism(this, Directions::RIGHT, movementRange);
				else if (moveToEmptyField == false) {
					tmpPoint.SetY(this->GetY() + movementRange);
					this->Attack(tmpPoint);
				}
				else if (moveToEmptyField == true) {
					directionsBlocked[Directions::RIGHT] = DIRECTION_BLOCKED;
				}
				else continue;
				break;
			}
			else directionsBlocked[Directions::RIGHT] = DIRECTION_BLOCKED;
		}

		if (directionsBlocked[Directions::LEFT] == DIRECTION_BLOCKED &&
			directionsBlocked[Directions::RIGHT] == DIRECTION_BLOCKED &&
			directionsBlocked[Directions::UP] == DIRECTION_BLOCKED &&
			directionsBlocked[Directions::DOWN] == DIRECTION_BLOCKED) break;
	}
}

void Organism::Attack(Point& tmpPoint) {
	Organism* tmp = this->world.GetOrganismFromField(tmpPoint.GetX(), tmpPoint.GetY());
	if (tmp != NULL) tmp->Collision(this);
}

void Organism::CreateChild(Organism* attacker) {
	Point prevPoint(this->GetX(), this->GetY());
	Organism* newOrganism = NULL;
	newOrganism = this->CreateNewOrganism(prevPoint);
	newOrganism->MakeMove(true);
	if (this->point.GetX() != newOrganism->GetX() || this->point.GetY() != newOrganism->GetY()) {
		this->world.AddOrganismToField(this);
		if (newOrganism != NULL) {
			newOrganism->SetPause(1);
			this->world.AddOrganism(newOrganism);
			this->PrintCreateChildResult(attacker, newOrganism);
		}
	}
}

bool Organism::IsAttackDefended(Organism* attacker) {
	return false;
}

void Organism::MoveOrganism(Organism* organismToMove, Directions direction, int movementRange) {
	int x = this->point.GetX();
	int y = this->point.GetY();

	this->world.RemoveOrganismFromField(organismToMove);
	if (direction == Directions::LEFT) this->point.SetY(y - movementRange);
	else if (direction == Directions::RIGHT) this->point.SetY(y + movementRange);
	else if (direction == Directions::UP) this->point.SetX(x - movementRange);
	else if (direction == Directions::DOWN) this->point.SetX(x + movementRange);
	this->world.AddOrganismToField(this);
}

void Organism::KillLoser(Organism* winner, Organism* loser) {
	loser->SpecialMoveAfterDeath(winner);
	loser->SetOrganismIsAlive(false);
	this->world.RemoveOrganismFromField(loser);
}

void Organism::MoveAttackerToLoserField(Organism* winner, Organism* loser) {
	this->world.RemoveOrganismFromField(winner);
	winner->SetX(loser->GetX());
	winner->SetY(loser->GetY());
	this->world.AddOrganismToField(winner);
}

void Organism::PrintFightResult(Organism* winner, Organism* loser) {
	winner->Print();
	cout << " zabil ";
	loser->Print();
	cout << endl;
}

Organism::~Organism() {}