class Solution 
{
public:
    Node* flatten(Node* head) 
    {
        return flattenUtil(head);
    }
private:
    Node* flattenUtil(Node* head)
    {
        if (!head)
            return head;
        
        if (head->child)
        {
            Node* last = getLast(head->child);
            last->next = head->next;
            if (head->next)
            {
                head->next->prev = last;
            }
            
            head->next = head->child;
            head->child->prev = head;
            head->child = nullptr;
        }
        
        flatten(head->next);
        
        return head;
    }
    
    Node* getLast(Node* head)
    {
        while (head->next)
        {
            head = head->next;
        }
        
        return head;
    }
};
