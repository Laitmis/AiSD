struct QueueItem
{
    char value;
    QueueItem *next;
};

struct Queue
{
    QueueItem *head;
    QueueItem *tail;
};

Queue* initQueue()
{
    Queue *q = new Queue;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

bool isEmpty(Queue *q)
{
    return q->head == NULL;
}

void push(Queue *q,char c)
{
    if (isEmpty(q))
    {
        q->head = new QueueItem;
        q->head->value = c;
        q->head->next = NULL;
        q->tail = q->head;
    }
    else
    {
        QueueItem *tmp = new QueueItem;
        tmp->value = c;
        tmp->next = NULL;
        q->tail->next = tmp;
        q->tail = q->tail->next;
    }
}

char pop(Queue *q)
{
    if (isEmpty(q)) return '\0';

    QueueItem *tmp = q->head;
    char c_tmp = tmp->value;

    q->head = q->head->next;
    delete tmp;

    if (q->head == NULL) q->tail = NULL;

    return c_tmp;
}
