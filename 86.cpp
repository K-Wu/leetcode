//86.Partition List

#define NULL 0
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
ListNode* partition(ListNode* head, int x) {
	ListNode* lesser_head=NULL;
	ListNode* curr_lesser = NULL;
	ListNode* greater_head=NULL;
	ListNode* curr_greater = NULL;
	ListNode* ptr = head;
	while( ptr != NULL) {
		ListNode* next = ptr->next;
		if (ptr->val < x) {
			if (!lesser_head) {
				lesser_head = ptr;
				curr_lesser = ptr;
			}
			else {
				curr_lesser->next = ptr;
				curr_lesser = curr_lesser->next;
			}
		}
		else {
			if (!greater_head) {
				greater_head = ptr;
				curr_greater = ptr;
			}
			else {
				curr_greater->next = ptr;
				curr_greater = curr_greater->next;
			}
		}
		ptr = next;
	}
	if (curr_greater)
		curr_greater->next = NULL;//可能产生循环链表
	if (curr_lesser)
	{
		curr_lesser->next = greater_head;//边角条件：Line 41: member access within null pointer of type 'struct ListNode'
		return lesser_head;
	}
	else
		return greater_head;	 //边角测例失败[0] 1 lesser_head==NULL,greater_head!=NULL
	}
int main() {
	ListNode* head = new ListNode(2);
	head->next = new ListNode(1);
	ListNode* node = partition(head, 2);
	return 0;
}