//Rotate List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getSize(ListNode* head){
        int size=0;
        while(head!=NULL)
            {
                head=head->next;
                size++;
            }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int size = getSize(head);
        if(size==0) return head;
        k=k%size;
        if(k==0) return head;
        ListNode* curr=head;
        ListNode* newhead;
        for(int i=0;i<size-k-1;i++)//point to new last node
            curr=curr->next;
        newhead=curr->next;
        curr->next=NULL;
        curr=newhead;
        for(int i=0;i<k-1;i++)
            curr=curr->next;
        curr->next=head;
        return newhead;
    }
};