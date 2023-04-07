/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
	if (list2 == NULL)
		return list1;
	else if (list1 == NULL)
		return list2;
	if (list1->val <= list2->val)
	{
		list1->next = mergeTwoLists(list1->next, list2);
		return list1;
	}
	else
	{
		list2->next = mergeTwoLists(list1, list2->next);
		return list2;
	}
}
 
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
	struct ListNode *ret_list = NULL;
	if (listsSize == 0)
		return ret_list;
	else if (listsSize == 1)
	{
		ret_list = lists[0];
		return ret_list;
	}
	else
	{
		int i = 1;
		ret_list = lists[0];
		while (i < listsSize)
		{
			ret_list = mergeTwoLists(ret_list, lists[i]);
			i++;
		}
		return ret_list;
	}
}
