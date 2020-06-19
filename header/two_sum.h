//
// Created by King on 2020/6/12 21:45.
//

/*
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
 */

#ifndef JUSTFORFUN_TWO_SUM_H
#define JUSTFORFUN_TWO_SUM_H

#include <stdlib.h>

typedef struct {
    int value;
    int idx;
} data;

/**
 * shell_sort
 * @param srcData
 * @param count
 */
void shell_sort(data *srcData, int count) {
    int gap = count;
    while ((gap /= 2) >= 1) {
        for (int i = gap; i < count; i++) {
            data key = srcData[i];
            int j = i - gap;
            for (; j >= 0 && srcData[j].value > key.value; j -= gap) {
                srcData[j + gap] = srcData[j];
            }
            srcData[j + gap] = key;
        }
    }
}

int bisearch(data *sorted, const int *target, int start, int size) {
    int left, middle, right;

    left = start;
    right = size - 1;
    while (left <= right) {
        middle = (left + right) / 2;
        if ((sorted + middle)->value < target) {
            left = middle + 1;
        } else if ((sorted + middle)->value > target) {
            right = middle - 1;
        } else {
            return middle;
        }
    }
    return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    data *srcData = malloc(sizeof(data) * numsSize);
    for (int j = 0; j < numsSize; ++j) {
        data d;
        d.idx = j;
        d.value = *(nums+j);
        *(srcData+j) = d;
    }
    *returnSize = 2;
    int *returnNums = (int *) malloc(sizeof(int) * 2);
    shell_sort(srcData, numsSize);
    for (int i = 0; i < numsSize; i++) {
        *returnNums = (srcData+i)->idx;
        int pos = bisearch(srcData, target - (srcData + i)->value, i+1, numsSize);
        if (pos > i) {
            *(returnNums + 1) = (srcData+pos)->idx;
            break;
        }
    }
    return returnNums;
}

int func() {
    int nums[] = {3, 3};
    int target = 6;
    int numSize = 2;
    int returnSize = 0;
    int *returnNums = twoSum(nums, numSize, target, &returnSize);
    printf("结果：\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", *(returnNums + i));
    }
    return 0;
}

#endif //JUSTFORFUN_TWO_SUM_H
