#pragma once
#include "User.h"
#include <vector>
#include "json/json.hpp"

namespace Hyt
{
	//�û�������
	class UserMgr
	{
		std::vector<User> usersList;
	public: 
		UserMgr();
		static UserMgr GetUsersFromFile(std::string fileName);
		void SaveToFile(std::string fileName);
		//ע��, �û��Ѵ����򷵻�false
		bool Register(const User& newUser);
		//�����û�
		bool ExistUser(std::string name);
		//Ѱ���û�
		User& FindUser(std::string name, bool& success);
		//��¼, ��¼�ɹ��򷵻�true, userΪ��ǰ�û���ָ��
		User& Login(std::string userName, std::string pw, bool& success);
		size_t UserCount();
		friend void to_json(nlohmann::json& j, const UserMgr& mgr);
		friend void from_json(const nlohmann::json& j, UserMgr& mgr);
	};
}

