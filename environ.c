#include "main.h"
/**
*_myenv - prints the current env
*@info: parameter
*Return: void
*/
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
*_getenv - gets the current env
*@info: parameter
*@name: the name of the env
*Return: void
*/
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *v;

	while (node)
	{
		if (v && *v)
			return (v);
		node = node->next;
		v = starts_with(node->str, name);
	}
	return (NULL);
}

/**
*_mysetenv - creates a new environment variable or modify an existing
*@info: contains potential args
*Return: 0
*/
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
*_myunsetenv - removes an environ var
*@info: contains potential args
*Return: 0
*/
int _myunsetenv(info_t *info)
{
	int n;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (n = 1; n <= info->argc; n++)
		_unsetenv(info, info->argv[n]);
	return (0);
}

/**
*populate_env_list - populates a list
*@info: contains potential arguments
*Return: 0
*/
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t v;

	for (v = 0; environ[v]; v++)
		add_node_end(&node, environ[v], 0);
	info->env = node;
	return (0);
}
