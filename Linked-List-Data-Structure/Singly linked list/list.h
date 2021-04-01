typedef struct node{
    int data;
    struct node *next;
}node;

typedef node* list;

void init(list *l);
void append(list *l, int d);
void traverse(list l);
void rem(list *l, int d);
int length(list l);
void destroy(list *l);
int isempty(list l);
void insert_beg(list *l,int d);
void insert_sorted(list *l, int d);
void Remove(list *l , int d);
void reverse(list *l);
void split(list *l);
void join(list *l1 , list* l2);
void insert_at(list *l, int i , int d);
int search(list l , int d);
int peek(list *l);
list Union(list L1, list L2);
int pop(list *l);
void sort(list *l);
