#pragma once
#include <string>
class KeyItem
{
public:
	/// <summary>
	/// Increases item count by amount
	/// </summary>
	void add(int amount);
	/// <summary>
	/// Decreases item count by amount
	/// </summary>
	void consume(int amount);
	/// <summary>
	/// Returns the count
	/// </summary>
	/// <returns></returns>
	int getCount();
	/// <summary>
	/// Will print "m_name: m_count"
	/// </summary>
	void print();

private:
	std::string m_name;
	int m_count;

};

