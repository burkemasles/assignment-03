/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Burke Masles <burkemasles@yahoo.com>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Implements `buffer.h`.
 */

// TODO: `#include`s for system headers, if necessary

#include "buffer.h"
#include <iostream>
using std::cout;
// TODO: `#include`s for other local headers, if necessary

// ----------------------------------------------------------------------------

// TODO: implementations for all functions in `class Buffer`

Buffer::Buffer(unsigned int a, unsigned int b) : size_x(a), size_y(b)
{

	data_ = new char[size_x*size_y];
}
Buffer::~Buffer()
{
	delete[] data_;
}
char Buffer::get(unsigned int x, unsigned int y) const
{
	if (size_x < x || size_y < y)
	{
		cout << "Index out of bounds";
	}
	else return data_[y * size_x + x];
}

void Buffer::set(unsigned int x, unsigned int y, char c)
{
	if (size_x < x || size_y < y)
	{
		cout << "Index out of bounds";
	}
	else data_[y * size_x + x] = c;
}
void Buffer::set(unsigned int pos_x, unsigned int pos_y, std::string s) 
{
	for (int i = 0, x = pos_x, y = pos_y; i < s.length(); i++) {
		if (s[i] == '\n') {
			y++;
			x = pos_x;
		}
		else {
			set(x++, y, s[i]);
		}
	}
}
void Buffer::draw() const 
{
	for (int i = 0; i <= (size_x*size_y); i++)
	{
		cout << data_[i];
	}
}
void Buffer::clear()
{
	for (int i = 0; i <= (size_x*size_y); i++)
	{
		data_[i] = ' ';
	}
}