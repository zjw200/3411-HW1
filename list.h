struct node {
    int value;
    struct node *next;
};

struct node *create(int v);
void append(struct node *root, int v);
void print(struct node *root);
void free_list(struct node *root);
struct node *prepend(struct node *root, int value);
int get(struct node *root, int index);
void add(struct node *root, int index, int value);
void remove2(struct node *root, int index);
int find(struct node *root, int value);




