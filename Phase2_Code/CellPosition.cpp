#include "CellPosition.h"

#include "UI_Info.h"

CellPosition::CellPosition ()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition (int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)

		if (v < NumVerticalCells && v >= 0)
		{
		vCell = v;
		return true;
		}

	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)

	if (h < NumHorizontalCells && h >= 0)
	{
		hCell = h;
		return true;
	}

	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file

	return (vCell < NumVerticalCells && vCell >= 0
		&& hCell < NumHorizontalCells && hCell >= 0); // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file

	if (cellPosition.VCell() == -1 || cellPosition.HCell() == -1)
	{
		return -1;
	}

	int cPos = NumHorizontalCells * (NumVerticalCells - cellPosition.VCell()) - (NumHorizontalCells - cellPosition.HCell()) + 1;
	return cPos; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file
	
	int posH, posV;

	if (cellNum > 0 && cellNum <= NumHorizontalCells * NumVerticalCells)
	{
		posH = (cellNum - 1) % NumHorizontalCells;
		posV = NumVerticalCells - ((cellNum + NumHorizontalCells - posH + 1) / NumHorizontalCells);
	}
	else
	{
		posH = -1;
		posV = -1;
	}
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it

	position.SetHCell(posH);
	position.SetVCell(posV);

	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	/// TODO: Implement this function as described in the .h file

	int cellNum = GetCellNum() + addedNum;
	if (cellNum > 0 && cellNum <= NumHorizontalCells * NumVerticalCells)
	{
	(*this) = GetCellPositionFromNum(cellNum);
	}

	// Note: this function updates the data members (vCell and hCell) of the calling object
}