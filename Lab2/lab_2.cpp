struct Node
{
    char c;
    Node *next;
};

struct Stack
{
    Node *head;
};

Stack initList()
{
    Stack st;
    st.head = NULL;
    return st;
}

bool isEmpty(Stack &st) { return st.head == NULL; }

void push(Stack &st, char c)
{
    Node *tmp = new Node;
    tmp->c = c;
    tmp->next = st.head;

    st.head = tmp;
}

char pop(Stack &st)
{
    if (isEmpty(st)) return '\0';

    Node *tmp = st.head;
    char c_tmp = tmp->c;

    st.head = st.head->next;
    delete tmp;

    return c_tmp;
}
