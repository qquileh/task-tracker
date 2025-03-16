#pragma once

#include <string>


class DatabaseConnectionConfig {
private:
	std::string _dbname = "task-tracker";
	std::string _user = "postgres";
	std::string _password = "1111";
	std::string _hostaddr = "127.0.0.1";
	std::string _port = "5432";

public:
	std::string getConnectionString() const;
};
