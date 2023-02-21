#pragma once
#include "Organism.h"
#include <list>
using namespace std;

class Organism;

class World {
private:
	int width;
	int height;
	int turn;
	Organism*** board;
	list<Organism*> organisms;
	void CreateBoard(int width, int height);
	void InitBoard();
	Organism* CreateRandomOrganism();
	void SortOrganisms();
	void DeleteDeadOrganisms();
	Organism* CreateOrganism(World* world,int x,int y,int organismType);
public:
	World();
	World(int height, int width);
	int GetBoardWidth();
	int GetBoardHeight();
	int GetTurn();
	bool isEmptyField(int x, int y);
	Organism* GetOrganismFromField(int x, int y);
	void AddOrganism(Organism* other);
	void RemoveOrganismFromField(Organism* organismToRemove);
	void AddOrganismToField(Organism* organismToAdd);
	void MoveOrganismToField(Organism* organism, Point point);
	void GenerateOrganisms();
	void SaveWorld();
	void LoadWorld();
	void NextTurn();
	void DrawWorld();
	~World();
};