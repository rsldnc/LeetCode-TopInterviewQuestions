/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
 
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *cpy_l1 = l1;
	struct ListNode *cpy_l2 = l2;
	struct ListNode *ret_list = NULL;
	struct ListNode *curr = NULL;
	int sum = 0;
	while (cpy_l1 || cpy_l2)
	{
		if (cpy_l1)
		{
			sum += cpy_l1->val;
			cpy_l1 = cpy_l1->next;
        }
		if (cpy_l2)
		{
			sum += cpy_l2->val;
			cpy_l2 = cpy_l2->next;
		}
		
		struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
		new_node->val = sum % 10;
		new_node->next = NULL;
		if (curr)
		{
			curr->next = new_node;
			curr = curr->next;
		}
		else
		{
			ret_list = new_node;
			curr = new_node;
		}
		
		sum = sum / 10;
	}
	if (sum != 0)
	{
		struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
		new_node->val = sum % 10;
		new_node->next = NULL;
		curr->next = new_node;
		curr = curr->next;
	}
	free(cpy_l1);
	free(cpy_l2);
	free(curr);
	return ret_list;
}
