typedef struct node {
    int data;
    struct node* next;
}NODE;

NODE* create_list(NODE* start);
void display(NODE* start);
void count(NODE* start);
void search(NODE* start, int data);
NODE* addatbeg(NODE* start, int data);
NODE* addatend(NODE* start, int data);
NODE* addafter(NODE* start, int data, int item);
NODE* addbefore(NODE* start, int data, int item);
NODE* addatpos(NODE* start, int data, int pos);
NODE* del(NODE* start, int data);
void destroy_list(NODE* head);
NODE* reverse(NODE* start);