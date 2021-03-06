#include "Logger.h"

Logger::Logger() :
	output_stream(&std::cerr, [](std::ostream*) {})
{ }

Logger::Logger(std::string file) :
	output_stream(std::make_shared<std::ofstream>(file))
{
	//Show current working directory
	//Probably a much better way to do this...
	system("pwd");
}
