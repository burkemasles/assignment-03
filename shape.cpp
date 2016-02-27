/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 YOUR_NAME <YOUR_EMAIL>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Implements `shape.h`.
 */

// TODO: `#include`s for system headers, if necessary

#include "shape.h"
#include <iostream>
#include <string>
using std::cout;
using std::string;
// TODO: `#include`s for other local headers, if necessary

// ----------------------------------------------------------------------------

// TODO: implementations for all functions in `class Buffer`

Shape::Shape(const std::string & type)
{
	setType(type);
}

Shape::~Shape() = default;

std::string Shape::getType()
{
	return type_;
}

void Shape::setType(const std::string & type)
 {
	 type_ = type;
	 if (type_ == "empty")
	 {
		 type_art_ = "     \n     \n     \n";
	 }
	 else if (type_ == "triangle")
	 {
		 type_art_ = "  ,  \n / \\ \n/___\\n";
	 }
	 else if (type_ == "square")
	 {
		 type_art_ = ".---.\n|   |\n'---'\n";
	 }
	 else cout << "Invalid Type";
 }

void Shape::drawToBuffer(Buffer & b, unsigned int x, unsigned int y) const
{
	b.set(x, y, type_art_);
}

bool Shape::isHappy(const Neighborhood & n, unsigned int x, unsigned int y) const
{
	return true;
}
