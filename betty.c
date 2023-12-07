#include<shell.h>

/**
 * m_func1 - Example function 1
 */
void m_func1(void)
{
	write(STDOUT_FILENO, "Hello, world!\n", 13);
}

/**
 * m_func2 - Example function 2
 */
void m_func2(void)
{
	write(STDOUT_FILENO, "Betty-compliant code\n", 21);
}

int main(void)
{
	m_func1();
	m_func2();

	return EXIT_SUCCESS;
}

