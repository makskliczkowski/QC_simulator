﻿#include "protocol.h"
#include "BB84.h"
#include "B92.h"
#include "statistics.h"

using namespace std;

int main()
{
	buffer::init();

	
	int size = 450;
	double angle = 30;
	protocol* Alice = new B92(size, angle);
	protocol* Bob = new B92(size, angle);
	//protocol* Eve = new B92(size, angle);


	//*** First communication pattern ***//

	/*

	Alice->load_key();
	//Alice->generate_basis();

	Bob->load_key();
	Bob->generate_basis();

	//Eve->load_key();
	//Eve->generate_basis();

	cout << "Alice" << endl << *dynamic_cast<B92*>(Alice);
	cout << "Bob" << endl << *dynamic_cast<B92*>(Bob);
	//cout << "Eve" << endl << *dynamic_cast<B92*>(Eve);

	quantum_channel connection(Alice);
	connection.make_noise(50);

	//Eve->spy_quantum(&connection);
	Bob->read_quantum(&connection);

	Alice->compare(Bob);

	//Eve->spy_classic(Alice);
	Alice->key_reduction();
	Bob->key_reduction();

	cout << "Alice" << endl << *dynamic_cast<B92*>(Alice);
	cout << "Bob" << endl << *dynamic_cast<B92*>(Bob);
	//cout << "Eve" << endl << *dynamic_cast<B92*>(Eve);

	
	connection.error_estimation(Alice, Bob, 70);
	
	cout << "Alice" << endl << *dynamic_cast<B92*>(Alice);
	cout << "Bob" << endl << *dynamic_cast<B92*>(Bob);

  	connection.Cascade(Alice, Bob,0.5, 5);

  	cout << "Alice" << endl << *dynamic_cast<B92*>(Alice);
	cout << "Bob" << endl << *dynamic_cast<B92*>(Bob);

	connection.privacy_amp(Alice, Bob, 20);

	cout << "Alice" << endl << *dynamic_cast<B92*>(Alice);
	cout << "Bob" << endl << *dynamic_cast<B92*>(Bob);
	
	*/

	//*** End of the pattern ***//

	statistics STATS(Alice, Bob, 30);
	//SimulationData data = STATS.simulate_QBER_noise(Alice, Bob, 0, 60, 2);
	//data.apply(&Alice, &Bob);

	cout << *dynamic_cast<B92*>(Alice);
	cout << *dynamic_cast<B92*>(Bob);
	
	STATS.Cascade_convergence(Alice, Bob, 30, 0.2, 1, 0.05, 50, 20).apply(&Alice, &Bob);
	STATS.print_cascade_conv("data_C_convergence.txt");
	
	//STATS.simulate_QBER_angle(Alice, Bob, 5, 45, 5, 40).apply(&Alice, &Bob);
	STATS.print_stats();
	//STATS.print_charts("data_noise.txt", "data_angle.txt");

	delete Alice;
	delete Bob;
	//delete Eve;

	buffer::close();

	system("PAUSE");
	return 0;
}
