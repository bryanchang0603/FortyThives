#ifndef A3_STACK_H_
#define A3_STACK_H_
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

template<class CardT>
class Stack {
private:
	int temp;
	std::vector<CardT> stackList;

public:
	Stack(CardT s[]);
	std::vector<CardT> push(CardT e);
	std::vector<CardT> pop();
	CardT top();
	int size();
	CardT * toSeq();

};
#endif
