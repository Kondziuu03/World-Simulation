#include <iostream>
#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Hedgehog.h"
#include "Grass.h"
#include "Koka.h"
#include "Guarana.h"
#include <fstream>

#define NUMBER_OF_ORGANISMS 8

using namespace std;

World::World() {
	this->height = 0;
	this->width = 0;
	this->turn = 0;
	this->board = NULL;
}

World::World(int height, int width) {
	this->width = width;
	this->height = height;
	this->turn = 0;
	CreateBoard(width, height);
	InitBoard();
}

void World::CreateBoard(int width, int height) {
	this->board = new Organism * *[width];
	for (int i = 0; i < width; i++) {
		this->board[i] = new Organism * [height];
	}
}

void World::InitBoard() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++)
			this->board[i][j] = NULL;
	}
}

Organism* World::CreateRandomOrganism() {
	int x, y, organismType;

	do {
		x = rand() % this->height;
		y = rand() % this->width;
	} while (this->board[x][y] != NULL);

	organismType = rand() % NUMBER_OF_ORGANISMS;
	return CreateOrganism(this,x,y,organismType);
	
}

Organism* World::CreateOrganism(World* world,int x,int y,int organismType) {
	if (organismType == OrganismType::WOLF) return new Wolf(*this, Point(x, y), this->turn, OrganismType::WOLF);
	else if (organismType == OrganismType::SHEEP) return new Sheep(*this, Point(x, y), this->turn, OrganismType::SHEEP);
	else if (organismType == OrganismType::TURTLE) return new Turtle(*this, Point(x, y), this->turn, OrganismType::TURTLE);
	else if (organismType == OrganismType::ANTELOPE) return new Antelope(*this, Point(x, y), this->turn, OrganismType::ANTELOPE);
	else if (organismType == OrganismType::HEDGEHOG) return new Hedgehog(*this, Point(x, y), this->turn, OrganismType::HEDGEHOG);
	else if (organismType == OrganismType::GRASS) return new Grass(*this, Point(x, y), this->turn, OrganismType::GRASS);
	else if (organismType == OrganismType::KOKA) return new Koka(*this, Point(x, y), this->turn, OrganismType::KOKA);
	else if (organismType == OrganismType::GUARANA) return new Guarana(*this, Point(x, y), this->turn, OrganismType::GUARANA);
	else return NULL;
}

void World::GenerateOrganisms() {
	int fields = this->height * this->width;
	Organism* newOrganism = NULL;

	for (int i = 0; i < fields / 3; i++) {
		newOrganism = CreateRandomOrganism();
		if (newOrganism != NULL) this->AddOrganism(newOrganism);
	}
}

void World::SortOrganisms() {
	this->organisms.sort([](Organism* organism1, Organism* organism2) {
		if (organism1->GetInitiative() == organism2->GetInitiative())
			return organism1->GetTurnOfBirth() < organism2->GetTurnOfBirth();
		return organism1->GetInitiative() > organism2->GetInitiative();
		});
}


void World::DeleteDeadOrganisms() {
	list<Organism*> tmpList;
	for (auto organism : this->organisms) {
		if (organism->IsAlive() == true) {
			tmpList.push_back(organism);
		}
	}
	this->organisms.clear();
	this->organisms = tmpList;
	tmpList.clear();
}

int World::GetBoardWidth() {
	return this->width;
}

int World::GetBoardHeight() {
	return this->height;
}

int World::GetTurn() {
	return this->turn;
}

bool World::isEmptyField(int x, int y) {
	if (this->board[x][y] == NULL) return true;
	else return false;
}

Organism* World::GetOrganismFromField(int x, int y) {
	return this->board[x][y];
}

void World::AddOrganism(Organism* other) {
	this->organisms.push_back(other);
	this->board[other->GetX()][other->GetY()] = other;
}

void World::RemoveOrganismFromField(Organism* organismToRemove) {
	this->board[organismToRemove->GetX()][organismToRemove->GetY()] = NULL;
}

void World::AddOrganismToField(Organism* organismToAdd) {
	this->board[organismToAdd->GetX()][organismToAdd->GetY()] = organismToAdd;
}

void World::MoveOrganismToField(Organism* organism, Point newPoint) {
	organism->SetX(newPoint.GetX());
	organism->SetY(newPoint.GetY());
	this->AddOrganismToField(organism);
}

void World::NextTurn() {
	int moves;
	SortOrganisms();
	cout << "Zaczynamy ture nr. " << this->turn + 1 << endl;
	for (auto organism : organisms)
	{
		if (organism->IsAlive()) {
			if (organism->GetPause() != 0) {
				if (organism->IsAlive() == true) organism->SetPause(organism->GetPause() - 1);
			}
			else {
				if (organism->GetExtraMoves() != 0) {
					moves = organism->GetExtraMoves();
					for (int i = 0; i < moves + 1; i++) {
						if (organism->IsAlive() == true) {
							organism->Action();
							organism->SetExtraMoves(organism->GetExtraMoves() - 1);
						}
					}
				}
				else organism->Action();
			}
		}
	}
	this->turn++;
}

void World::DrawWorld() {
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			if (this->board[i][j] == NULL) cout << "-";
			else this->board[i][j]->Draw();
		}
		cout << endl;
	}
	cout << endl;
}

void World::SaveWorld() {
	this->DeleteDeadOrganisms();
	ofstream file;
	string filePath;
	cout << "Nazwa pliku do zapisu: " << endl;
	cin >> filePath;
	filePath += ".txt";

	file.open(filePath, ofstream::app);
	if (!file.is_open()) cout << "Blad zapisu" << endl;
	else {
		file << this->height;
		file << " ";
		file << this->width;
		file << " ";
		file << this->turn;
		file << "\n";
		for (auto organism : this->organisms) {
			file << organism->GetX();
			file << " ";
			file << organism->GetY();
			file << " ";
			file << organism->GetTurnOfBirth();;
			file << " ";
			file << organism->GetOrganismType();
			file << " ";
			file << organism->GetExtraMoves();
			file << " ";
			file << organism->GetPause();
			file << " ";
			file << organism->GetPower();
			file << "\n";
		}
		cout << "Gra jest zapisana" << endl;
	}
}

void World::LoadWorld() {
	ifstream file;
	string filePath;
	cout << "Nazwa pliku: ";
	cin >> filePath;
	filePath += ".txt";
	file.open(filePath);

	if (!file.is_open()) {
		cout << "Blad odczytu" << endl;
	}
	else {
		int height, width, turn;
		int x, y, power, turnOfBirth, extraMoves, pause,organismType;
		file >> this->height;
		file >> this->width;
		CreateBoard(this->height, this->width);
		InitBoard();
		this->organisms.clear();
		file >> turn;
		this->turn = turn;

		Organism* tmpOrganism = NULL;

		while (!file.eof()) {
			file >> x;
			file >> y;
			file >> turnOfBirth;
			file >> organismType;
			file >> extraMoves;
			file >> pause;
			file >> power;
			tmpOrganism = CreateOrganism(this, x, y, organismType);
			if (tmpOrganism != NULL) {
				tmpOrganism->SetPower(power);
				tmpOrganism->SetExtraMoves(extraMoves);
				tmpOrganism->SetPause(pause);
				this->AddOrganism(tmpOrganism);
			}
		}
		this->organisms.pop_back();
	}
}

World::~World() {
	for (int i = 0; i < width; i++) {
		delete[] this->board[i];
	}
	delete this->board;
}