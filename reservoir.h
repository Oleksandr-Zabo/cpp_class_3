#ifndef RESERVOIR_H
#define RESERVOIR_H

#include "consts.h"

#include "logger.h"

class Reservoir {
private:
	string _name;
	double _lenth;
	double _width;
	double _depth;
	Type_of_reservior _type;

	string _get_object_as_string() const;

public:
	explicit Reservoir();
	explicit Reservoir(string name, double lenth, double width, double depth, Type_of_reservior type);
};

#endif // !RESERVOIR_H


