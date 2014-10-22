#include "stats.hpp" 
 
using namespace std;
 
float mean(vector<float> list)
{
	if(list.size()==0) {
		return 0; }

	return sum(list)/list.size();
}

float sum(vector<float> list)
{
	float total(0);
		
	for(std::vector<float>::size_type i = 0; i != list.size(); i++) {
		total += list[i]; }
		
	return total;
}

float variance(vector<float> list) 
{
	float s(0);
	
	float m = mean(list);
	
	for(std::vector<float>::size_type i = 0; i != list.size(); i++) {
		s += pow(list[i] - m , 2); }
	
	return s/list.size();	
}

float standardDeviation(vector<float> list) //ecart-type
{
	return sqrt(variance(list));
}
