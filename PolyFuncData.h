#pragma once

//#include <iostream>			//istream, ostream
#include <vector>
#include "json/json.hpp"	//json

using uint = unsigned int;
using nlohmann::json;

namespace Hyt
{
	//Polynomial function data����ʽ��������
	class PolyFuncData
	{
	private:
		//x��Сֵ
		double xmin;
		//x���ֵ
		double xmax;
		//�����б�
		std::vector<double> argsList;
		//��ϲ����б�
		std::vector<double> fitArgsList;
		//ƫ�������
		double rms;
	public:
		PolyFuncData(const double& xmin = 0, const double& xmax = 1, uint count = 1);
		PolyFuncData(const std::vector<double>& argsList, const double& xmin = 0, const double& xmax = 1);
		//���ݶ���ʽ��ȡһ��ֵ
		double GetValue(double x);
		//���ݶ���ʽ�ڶ�������ȡһ��ֵ, �����򷵻�NaN
		double GetValue_s(double x, bool& inRange);
		//���û����н���, ��������
		void Input(const bool& useOutput = false);
		//������ݵ�cout
		void Output();
		friend void to_json(json& j, const PolyFuncData& data);
		friend void from_json(const json& j, PolyFuncData& data);
	};
	void to_json(json& j, const PolyFuncData& data);
	void from_json(const json& j, PolyFuncData& data);
	//�������ʽ�����ĺ���ֵ
	double GetPolyFuncValue(double x, std::vector<double> argList, int startTerm = 0);
}
