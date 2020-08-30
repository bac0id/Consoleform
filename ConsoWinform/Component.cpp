#include "Component.h"

const char* Control::ControlsOrderTable[] =
{
	typeid(Form).name(),
	typeid(Text).name(),
	typeid(SplitLine).name(),
	0,
}