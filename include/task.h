#pragma once

#include <string>


class Task {
private:
	int id;
	std::string description;
	std::string status;
	std::string createdAt;
	std::string updatedAt;
};