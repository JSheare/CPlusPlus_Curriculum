#ifndef STRINGVALUEPAIR_H
#define STRINGVALUEPAIR_H

#include <string>

#include "Pair.h"

template <typename V>
class StringValuePair : public Pair<std::string, V>
{
public:
	StringValuePair(std::string_view first, const V second)
		: Pair<std::string, V>{ static_cast<std::string>(first), second }
	{}
};

#endif
