#include "push_swap.h"

int get_middle_element(t_node **head)
{
    t_node *fast;
    t_node *slow;

    slow = *head;
    fast = *head;

    while (fast != (*head) && slow != (*head))
    {
        slow = slow->nextInLine;
        fast = fast->nextInLine->nextInLine;
    }
    return (slow->content);
}


// void    merge_arrays(t_node **head, int left, int right, int middle)
// {
//     t_node *left_stack;
//     t_node *right_stack;
//     int side1;
//     int side2;
//     int first;
//     int sec;
//     int all;

//     side1 = middle - left + 1;
//     side2 = right - middle;
//     first = 0;
//     sec = 0;

//     while (first < side1)
//     {
//         left_stack = (*head)  ;
//         first++;
//     }
//     while (sec < side2)
//     {
//         right_arr[sec] = (*head)[middle + 1 + sec];
//         sec++;
//     }
//     first = 0; //index primeiro subarray
//     sec = 0; //index segundo subarray
//     all = left; //index  merged array
//     while (first < side1 && sec < side2)
//     {
//         if (left_arr[first] <= right_arr[sec])
//         {
//             (*head)[all] = left_arr[first];
//             first++;
//         }
//         else
//         {
//             (*head)[all] = right_arr[sec];
//             sec++; 
//         }
//         all++;
//     }
//     while (first < side1) //copiar os restantes elementos do left_arr
//     {
//         (*head)[all] = left_arr[first];
//         first++;
//         all++;
//     }
//     while (sec < side2) // copiar os restantes elementos do right_arr
//     {
//         (*head)[all] = right_arr[sec];
//         sec++;
//         all++;
//     }
// }

// void    merge_sort(t_node **head, int left, int right) //algorithm
// {
//     int middle;

//     if (left > right)
//         return ;
//     if (left < right)
//     {
//         middle = get_middle_element(head);
//         merge_sort(head, left, middle);
//         merge_sort(head, middle + 1, right);
//         merge(head, left, middle, right);
//     }
// }