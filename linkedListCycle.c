/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int is_cycle(struct ListNode *head, struct ListNode *node, int *tab, int num, int len)
{
	int i = 0;
	struct ListNode *curr = head;
	while (i < len)
	{
		if (tab[i] == num && curr->next == node->next)
			return 1;
		curr = curr->next;
		i++;
	}
	return 0;
}

bool hasCycle(struct ListNode *head)
{
	int tab[10000];
	if (!(head && head->next))
		return false;
	struct ListNode *curr = head;
	tab[0] = curr->val;
	curr = curr->next;
	int i = 1;
	while (curr)
	{
		if (is_cycle(head, curr, tab, curr->val, i))
			return true;
		tab[i] = curr->val;
		curr = curr->next;
		i++;
	}
	return false;
}
