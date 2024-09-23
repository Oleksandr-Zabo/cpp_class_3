#include "res_obs.h"

//constructors
Reservoir_obs::Reservoir_obs() {
	_size = new size_t{ ProjectConsts::empty_size };
	_allocated_memory = new size_t{ ProjectConsts::default_allocated_memory };
	_reservoirs = new Reservoir[*_allocated_memory];

	Logger::debug(_get_object_as_string() + " created with default allocated memory");
}
Reservoir_obs::Reservoir_obs(size_t allocated_memory)
{
	_size = new size_t{ ProjectConsts::empty_size };
	_allocated_memory = new size_t{ allocated_memory };
	_reservoirs = new Reservoir[*_allocated_memory];
	Logger::debug(_get_object_as_string() + " with custom allocated memory");
}
Reservoir_obs::Reservoir_obs(size_t* allocated_memory) : Reservoir_obs(*allocated_memory)
{}

//Methods
void Reservoir_obs::allocate_new_memory()
{
	Reservoir* new_reserviors = new Reservoir[(*_allocated_memory) * 2];
	for (size_t i = 0; i < *_size; i++)
	{
		new_reserviors[i] = _reservoirs[i];
	}
	Logger::warning("Copying old memory queue to new memory queue");
	delete[] _reservoirs;
	_reservoirs = new_reserviors;
	*_allocated_memory *= 2;
	Logger::info("New memory allocated");
}

inline void Reservoir_obs::analyze_memory()
{
	Logger::info("Analyzing memory");
	if (*_size == *_allocated_memory)
	{
		Logger::warning("Memory is full, allocating new memory");
		allocate_new_memory();
	}
}

void Reservoir_obs::push(Reservoir reservoir)
{
	Logger::info("Pushing new reservoir");
	analyze_memory();
	_reservoirs[*_size] = reservoir;
	(*_size)++;
	Logger::info("Reservoir pushed");
}

void Reservoir_obs::push(Reservoir* reservoir)
{
	Logger::info("Pushing new reservoir");
	analyze_memory();
	_reservoirs[*_size] = *reservoir;
	(*_size)++;
}

void Reservoir_obs::push_by_index(Reservoir reservoir, size_t index)
{
	Logger::info("Pushing new reservoir by index");
	if (index >= *_size)
	{
		Logger::error("Index out of range");
		return;
	}
	analyze_memory();
	for (size_t i = *_size; i > index; i--)
	{
		_reservoirs[i] = _reservoirs[i - 1];
	}
	_reservoirs[index] = reservoir;
	(*_size)++;
}

void Reservoir_obs::push_by_index(Reservoir* reservoir, size_t index)
{
	Logger::info("Pushing new reservoir by index");
	if (index >= *_size)
	{
		Logger::error("Index out of range");
		return;
	}
	analyze_memory();
	for (size_t i = *_size; i > index; i--)
	{
		_reservoirs[i] = _reservoirs[i - 1];
	}
	_reservoirs[index] = *reservoir;
	(*_size)++;
}

void Reservoir_obs::print_all() const
{
	Logger::info("Printing all reservoirs");
	for (size_t i = 0; i < *_size; i++)
	{
		cout << "Reservoir #" << i + 1 << endl;
		_reservoirs[i].print_info();
		cout << endl;
	}
}

void Reservoir_obs::del_by_index(size_t index)
{
	Logger::info("Deleting reservoir by index");
	if (index >= *_size)
	{
		Logger::error("Index out of range");
		return;
	}
	for (size_t i = index; i < *_size - 1; i++)
	{
		_reservoirs[i] = _reservoirs[i + 1];
	}
	(*_size)--;
	Logger::error("Reservoir deleted");
}

void Reservoir_obs::del_by_item(Reservoir reservoir)
{
	Logger::info("Deleting reservoir by item");
	for (size_t i = 0; i < *_size; i++)
	{
		if (_reservoirs[i].is_same_obj(reservoir))
		{
			del_by_index(i);
			Logger::error("Reservoir deleted");
			return;
		}
	}
	Logger::error("Reservoir not found");
}

void Reservoir_obs::del_by_item(Reservoir* reservoir)
{
	Logger::info("Deleting reservoir by item");
	for (size_t i = 0; i < *_size; i++)
	{
		if (_reservoirs[i].is_same_obj(*reservoir))
		{
			del_by_index(i);
			Logger::error("Reservoir deleted");
			return;
		}
	}
	Logger::error("Reservoir not found");
}

//destructor
Reservoir_obs::~Reservoir_obs()
{
	Logger::error("Size deleted");
	delete _size;
	Logger::error("Allocated_memory deleted");
	delete _allocated_memory;
	Logger::error(_get_object_as_string() + " destroyed");
	delete[] _reservoirs;
	
}

//for logger
inline string Reservoir_obs::_get_object_as_string() const
{
	stringstream ss;
	ss << "Reservoir object <" << (void**)this << ">";
	return ss.str();
}