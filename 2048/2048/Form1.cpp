#include "stdafx.h"
#include "Form1.h"
// #include "Form1.h"

int field[4][4] = { { 2, 0, 0, 0 }, 
					{ 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 }, 
					{ 0, 0, 0, 0 } };

int score = 0;

inline System::Drawing::SolidBrush^ CppCLR_WinformsProjekt::Form1::GenerateColor(int value) {
	SolidBrush^ solidbrush;
	if (value == 0)
	{
		Color^ cl = gcnew Color();
		solidbrush = gcnew SolidBrush(cl->FromArgb(122, 122, 122));
	}
	if (value == 2)
	{
		Color^ cl = gcnew Color();
		solidbrush = gcnew SolidBrush(cl->FromArgb(238, 228, 218));
	}
	if (value == 4)
	{
		Color^ cl = gcnew Color();
		solidbrush = gcnew SolidBrush(cl->FromArgb(237, 224, 200));
	}
	if (value == 8)
	{
		Color^ cl = gcnew Color();
		solidbrush = gcnew SolidBrush(cl->FromArgb(242, 177, 121));
	}
	if (value == 16)
	{
		Color^ cl = gcnew Color();
		solidbrush = gcnew SolidBrush(cl->FromArgb(245, 149, 99));
	}
	if (value == 32)
	{
		Color^ cl = gcnew Color();
		solidbrush = gcnew SolidBrush(cl->FromArgb(246, 124, 95));
	}
	if (value == 64)
	{
		Color^ cl = gcnew Color();
		solidbrush = gcnew SolidBrush(cl->FromArgb(246, 94, 59));
	}
	if (value == 128)
	{
		Color^ cl = gcnew Color();
		solidbrush = gcnew SolidBrush(cl->FromArgb(237, 207, 114));
	}
	if (value == 256)
	{
		Color^ cl = gcnew Color();
		solidbrush = gcnew SolidBrush(cl->FromArgb(237, 204, 97));
	}
	if (value == 512)
	{
		Color^ cl = gcnew Color();
		solidbrush = gcnew SolidBrush(cl->FromArgb(237, 200, 80));
	}
	if (value == 1024)
	{
		Color^ cl = gcnew Color();
		solidbrush = gcnew SolidBrush(cl->FromArgb(237, 197, 63));
	}
	if (value >= 2048)
	{
		Color^ cl = gcnew Color();
		solidbrush = gcnew SolidBrush(cl->FromArgb(237, 194, 46));
	}
	return solidbrush;
}

inline System::Void CppCLR_WinformsProjekt::Form1::pictureBox1_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
{

	for (int i = 0; i < 4; i++)
	{	
		e->Graphics->FillRectangle(GenerateColor(field[0][i]), (5 + 60 * i + 5 * i), 5, 60, 60);
		if (field[0][i] != 0)
		{
			e->Graphics->DrawString(field[0][i].ToString(), gcnew System::Drawing::Font("Arial", 14), Brushes::Black, ((25 + 60 * i + 5 * i) - field[0][i].ToString()->Length), 25);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		e->Graphics->FillRectangle(GenerateColor(field[1][i]), (5 + 60 * i + 5 * i), 70, 60, 60);
		if (field[1][i] != 0)
		{
			e->Graphics->DrawString(field[1][i].ToString(), gcnew System::Drawing::Font("Arial", 14), Brushes::Black, ((25 + 60 * i + 5 * i) - field[1][i].ToString()->Length), 90);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		e->Graphics->FillRectangle(GenerateColor(field[2][i]), (5 + 60 * i + 5 * i), 135, 60, 60);
		if (field[2][i] != 0)
		{
			e->Graphics->DrawString(field[2][i].ToString(), gcnew System::Drawing::Font("Arial", 14), Brushes::Black, ((25 + 60 * i + 5 * i) - field[2][i].ToString()->Length), 155);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		e->Graphics->FillRectangle(GenerateColor(field[3][i]), (5 + 60 * i + 5 * i), 200, 60, 60);
		if (field[3][i] != 0)
		{
			e->Graphics->DrawString(field[3][i].ToString(), gcnew System::Drawing::Font("Arial", 14), Brushes::Black, ((25 + 60 * i + 5 * i) - field[3][i].ToString()->Length), 220);
		}
	}
}

inline System::Void CppCLR_WinformsProjekt::Form1::Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Down)
	{
		Drop();
	}
	if (e->KeyCode == Keys::Left)
	{
		CppCLR_WinformsProjekt::Form1::Rotate();
		CppCLR_WinformsProjekt::Form1::Rotate();
		CppCLR_WinformsProjekt::Form1::Rotate();
		Drop();
		CppCLR_WinformsProjekt::Form1::Rotate();
	}
	if (e->KeyCode == Keys::Right)
	{
		CppCLR_WinformsProjekt::Form1::Rotate();
		Drop();
		CppCLR_WinformsProjekt::Form1::Rotate();
		CppCLR_WinformsProjekt::Form1::Rotate();
		CppCLR_WinformsProjekt::Form1::Rotate();
	}
	if (e->KeyCode == Keys::Up)
	{
		CppCLR_WinformsProjekt::Form1::Rotate();
		CppCLR_WinformsProjekt::Form1::Rotate();
		Drop();
		CppCLR_WinformsProjekt::Form1::Rotate();
		CppCLR_WinformsProjekt::Form1::Rotate();
	}
	Control::Refresh();
}

inline System::Void CppCLR_WinformsProjekt::Form1::resetToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	score = 0;
	label1->Text = "0";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			field[i][j] = 0;
		}
	}
	field[0][0] = 2;
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
						score += field[posJ][posI];
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
		label1->Text = score.ToString();
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