#pragma once

#include <string>


class Task {
private:
	int _id;
	std::string _description;
	std::string _status;
	std::string _createdAt;
	std::string _updatedAt;
};