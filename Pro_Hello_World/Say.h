#ifndef SAY_H
#define SAY_H
#include<string>

class Say
{
	private:
		std::string mess;
	public:
		Say();
		Say(std::string mess);
		void say();
};

#endif
