void deleteNode(Node* node)
{
	Node* prev;
	if (node == NULL)
		return;
	else {
		if(node->next != NULL) {
           prev =node->next;
			node->data = prev->data;
			node->next =prev->next;
		}
	}
}
