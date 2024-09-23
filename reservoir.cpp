#include "reservoir.h"

// Constructors
Reservoir::Reservoir() {
	Logger::debug(_get_object_as_string() + " created default");
	_lenth = 0;
	_width = 0;
	_depth = 0;
	_type = Type_of_reservior::unknown_reservior;
}

Reservoir::Reservoir(string name) : Reservoir() {
	_name = name;
}

Reservoir::Reservoir(string name, double lenth) : Reservoir(name) {
	_lenth = lenth;
}

Reservoir::Reservoir(string name, double lenth, double width) : Reservoir(name, lenth) {
	_width = width;
}

Reservoir::Reservoir(string name, double lenth, double width, double depth) : Reservoir(name, lenth, width) {
	_depth = depth;
}

Reservoir::Reservoir(string name, double lenth, double width, double depth, Type_of_reservior type) : Reservoir(name, lenth, width, depth) {
	Logger::debug(_get_object_as_string() + " created with params");
	_type = type;
}

Reservoir::Reservoir(string name, double lenth, double width, double depth, string type) : Reservoir(name, lenth, width, depth) {
	Logger::debug(_get_object_as_string() + " created with params");
	if (type == "river" || type == "River") {
		_type = Type_of_reservior::river;
	}
	else if (type == "sea" || type == "Sea") {
		_type = Type_of_reservior::sea;
	}
	else if (type == "pond" || type == "Pond") {
		_type = Type_of_reservior::pond;
	}
	else if (type == "pool" || type == "Pool") {
		_type = Type_of_reservior::pond;
	}
	else {
		_type = Type_of_reservior::unknown_reservior;
	}
}

Reservoir::Reservoir(string name, double lenth, double width, double depth, int type) : Reservoir(name, lenth, width, depth) {
	Logger::debug(_get_object_as_string() + " created with params");
	switch (type) {
	case 1:
		_type = Type_of_reservior::river;
		break;
	case 2:
		_type = Type_of_reservior::sea;
		break;
	case 3:
		_type = Type_of_reservior::pond;
		break;
	case 4:
		_type = Type_of_reservior::pool;
		break;
	default:
		_type = Type_of_reservior::unknown_reservior;
		break;
	}
}

// Copy constructor
Reservoir::Reservoir(const Reservoir& other) {
	Logger::debug(_get_object_as_string() + " created as copy of " + other._get_object_as_string());
	_name = other._name;
	_lenth = other._lenth;
	_width = other._width;
	_depth = other._depth;
	_type = other._type;
}

// Get type of reservoir
inline string Reservoir::get_type() const {
	switch (_type) {
	case Type_of_reservior::river:
		return "River";
	case Type_of_reservior::sea:
		return "Sea";
	case Type_of_reservior::pond:
		return "Pond";
	case Type_of_reservior::pool:
		return "Pool";
	case Type_of_reservior::unknown_reservior:
		return "Unknown";
	default:
		return "Unknown";
	}
}

// for logger
inline string Reservoir::_get_object_as_string() const {
	stringstream ss;
	ss << "Reservoir object <" << (void**)this << ">";
	return ss.str();
}


// Setters
void Reservoir::set_name(string name) {
	Logger::info(_get_object_as_string() + " name changed to " + name);
	_name = name;
}

void Reservoir::set_lenth(double lenth) {
	Logger::info(_get_object_as_string() + " lenth changed to " + to_string(lenth));
	_lenth = lenth;
}

void Reservoir::set_width(double width) {
	Logger::info(_get_object_as_string() + " width changed to " + to_string(width));
	_width = width;
}

void Reservoir::set_depth(double depth) {
	Logger::info(_get_object_as_string() + " depth changed to " + to_string(depth));
	_depth = depth;
}

void Reservoir::set_type(Type_of_reservior type) {
	Logger::info(_get_object_as_string() + " type changed to " + get_type());
	_type = type;
}

// Methods
inline double Reservoir::get_volume() const {
	return _lenth * _width * _depth;
}

inline double Reservoir::get_square() const {
	return _lenth * _width;
}

inline void Reservoir::is_same_type_s(const Reservoir& other) const {
	if (_type == other._type) {
		cout << _get_object_as_string() << " is same type as " << other._get_object_as_string() << endl;
	}
	else {
		cout << _get_object_as_string() << " is not same type as " << other._get_object_as_string() << endl;
	}
}

inline bool Reservoir::is_same_type(const Reservoir& other) const {
	return (_type == other._type);
}

bool Reservoir::is_same_obj(const Reservoir& other) const {
	bool is_same = (_name == other._name && _lenth == other._lenth && _width == other._width && _depth == other._depth && _type == other._type);
	return is_same;
}

inline int Reservoir::dif_square_same_type(const Reservoir& other) const {
	if (is_same_type(other)) {
		string info = _get_object_as_string() + " and " + other._get_object_as_string() + " have same types ";
		Logger::error(info);

		if (get_square() > other.get_square()) {
			return 1;
		}
		else if (get_square() < other.get_square()) {
			return -1;
		}
		else {
			return 0;
		}
	}
	else {
		string error = _get_object_as_string() + " and " + other._get_object_as_string() + " have different types ";
		Logger::error(error);
		cout << "INVALID OPERATION: " << _get_object_as_string() << " is not same type as " << other._get_object_as_string() << endl;
	}
}

inline void Reservoir::print_dif_square_same_type(const Reservoir& other) const {
	int result = dif_square_same_type(other);
	if (result == 1) {
		cout << _get_object_as_string() << " have bigger square than " << other._get_object_as_string() << endl;
	}
	else if (result == -1) {
		cout << _get_object_as_string() << " have smaller square than " << other._get_object_as_string() << endl;
	}
	else if (result == 0) {
		cout << _get_object_as_string() << " have same square as " << other._get_object_as_string() << endl;
	}
}

// Print reservoir information
void Reservoir::print_info() const {
	cout << "Reservoir name: " << _name << endl;
	cout << "Reservoir lenth: " << _lenth << endl;
	cout << "Reservoir width: " << _width << endl;
	cout << "Reservoir depth: " << _depth << endl;
	cout << "Reservoir type: " << get_type() << endl;
	cout << "Reservoir volume: " << get_volume() << endl;
	cout << "Reservoir square: " << get_square() << endl;
}
