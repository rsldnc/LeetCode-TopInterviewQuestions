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
 
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	int len = countNodes(head);
	if (len == 1)
		return NULL;
	if (len == n)
		return head->next;
	int i = 0;
	struct ListNode *curr = head;
	struct ListNode *prev = NULL;
	while (curr && i < len - n)
	{
		prev = curr;
		curr = curr->next;
		i++;
	}
	if (n == 1 && curr)
	{
		prev->next = NULL;
		return head;
	}
	prev->next = curr->next;
	return head;
}
