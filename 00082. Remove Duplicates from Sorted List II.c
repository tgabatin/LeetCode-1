
//Accepted	8 ms	cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next) return head;
        ListNode *tmp = head;
        
        int count = 1;
        int val = head->val;
        bool flag = false;
        while (tmp->next) {
            if(tmp->next->val == val) count++;
            else{
                if(count == 1) {
                    head = tmp;
                    flag = true;
                    break;
                }
                else{
                    count = 1;
                    val = tmp->next->val;
                }
            }
            tmp = tmp->next;
        }
        if(count == 1) head = tmp,flag = true;
        if(!flag) return NULL;
        
        ListNode *fir = head->next;
        ListNode *sec = NULL;
        if(fir && fir->next) sec = fir->next;
        val = head->val;
        
        tmp->next = NULL;
        
        while(fir && sec){
            if(fir->val != val && fir->val != sec->val){
                tmp->next = new ListNode(fir->val);
                tmp = tmp->next;
            }
            
            val = fir->val;
            fir = sec;
            sec = fir->next;
        }
        
        if(fir && fir->val != val){
            tmp->next = fir;
        }
        
        return head;
    }
};

