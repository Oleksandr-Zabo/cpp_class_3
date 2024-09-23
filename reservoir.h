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

	//for logger
	inline string _get_object_as_string() const;

public:

	//constructors
	Reservoir();
	Reservoir(string name);
	Reservoir(string name, double lenth);
	Reservoir(string name, double lenth, double width);
	Reservoir(string name, double lenth, double width, double depth);
	Reservoir(string name, double lenth, double width, double depth, Type_of_reservior type);

	//for incorrect input type
	Reservoir(string name, double lenth, double width, double depth, string type);
	Reservoir(string name, double lenth, double width, double depth, int type);
	//copy constructor
	Reservoir(const Reservoir& other);

	//get type of reservoir
	inline string get_type() const;

	//setters

	void set_name(string name);
	void set_lenth(double lenth);
	void set_width(double width);
	void set_depth(double depth);
	void set_type(Type_of_reservior type);

	//methods
	inline double get_volume() const;
	inline double get_square() const;

	inline void is_same_type_s(const Reservoir& other) const;
	inline bool is_same_type(const Reservoir& other) const;
	bool is_same_obj(const Reservoir& other) const;

	inline int dif_square_same_type(const Reservoir& other) const;
	inline void print_dif_square_same_type(const Reservoir& other) const;

	//print reservoir information
	void print_info() const;

};

#endif // !RESERVOIR_H


