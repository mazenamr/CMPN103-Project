#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
	initial = false;
}

CardOne::~CardOne(void)
{
}

int CardOne::walletAmount = 0;
bool CardOne::initiated = false;

void CardOne::ReadCardParameters(Grid* pGrid)
{
	if (!initiated)
	{

		///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


		// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


		// 1- Get a Pointer to the Input / Output Interfaces from the Grid

		Input* pIn = NULL;
		pIn = pGrid->GetInput();

		Output* pOut = NULL;
		pOut = pGrid->GetOutput();

		// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
		//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."

		pOut->PrintMessage("New CardOne: Enter its wallet amount: ");
		walletAmount = pIn->GetInteger(pOut);
		initiated = true;
		initial = true;

		// [ Note ]:
		// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
		// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
		// to be able to perform his Apply() action

		// 3- Clear the status bar

		pOut->ClearStatusBar();
	}
}


void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number


	Card::Apply(pGrid, pPlayer);

	pPlayer = pGrid->GetCurrentPlayer();

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

	pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);

}

void CardOne::Save(ofstream& OutFile, GameObjectType Type)
{
	Card::Save(OutFile, Type);
	if (Type != CARD)
	{
		return;
	}
	OutFile << ' ' << walletAmount << endl;
}

bool CardOne::Load(ifstream& InFile)
{
	Card::Load(InFile);
	InFile >> walletAmount;
	return true;
}
