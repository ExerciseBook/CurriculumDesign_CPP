#pragma once
#include "User.h"
#include "UserMgr.h"

namespace Hyt
{

	//�û�����
	class UserOper
	{
	public:
		/*
		��¼��ע��
		currentUser: ���ڱ��浱ǰ�û���ָ�������
		*/
		static void LoginOrRegister(UserMgr& mgr, User*& currentUser, bool& success);
		static bool LoginOrRegister(UserMgr& mgr, User*& currentUser);
	};
}

