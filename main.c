#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
int main()
{
    struct node* start = NULL;
    int choice, data, item, pos;

    while (1)
    {
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Add to empty list / Add at beginning\n");
        printf("6.Add at end\n");
        printf("7.Add after node\n");
        printf("8.Add before node\n");
        printf("9.Add at position\n");
        printf("10.Delete\n");
        printf("11.Reverse\n");
        printf("12.Destroy list\n");
        printf("13.Quit\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            count(start);
            break;
        case 4:
            printf("Enter the element to be searched : ");
            scanf("%d", &data);
            search(start, data);
            break;
        case 5:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            start = addatbeg(start, data);
            break;
        case 6:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            start = addatend(start, data);
            break;
        case 7:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element after which to insert : ");
            scanf("%d", &item);
            start = addafter(start, data, item);
            break;
        case 8:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element before which to insert : ");
            scanf("%d", &item);
            start = addbefore(start, data, item);
            break;
        case 9:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the position at which to insert : ");
            scanf("%d", &pos);
            start = addatpos(start, data, pos);
            break;
        case 10:
            printf("Enter the element to be deleted : ");
            scanf("%d", &data);
            start = del(start, data);
            break;
        case 11:
            start = reverse(start);
            break;
        case 12:
            destroy_list(start);
            start = NULL;
            break;
        case 13:
            exit(1);
        default:
            printf("Wrong choice\n");
        }/*End of switch */
    }/*End of while */

    return 0;
}/*End of main()*/
