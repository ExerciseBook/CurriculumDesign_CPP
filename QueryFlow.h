#pragma once
#include <iostream>
#include <string>							//string
using std::cin;
using std::cout;
using std::string;

namespace Hyt 
{
	//����ѯ����
	class QueryFlow
	{
	public:
		//ֻ�ûش��ǻ��
		static bool YesNoQuery(const string& queryWord, const bool& useCES = true);
		static bool IfContinue(const string& queryWord = "�Ƿ����?&8(���������, �س�ȷ��)");
	};
}

