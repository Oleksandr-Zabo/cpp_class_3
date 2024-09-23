#include "res_obs.h"

bool Logger::is_print_logs = true;

int main()
{
	Reservoir r1("River", 10.0, 100.0, 5.0, "river");
	Reservoir r2("Sea", 100.0, 100.0, 100.0, "sea");
	Reservoir r3 = r1;
	r3.set_name("Pond");
	r3.set_type(Type_of_reservior::pond);

	Reservoir_obs robs;
	robs.push(r1);
	robs.push(r2);
	robs.push(r3);

	robs.print_all();

	Reservoir r4 = r2;
	r4.set_name("Pool");
	r4.set_type(Type_of_reservior::pool);
	r4.set_depth(1.5);

	robs.push_by_index(r4, 1);

	robs.print_all();

	robs.del_by_item(r4);
	robs.print_all();

	system("pause");
	cout << "The end" << endl;
	return 0;
}