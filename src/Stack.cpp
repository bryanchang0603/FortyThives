// Implementation here
#include <CardTypes.h>
#include "Stack.h"

template <class CardT>
std::vector<CardT> Stack<CardT>::Stack(CardT s[]){
	this->stackList = s;
	return this->stackList;
}

template<class CardT>
std::vector<CardT> Stack<CardT>::push(CardT e){
	this->stackList.push_back(e);
	return this->stackList;
}

template<class CardT>
std::vector<CardT> Stack<CardT>::pop(){
	if(this->stackList.size() == 0)
		throw std::invalid_argument("empty stack");
	else{
		this->stackList.pop_back();
		return this->stackList;
	}
}

template<class CardT>
CardT Stack<CardT>::top(){
	if(this->stackList.size() == 0)
		throw std::invalid_argument("empty stack");
	else{
		return this->stackList.back();
	}
}

template<class CardT>
int Stack<CardT>::size(){
	return this->stackList.size();
}

template<class CardT>
CardT * Stack<CardT>::toSeq(){
	CardT * arrayStack = &this->stackList[0];
	return arrayStack;
}

// Keep this at bottom
template class Stack<CardT>;

