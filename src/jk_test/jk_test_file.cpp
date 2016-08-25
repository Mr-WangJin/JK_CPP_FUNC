#include "jk_test_file.h"
#include "jk_file.h"
#include <stdlib.h>
#include <iostream>
#include "thread/JKThread.h"

JK_Test_File::JK_Test_File()
{
	m_pFileName = "testfile";
}

JK_Test_File::~JK_Test_File()
{

}

class A
{
public:
	A()
	{
		print();
	};
	virtual ~A(){};

public:
	virtual void print(){this->init();};

public:
	virtual void init() = 0;
};
class B : public A
{
public:
	B(){};

public:
	virtual void print(){printf("A");};

	virtual void init()
	{
		printf("ddd");
	}
};


void JK_Test_File::TestClass()
{
	//this->testWriteFile();
	//this->testReadFile();

	//this->testThread();
	B *b = new B;
	A* a = b;
	a->init();

}

void JK_Test_File::testReadFile()
{
	/* test file */
	char *buffer = NULL;
	long bufSize = 0;

	if (JK_CPP_FUNC::JK_File::ReadFile(m_pFileName, "r", buffer, bufSize) == true)
		std::cout<<"Test Read File is TRUE!"<<std::endl;
	else
		std::cout<<"Test Read File if False!"<<std::endl;
	free(buffer);
}
void JK_Test_File::testWriteFile()
{
	/* test file */
	char *buffer = "testFile";
	long bufSize = 8;

	if (JK_CPP_FUNC::JK_File::WriteFile(m_pFileName, "w+", buffer, bufSize) == true)
		std::cout<<"Test Write File is TRUE!"<<std::endl;
	else
		std::cout<<"Test Write File if False!"<<std::endl;

}
void JK_Test_File::testThread()
{
	//JKThread::testThread();
	JKThread::testMutex();
}