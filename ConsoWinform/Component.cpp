#include "Component.h"

const char* Component::ComponentOrderTable[] =
{
	typeid(Form).name(),
	typeid(Text).name(),
	typeid(SplitLine).name(),
	0,
}