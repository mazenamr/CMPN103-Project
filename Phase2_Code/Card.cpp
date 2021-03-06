#include "Card.h"


Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	if (cardNumber > 0 && cardNumber < 15) 
	{
		cardNumber = cnum; // needs validation
		}
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Output function that draws a cell containing the "cardNumber" in "position"

	pOut->DrawCell(position, cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + " ! Click to continue ...");
}

bool Card::IsOverlapping(GameObject* newObj) const
{
	return false;
}

void Card::Save(ofstream& OutFile, GameObjectType Type)
{
	if (Type != CARD)
	{
		return;
	}
	OutFile << cardNumber << ' ' << position.GetCellNum();
}

bool Card::Load(ifstream& InFile)
{
	int pos;
	InFile >> pos;
	position = CellPosition(pos);
	return true;
}

Card::~Card()
{
}
