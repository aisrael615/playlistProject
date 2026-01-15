#include"node.h"
#include"playlist.h"
#include"playback.h"
#include"utils.h"
#include"sort.h"
#include<strings.h>



Node *merge_sort_recur(Node *head, int (*cmp)(const Song*, const Song*)){
    Node *right_head = NULL;

    if(!head || !(head->next)){
        return head;
    }

    right_head = split_list(head);

    Node *left_sorted = merge_sort_recur(head, cmp);
    Node *right_sorted = merge_sort_recur(right_head, cmp);

   return merge_lists(left_sorted, right_sorted, cmp);
}


Node *split_list(Node *head){
    Node* prev = NULL;
    Node *fast = head;
    Node *slow = head;
    
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) prev->next = NULL; // cut the list

    if (slow) slow->prev = NULL;

    return slow; // head of right half
}

Node *merge_lists(Node *left_sorted, Node *right_sorted, int (*cmp)(const Song*, const Song*)){
    Node *head = NULL;
    Node *cur = NULL;
    Node *cur_left =  left_sorted;
    Node *cur_right = right_sorted;

    while(cur_left && cur_right){
        if (cmp(&(cur_left->song), &(cur_right->song)) <= 0){
            if (!head){
                head = cur_left;
                cur = head;
            }
            else{

                cur->next = cur_left;
                cur_left->prev = cur;
                cur = cur->next;
            }
            cur_left = cur_left -> next;
        }
        else{
            if (!head){
                head = cur_right;
                cur = head;
            }
            else{
                cur->next = cur_right;
                cur_right->prev = cur;
                cur = cur->next;

            }
            cur_right = cur_right -> next;
        }
        
    }
    
    if (cur_left){
        if (!cur){
            return cur_left;
        }
        cur->next = cur_left;
    }
    else if(cur_right){
        if (!cur){
            return cur_right;
        }
        cur->next = cur_right;
    }
    return head;
}

int cmp_by_title(const Song *s1, const Song *s2) {
    return str_case_cmp(s1->title, s2->title);
}

int cmp_by_artist(const Song *s1, const Song *s2) {
    return str_case_cmp(s1->artist, s2->artist);
}

int cmp_by_duration(const Song *s1, const Song *s2){
    return (s1->duration >= s2->duration);
}