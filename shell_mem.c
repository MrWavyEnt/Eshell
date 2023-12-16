#include "main.h"

/**
 * _realloc -  reallocates a memory block using malloc and free
 *@pt: pointer
 *@old_p: previous Size Of The Pointer
 *@new_p: new size of the pointer
 *Return: Pointer to reallocated memory
 */
void *_realloc(void *pt, unsigned int old_s, unsigned int new_s)
{
	void *end;

	if (new_s == old_s)
		return (pt);
	if (new_s == 0 && pt)
	{
		free(pt);
		return (NULL);
	}
	end = malloc(new_s);
	if (end == NULL)
	{
		free(end);
		return (NULL);
	}
	if (pt == NULL)
	{
		fill_an_array(end, '\0', new_s);
		free(pt);
	}
	else
	{
		_memcpy(end, pt, old_s);
		free(pt);
	}
	return (end);
}

/**
 * free_all - free memory allocated
 * @bltcmd: array pointer
 * @charpt: char pointer
 * Return: Void
 */
void free_all(char **bltcmd, char *charpt)
{
	free(bltcmd);
	free(charpt);
	bltcmd = NULL;
	charpt = NULL;
}

/**
 * _memcpy - copy bytes of memory from source to destination
 *@destint: destination pointer
 *@srcptr: source pointer
 *@n: size to be copied
 *Return: pointer to destination
 */
char *_memcpy(char *destint, char *srcptr, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		destint[i] = srcptr[i];
	}
	return (destint);
}

/**
 * fill_an_array - fill an array by constant byte
 *@vpt: void pointer
 *@el: int to be used
 *@inlen: length for int
 *Return: void pointer
 */
void *fill_an_array(void *vpt, int el, unsigned int inlen)
{
	char *p = vpt;
	unsigned int abc = 0;

	while (abc < inlen)
	{
		*p = el;
		p++;
		abc++;
	}
	return (vpt);
}

/**
 * _calloc - allocates memory for an array using malloc
 *@size: size
 *Return: void pointer
 */
void *_calloc(unsigned int s)
{
	char *abc;
	unsigned int in;

	if (s == 0)
		return (NULL);
	abc = malloc(s);
	if (abc == NULL)
		return (NULL);
	for (in = 0; in < s ; in++)
	{
		abc[in] = '\0';
	}
	return (abc);
}

