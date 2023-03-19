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

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	int len_A = countNodes(headA);
	int len_B = countNodes(headB);
	int *tab_A = listToArray(headA, len_A);
	int *tab_B = listToArray(headB, len_B);
	len_A--;
	len_B--;
	if (!(tab_A[len_A] == tab_B[len_B]))
		return NULL;
	while (len_A >= 0 && len_B >= 0 && tab_A[len_A] == tab_B[len_B])
	{
		len_A--;
		len_B--;
	}
	int i = 0;
	struct ListNode *curr_A = headA;
	while (i < len_A + 1)
	{
		curr_A = curr_A->next;
		i++;
	}
	i = 0;
	struct ListNode *curr_B = headB;
	while (i < len_B + 1)
	{
		curr_B = curr_B->next;
		i++;
	}
	free(tab_A);
	free(tab_B);
	while (!(curr_A == curr_B))
	{
		curr_A = curr_A->next;
		curr_B = curr_B->next;
	}
	return curr_A;
}
