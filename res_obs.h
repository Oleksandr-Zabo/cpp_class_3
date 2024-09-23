#include "reservoir.h"

#ifndef	RESERVOIR_OBS
#define RESERVOIR_OBS

class Reservoir_obs {
private:
	//Fields
	Reservoir* _reservoirs = nullptr;
	size_t* _size;
	size_t* _allocated_memory;

	//for logger
	inline string _get_object_as_string() const;

public:
	//constructor
	Reservoir_obs();
	Reservoir_obs(size_t allocated_memory);
	//The explicit keyword is not allowed for constructors that take a single argument of a non-class type.
	Reservoir_obs(size_t* allocated_memory);

	//Methods
	void allocate_new_memory();
	inline void analyze_memory();
	void push(Reservoir reservoir);
	void push(Reservoir* reservoir);
	void push_by_index(Reservoir reservoir, size_t index);
	void push_by_index(Reservoir* reservoir, size_t index);
	void del_by_index(size_t index);
	void del_by_item(Reservoir reservoir);
	void del_by_item(Reservoir* reservoir);
	void print_all() const;

	//destructor
	~Reservoir_obs();
	
};
#endif // !RESERVOIR_OBS

