#pragma once
#include <string>					//string
#include "json/json.hpp"
#include "ColorfulConsole/Color.h"

using std::string;
using namespace nlohmann;
using namespace ColorfulConsole;

namespace Hyt
{
	namespace Configration
	{
		class Config
		{
		public:
			//����ɫ
			Color bgColor;
			//ǰ��ɫ
			Color fgColor;
			//��ʼ��
			void Init();
			//���浽·����
			void Save(string fullPath);
			static Config GetConfig(string fullPath);
		};
		void from_json(const json& j, Config& cfg);
		void to_json(json& j, const Config& cfg);
	}
}

