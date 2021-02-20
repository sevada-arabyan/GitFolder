#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <iterator>
#include <cassert>
#include <algorithm>

using std::cout;
using std::endl;

using std::vector;
using std::list;

void generateVector(vector<int>& vec, const size_t size){
	assert(size > 0);
	//size_t size{vec.size()};
	std::default_random_engine engine;
	engine.seed(1337);
	std::uniform_int_distribution<int> distro(0, 15);
	for(size_t i{0}; i < size; ++i){
		vec.push_back(distro(engine));
	}
}
void printVector(const vector<int>& vec){
	for(const auto& i : vec){
		cout << i << ' ';
	}
	cout << endl;
}
int main(){
	vector<int> vec;
	size_t size{10};
	vec.reserve(size);
//	cout << "Hello" << endl;
	generateVector(vec, size);
	printVector(vec);
	copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout," "));
	cout << endl;

}
