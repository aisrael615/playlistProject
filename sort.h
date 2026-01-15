#ifndef SORT_H
#define SORT_H

#include<stdlib.h>
#include"node.h"
#include"song.h"

Node *merge_sort_recur(Node *head, int (*cmp)(const Song*, const Song*));
Node *split_list(Node *head);
Node *merge_lists(Node *left_sorted, Node *right_sorted, int (*cmp)(const Song*, const Song*));
int cmp_by_title(const Song *s1, const Song *s2);
int cmp_by_artist(const Song *s1, const Song *s2);
int cmp_by_duration(const Song *s1, const Song *s2);

#endif