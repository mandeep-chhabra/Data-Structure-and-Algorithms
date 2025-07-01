Node *segregate(Node *head)
{
    // code here
    if (head == nullptr || head->next == nullptr)
        return head;

    map<int, int> freq;
    Node *temp = head;

    while (temp != nullptr)
    {
        freq[temp->data]++;
        temp = temp->next;
    }

    temp = head;
    for (map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it)
    {
        int value = it->first;
        int count = it->second;

        for (int i = 0; i < count; i++)
        {
            temp->data = value;
            temp = temp->next;
        }
    }

    return head;
}