#pragma once

#include <fstream>
#include <string>

using namespace std;

class buffer {
private:
	static fstream data;
	static fstream temp_file;
	static const char file_name[];
	static const int bit_size;
	static long max_rand;
public:
	static void init();
	static bool randomize();
	static double rand_1();
	static void close();
};