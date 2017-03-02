// DB_lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CDatabase.h"
#include "CDatabaseError.h"

int main()
{
	try
	{
		CDatabase db("res/db.csv");
		while (!std::cin.eof())
		{
			std::cout << "Enter username: ";
			std::string userName;
			if (std::getline(std::cin, userName))
			{
				auto result = db.GetUserInfo(userName, Field::ID);
				std::cout << "Record id: ";
				std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, ", "));
				std::cout << std::endl;
			}
		}
	}
	catch (CDatabaseError const& error)
	{
		std::cout << error.what() << std::endl;
	}
    return 0;
}

