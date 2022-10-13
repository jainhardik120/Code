int findSecondLastNode(struct Node* head)
{
    struct Node* temp = head;
  
    if (temp == NULL || temp->next == NULL)
        return -1;
  
    while (temp != NULL) {
  
        if (temp->next->next == NULL)
            return temp->data;
  
        temp = temp->next;
    }
}
void push(struct Node** head_ref, int new_data)
{
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
