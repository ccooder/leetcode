//
// Created by King on 2020/6/14 15:00.
//

#ifndef JUSTFORFUN_LONGEST_SUBSTRING_H
#define JUSTFORFUN_LONGEST_SUBSTRING_H

#include <string.h>

typedef struct {
    int count;
    int pos;
} record;

void find_sub(int *pos, const char *s, int *len) {
    record rec;
    rec.count = 0;
    rec.pos = 0;
    record r[128] = {rec};
    while (*(s + (*pos)) != '\0') {
        char c = *(s + (*pos));
        if (r[c].count) {
            *pos = r[c].pos + 1;
            break;
        } else {
            (r[c].count)++;
            r[c].pos = *pos;
            (*len)++;
            (*pos)++;
        }

    }
}

int lengthOfLongestSubstring(char *s) {
    int len = 0;
    int p = 0;
    int str_len = strlen(s);
    while (*(s + p) != '\0' && str_len - p > len) {
        int temp_len = 0;
        find_sub(&p, s, &temp_len);
        if (temp_len > len)
            len = temp_len;
        if (len == 95)
            return len;
    }
    return len;
}

int lengthOfLongestSubstring1(char *s) {
    int start = 0, end = 0, maxlen = 0;
    char map[256] = {0};
    map[*(s + start)] = 1;

    while (*(s + end) != 0) {
        maxlen = maxlen > (end - start + 1) ? maxlen : (end - start + 1);
        ++end;
        while (0 != map[(int) *(s + end)]) {
            map[*(s + start)] = 0;
            ++start;
        }
        map[*(s + end)] = 1;
    }

    return maxlen;
}

int lengthOfLongestSubstring3(char *s) {
    int start = 0, end = 0, max_len = 0;
    int hash[128] = {-1};
    int size = strlen(s);
    while (end < size) {
        while (hash[*(s + end)] == 0 && end < size) {
            hash[*(s + end)] = 1;
            end++;
        }
        int len = end - start;
        max_len = len > max_len ? len : max_len;
        if (end < size) {
            while (*(s + start) != *(s + end)) {
                hash[*(s + start)] = 0;
                start++;
            }
            hash[*(s + end)] = 0;
            start += 1;
        }

    }
    return max_len;
}

int lengthOfLongestSubstring4(char *s) {
    int i, j, left, right, cur, prev = 0, ans = 0;

    if (!s) return 0;

    for (i = 0; s[i] != '\0'; i++) {
        left = i - prev;
        right = i - 1;
        for (j = right; j >= left; j--) {
            if (s[j] == s[i]) break;
        }

        cur = i - j;
        if (cur > ans) {
            ans = cur;
        }

        prev = cur;
    }

    return ans;
}

int lengthOfLongestSubstring2(char *s) {
    if (!strlen(s)) return 0;
    int left = -1, right = 0, max_len = 0;
    int hash[128] = {0};
    while (*(s + right)) {
        if (hash[*(s + right)] >= left) {
            max_len = right - left > max_len ? right - left : max_len;
            left = hash[*(s + right)];
        }
        hash[*(s + right)] = right + 1;
        right++;
    }
    return max_len > right - left ? max_len : right - left;
}

int func() {
    char *s = "pwkwew";
    printf("the len of longest substring about %s is %d\n", s, lengthOfLongestSubstring2(s));
    return 0;
}

#endif //JUSTFORFUN_LONGEST_SUBSTRING_H
