﻿#include "QueryFlow.h"
#include <iostream>							//cout, cin
#include <string>							//string
#include "ColorfulConsole/CloEscString.h"	//ces
#include "ConAPIProx/AttrBrash.h"			//SetRectColor
#include "ConAPIProx/Rect.h"
#include "ConAPIProx/Positioner.h"			
#include "ColorfulConsole/GlobalEnvironment.h"
#include "ConAPIProx/GetKey.h"

using std::cin;
using std::cout;
using ColorfulConsole::ces;

namespace Hyt
{
	bool QueryFlow::YesNoQuery(const string& queryWord, const bool& useCES)
	{
		using namespace ConAPIProx;
		using GloEnv = ColorfulConsole::GlobalEnvironment;
		using TAttr = ColorfulConsole::TextAttribute::WarpedTextAttr;
		using ColorfulConsole::Color;
		
		Position begin = Positioner::GetCursorPosition();
		Position current = begin;
		if (useCES) cout << ces << queryWord; else cout << queryWord;
		//char temp;
		
		cout << "\n";
		current = Positioner::GetCursorPosition();
		cout << "确认|取消\n";
		Rect leftZone(current, current + Position{ 3,0 });
		Rect rightZone(current + Position{ 5,0 }, current + Position{ 8,0 });
		AttrBrash::SetRectForeColor(leftZone, Color(1));
		AttrBrash::SetRectForeColor(rightZone, Color(8));
		bool yes = true;
		//按键判断
		bool getAction = false;
		while (!getAction)
		{
			switch (ConAPIProx::GetKey())
			{
			case ConAPIProx::LeftArrow:
				AttrBrash::SetRectForeColor(leftZone, Color(1));
				AttrBrash::SetRectForeColor(rightZone, Color(8));
				yes = true; break;
			case ConAPIProx::RightArrow:
				AttrBrash::SetRectForeColor(leftZone, Color(8));
				AttrBrash::SetRectForeColor(rightZone, Color(1));
				yes = false; break;
			case ConAPIProx::Esc:
				yes = false; getAction = true; break;
			case ConAPIProx::Enter:
				getAction = true; break;
			default:
				break;
			}
		}
		return yes;
		//cin >> temp;
		//if (cin.bad() || cin.eof() || cin.fail())
		//{
		//	//清除输入并返回false
		//	cin.clear();
		//	return false;
		//}
		//return temp == 'Y' || temp == 'y';
	}

	bool QueryFlow::IfContinue(const string& queryWord)
	{
		return YesNoQuery(queryWord, true);
	}
	int QueryFlow::SaveInput_int(const std::string& queryWord, const std::string& failWord, const bool& useCES)
	{
		return BasicTypeInput<int>(queryWord,failWord,useCES);
	}
	float QueryFlow::SaveInput_float(const std::string& queryWord, const std::string& failWord, const bool& useCES)
	{
		return BasicTypeInput<float>(queryWord, failWord, useCES);
	}
	double QueryFlow::SaveInput_double(const std::string& queryWord, const std::string& failWord, const bool& useCES)
	{
		return BasicTypeInput<double>(queryWord, failWord, useCES);
	}
}