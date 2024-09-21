#include "reservoir.h"

explicit Reservoir::Reservoir()
{
	Logger::debug(_get_object_as_string() + " created default");
	_lenth = 0;
	_width = 0;
	_depth = 0;
	_type = Type_of_reservior::unknown_reservior;
}

explicit Reservoir::Reservoir(string name, double lenth, double width, double depth, Type_of_reservior type)
{
	Logger::debug(_get_object_as_string() + " created with params");
	_name = name;
	_lenth = lenth;
	_width = width;
	_depth = depth;
	_type = type;
}

string Reservoir::_get_object_as_string() const
{
	stringstream ss;
	ss << "Reservoir object <" << (void**)this << ">";
	return ss.str();
}