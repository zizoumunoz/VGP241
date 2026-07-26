#pragma once

// Gives accessibility to iterator functions
// can be tied into and used with std::sorting functions (std::sort, priorityqueue...)
// Iterate over containers instead of indexing through them

#include <algorithm>
#include <iterator>
#include <cstddef>

template <typename T>

class ContainerIterator
{
public:
	// define ids/names for stl use (std::sort, std::find, std::find_if)
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using pointer = T*;
	using reference = T&;
};
