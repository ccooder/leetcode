//
// Created by King on 2020/6/13 15:51.
//

#ifndef JUSTFORFUN_ADD_TWO_NUMBERS_H
#define JUSTFORFUN_ADD_TWO_NUMBERS_H

#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void display(struct ListNode *l) {
    printf("\n[");
    while (l != NULL) {
        printf("%d, ", l->val);
        l = l->next;
    }
    printf("]\n");
}

struct ListNode *push(struct ListNode *l, int val) {
    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    l->next = node;
    return node;
}


struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    int carry = 0;
    struct ListNode *sumL = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *temp = sumL;
    while (1) {
        int n1=0, n2=0, sum_bit;
        if (l1 == NULL && l2 == NULL) {
            if (carry)
                push(temp, carry);
            break;
        }else {
            if (l1 != NULL) {
                n1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL){
                n2 = l2->val;
                l2 = l2->next;
            }
            sum_bit = n1 + n2 + carry;
            carry = sum_bit / 10;
            int bit = sum_bit % 10;
            temp = push(temp, bit);
        }
    }
    return sumL->next;
}

int func() {
    struct ListNode *l1 = (struct ListNode *) malloc(sizeof(struct ListNode));
//    push(push(push(l1, 2), 4), 3);
    push(l1, 5);
    display(l1->next);

    struct ListNode *l2 = (struct ListNode *) malloc(sizeof(struct ListNode));
//    push(push(push(l2, 5), 6), 4);
    push(l2, 5);
    display(l2->next);

    struct ListNode *sumL = addTwoNumbers(l1->next, l2->next);

    display(sumL);

    return 0;
}

#endif //JUSTFORFUN_ADD_TWO_NUMBERS_H
