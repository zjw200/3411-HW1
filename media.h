struct media {
	char* name;
	char* creator;
};

struct ll_node {
	void* data;
	struct ll_node* next;
};

struct linked_list {
	struct ll_node* head;
};
