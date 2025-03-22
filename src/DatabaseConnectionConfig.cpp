#include "../include/DatabaseConnectionConfig.h"


std::string DatabaseConnectionConfig::getConnectionString() const {
	return "dbname=" + _dbname + " user=" + _user + " password="+ _password +
		   " hostaddr=" + _hostaddr + " port=" + _port +
		   " connect_timeout="+ _connect_timeout;
}
