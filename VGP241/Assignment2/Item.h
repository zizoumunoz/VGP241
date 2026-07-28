#pragma once
#include <string>

// forward declaring enum
enum ItemType : int;


class Item
{
public:

private:
	ItemType m_type;
	std::string m_name;
	int m_value;
	int m_count;


};

