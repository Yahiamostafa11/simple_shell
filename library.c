#include "shell.h"
/**
 * real_loc - real_loc memory
 * @ptr: pointer
 * @old_size: size viejo
 * @new_size: tamanio nuev
 * Return: pointer
 */
void *real_loc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *a;

	if (ptr == NULL)
	{
		a = malloc(new_size);
		if (a == NULL)
			return (NULL);
		return (a);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	a = malloc(new_size);
	if (a == NULL)
	{
		free(ptr);
		exit(0);
	}
	if (new_size > old_size)
		memcp(a, ptr, old_size);
	else
		memcp(a, ptr, new_size);
	free(ptr);
	return (a);
}
/**
 * memcp - memcp
 * @dest: dest
 * @src: src
 * @n: ene
 */
void memcp(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}
}

