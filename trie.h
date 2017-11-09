#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TRIE_H
#define TRIE_H

typedef struct node {
	struct node* next[8];
	struct wordNode* wordList;
	char* word; //word stored at this path
} node;

typedef struct wordNode {
	struct node* next_word;
	char* word;
} wordList;
