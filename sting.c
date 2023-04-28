#include "mainshell.h"

char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}

int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}


int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}


int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}


char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; 
		i = _strlen(str);
		str_end = &str[i]; 
	}
	str_start = splitted;
	if (str_start == str_end) 
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) 
			bool = 1;
	}
	if (bool == 0) 
		return (NULL);
	return (str_start);
}


int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
void rev_string(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
