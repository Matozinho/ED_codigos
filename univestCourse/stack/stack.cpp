#include <iostream>
#include "stack.h"

using namespace std;

template <typename T>
Stack<T>::Stack()
{
  this->top = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
  Node *aux;

  while (this->top != nullptr)
  {
    aux = this->top;
    this->top = this->top->next;
    delete aux;
  }
}

template <typename T>
bool Stack<T>::isEmpty() const
{
  return (top == nullptr);
}

template <typename T>
bool Stack<T>::isFull() const
{
  Node *aux;
  try
  {
    aux = new Node;
    delete aux;
    return false;
  }
  catch (std::bad_alloc exception)
  {
    return true;
  }
}

template <typename T>
void Stack<T>::push(T item)
{
  if (!this->isFull())
  {
    Node *aux = new Node;
    aux->info = item;
    aux->next = this->top;
    this->top = aux;
  }
  else
  {
    throw "Stack is already full!";
  }
}

template <typename T>
T Stack<T>::pop()
{
  if (!this->isEmpty())
  {
    Node *temp = this->top;
    T info = this->top->info;
    this->top = this->top->next;
    delete temp;
    return info;
  }
  else
  {
    throw "stack is Empty";
  }
}

template <typename T>
void Stack<T>::print() const
{
  Node *currentNode = this->top;

  cout << "top -> ";
  while (currentNode != nullptr)
  {
    cout << currentNode->info << " ";
    currentNode = currentNode->next;
  }
  cout << " <- bottom" << endl;
}