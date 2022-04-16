#pragma once
#include <iostream>

const int Array_Size = 8;

/* Узловой элемент списка */
struct Node
{
	int data = 0;
	int next_ptr = NULL;
};