


typedef struct {
    int data[110];   // enough size for constraints
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

bool isEmptyQ(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int x) {
    q->data[q->rear++] = x;
    q->size++;
}

int dequeue(Queue* q) {
    int val = q->data[q->front++];
    q->size--;
    return val;
}

int peek(Queue* q) {
    return q->data[q->front];
}

// ---------------- Stack using two queues ----------------
typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    initQueue(&st->q1);
    initQueue(&st->q2);
    return st;
}

void myStackPush(MyStack* obj, int x) {
    // Always push into q2 first
    enqueue(&obj->q2, x);

    // Move everything from q1 → q2
    while (!isEmptyQ(&obj->q1)) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }

    // Swap q1 and q2
    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->q1);
}

int myStackTop(MyStack* obj) {
    return peek(&obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return isEmptyQ(&obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}


/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/