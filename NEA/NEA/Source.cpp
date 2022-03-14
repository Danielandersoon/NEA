#include <stdexcept>
#include <iostream>
#include "Application.h"

int main()
{
	try
	{
		Application app;
		app.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\n\nEXCEPTION:" << e.what() << std::endl;
	}
}