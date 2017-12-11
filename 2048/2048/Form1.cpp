#include "stdafx.h"
#include "Form1.h"
// #include "Form1.h"

int field[4][4] = { { 2, 0, 0, 0 }, 
					{ 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 } };

inline System::Void CppCLR_WinformsProjekt::Form1::pictureBox1_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
{
	for (int i = 0; i < 4; i++)
	{
		e->Graphics->FillRectangle(Brushes::Cornsilk, (5 + 60 * i + 5 * i), 5, 60, 60);
		e->Graphics->DrawString(field[0][i].ToString(), gcnew System::Drawing::Font("Arial", 14), Brushes::Black, (25 + 60 * i + 5 * i), 25);
	}
	for (int i = 0; i < 4; i++)
	{
		e->Graphics->FillRectangle(Brushes::Cornsilk, (5 + 60 * i + 5 * i), 70, 60, 60);
		e->Graphics->DrawString(field[1][i].ToString(), gcnew System::Drawing::Font("Arial", 14), Brushes::Black, (25 + 60 * i + 5 * i), 90);
	}
	for (int i = 0; i < 4; i++)
	{
		e->Graphics->FillRectangle(Brushes::Cornsilk, (5 + 60 * i + 5 * i), 135, 60, 60);
		e->Graphics->DrawString(field[2][i].ToString(), gcnew System::Drawing::Font("Arial", 14), Brushes::Black, (25 + 60 * i + 5 * i), 155);
	}
	for (int i = 0; i < 4; i++)
	{
		e->Graphics->FillRectangle(Brushes::Cornsilk, (5 + 60 * i + 5 * i), 200, 60, 60);
		e->Graphics->DrawString(field[3][i].ToString(), gcnew System::Drawing::Font("Arial", 14), Brushes::Black, (25 + 60 * i + 5 * i), 220);
	}
}

inline System::Void CppCLR_WinformsProjekt::Form1::Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
	if (e->KeyChar == (Char)Keys::S)
	{
		Drop();	
	}
	if (e->KeyChar == (Char)Keys::A)
	{
		CppCLR_WinformsProjekt::Form1::Rotate();
		CppCLR_WinformsProjekt::Form1::Rotate();
		CppCLR_WinformsProjekt::Form1::Rotate();
		Drop();
		CppCLR_WinformsProjekt::Form1::Rotate();
	}
	if (e->KeyChar == (Char)Keys::D)
	{
		CppCLR_WinformsProjekt::Form1::Rotate();
		Drop();
		CppCLR_WinformsProjekt::Form1::Rotate();
		CppCLR_WinformsProjekt::Form1::Rotate();
		CppCLR_WinformsProjekt::Form1::Rotate();
	}
	if (e->KeyChar == (Char)Keys::W)
	{
		CppCLR_WinformsProjekt::Form1::Rotate();
		CppCLR_WinformsProjekt::Form1::Rotate();
		Drop();
		CppCLR_WinformsProjekt::Form1::Rotate();
		CppCLR_WinformsProjekt::Form1::Rotate();
	}
	Control::Refresh();
}

inline System::Void CppCLR_WinformsProjekt::Form1::Drop() {
	int cur = 0;
	int posI = 0;
	int posJ = 0;
	bool isCanMove = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (field[j][i] == 0 && field[j - 1][i] != 0 || field[j][i] == field[j - 1][i] && field[j][i] != 0)
			{
				isCanMove = true;
			}
		}
	}
	if (isCanMove)
	{
		for (int i = 0; i < 4; i++)
		{
			cur = field[3][i];
			posI = i;
			posJ = 3;
			for (int j = 2; j > -1; j--)
			{
				if (cur == 0 && field[j][i] != 0)
				{
					cur = field[j][i];
					posI = i;
					posJ = j;
				}
				else
					if (cur != 0 && field[j][i] == cur)
					{
						field[posJ][posI] += field[j][i];
						field[j][i] = 0;
						cur = field[j][i];
						posI = i;
						posJ = j;
					}
					else
						if (cur != 0 && field[j][i] != cur && field[j][i] != 0)
						{
							cur = field[j][i];
							posI = i;
							posJ = j;
						}
			}
		}
		int steps;
		for (int i = 0; i < 4; i++)
		{
			steps = 0;
			for (int j = 3; j > -1; j--)
			{
				if (field[j][i] == 0)
				{
					steps++;
				}
				else
					if (field[j][i] != 0 && j != 3)
					{
						if (j + steps != j)
						{
							field[j + steps][i] = field[j][i];
							field[j][i] = 0;
						}
					}
			}
		}
		Generate();
	}
	
}

inline System::Void CppCLR_WinformsProjekt::Form1::Rotate() {
	int temp[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp[i][j] = field[4 - j - 1][i];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			field[i][j] = temp[i][j];
		}
	}
}

inline System::Void CppCLR_WinformsProjekt::Form1::Generate() {
	int zeroCount = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (field[i][j] == 0)
			{
				zeroCount++;
			}
		}
	}
	if (zeroCount == 0)
	{
		label1->Text = "Сосать господин судья";
		return;
	}
	Random^ ran = gcnew Random();
	int pos = ran->Next(1, zeroCount);
	zeroCount = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (field[i][j] == 0)
			{
				zeroCount++;
				if (zeroCount == pos)
				{
					field[i][j] = 2;
					return;
				}
			}
		}
	}
}

inline System::Void CppCLR_WinformsProjekt::Form1::Form1_Click(System::Object^  sender, System::EventArgs^  e) {
	
}