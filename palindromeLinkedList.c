/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int countNodes(struct ListNode *head)
{
	int length = 0;
	struct ListNode *current = head;
	while (current)
	{
		length++;
		current = current->next;
	}
	return length;
}

#include <stdlib.h>

int *listToArray(struct ListNode *head, int length)
{
	int *array = (int *)malloc(length * sizeof(int));
	struct ListNode *current = head;
	int i = 0;
	while (current && i < length)
	{
		array[i] = current->val;
		current = current->next;
		i++;
	}
	return array;
}

bool isPalindrome(struct ListNode *head)
{
	int len = countNodes(head);
	int *tab = listToArray(head, len);
	int i = 0;
	len--;
	while (i < len)
	{
		if (tab[i] == tab[len])
		{
			i++;
			len--;
		}
		else
			return false;
	}
	free(tab);
	return true;
}
