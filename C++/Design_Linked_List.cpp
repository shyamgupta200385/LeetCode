/*
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
*/

class MyLinkedList {

    class Node
    {
    public:
        int val;
        Node *next;
    };
    
    /** Length of list */
    int length;
    Node *head = NULL;
    
public:

    /** Initialize your data structure here. */
    MyLinkedList() {
        length = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        /** If index is invalid, return -1 */
        if(index<length && index>=0)
        {
            Node *cur = head;
            while(index>0)
            {
               cur = cur->next;
               index--;
            }
            return cur->val;
        }
        else
            return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int data) {
        Node *newnode = new Node();
        newnode->val = data;
        newnode->next = head;
        head = newnode;
        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int data) {
        Node *newnode = new Node();
        newnode->val = data;
        length++;
        if(head == NULL){
            head = newnode;
        }
        else
        {
            Node *cur = head;
            /** Traverse till the end */
            while(cur->next != NULL)
            {
                cur = cur->next;
            }
            /** Add newnode at the end */
          cur->next = newnode;
       }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int data) {
        if(index>length)
            return;
        if(index<0)
        {
           addAtHead(data);
           length++;
        }
        else
        {
            Node *dummy = new Node();
            dummy->val = -1;
            dummy->next = head;
            Node *cur = dummy;
            while(index>0)
            {
                cur = cur->next;
                index--;
            }
            Node *newnode = new Node();
            Node *temp = cur->next;
            newnode->val = data;
            cur->next = newnode;
            newnode->next = temp;
            head = dummy->next;
            length++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < length && index >= 0)
        {
            length--;
            Node *dummy = new Node();
            dummy->val = 0;
            dummy->next = head;
            Node *cur = dummy;
            while(index>0)
            {
               cur = cur->next;
               index--;
            }
            cur->next = cur->next->next;
            head = dummy->next;
        }
        else
            return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
