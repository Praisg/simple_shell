#include "mainshell.h"

sept_lst *add_sep_node_end(sept_lst **head, char sep)
{
	sept_lst *new, *temp;

	new = malloc(sizeof(sept_lst));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}


void free_sep_list(sept_lst **head)
{
	sept_lst *temp;
	sept_lst *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}


link_list *add_line_node_end(link_list **head, char *line)
{
	link_list *new, *temp;

	new = malloc(sizeof(link_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}


void free_line_list(link_list **head)
{
	link_list *temp;
	link_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

rx_var *add_rvar_node(rx_var **head, int lvar, char *val, int lval)
{
	rx_var *new, *temp;

	new = malloc(sizeof(rx_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}


void free_rvar_list(rx_var **head)
{
	rx_var *temp;
	rx_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

