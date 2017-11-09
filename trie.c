#include "trie.h"

node* createNode () {
	struct node* newNode = (struct node*) malloc(sizeof(node));
	if (trie) {
		for (int i = 0; i < 8; i++) {
			trie -> next[i] = NULL;
		}
		trie -> wordList = NULL;
		trie -> word = "";
		return newNode;
	} else {
		fprintf(stderr, "Error allocating memory for trie structure");
		exit(1);
	}
}

int charToLetter(char c) {
	if (c == 'a' || c == 'b' || c == 'c') {
		return 2;
	} else if (c == 'd' || c == 'e' || c == 'f') {
		return 3;
	} else if (c == 'g' || c == 'h' || c == 'i') {
		return 4;
	} else if (c == 'j' || c == 'k' || c == 'l') {
		return 5;
	} else if (c == 'm' || c == 'n' || c == 'o') {
		return 6;
	} else if (c == 'p' || c == 'q' || c == 'r' || c =='s') {
		return 7;
	} else if (c == 't' || c == 'u' || c == "v") {
		return 8;
	} else {
		return 9;
	}
}

node* fillTrie (node* trie, FILE* fp) {
	char* next_word = (char*) malloc(sizeof(char) * MAX_LENGTH);
	struct node* current_pos = (struct node*) malloc(sizeof(struct node));
	current_pos = trie;
	while(fgets(next_word, MAX_LENGTH, fp)) {
		// traverse the trie according to the letters in the word
		// until end of word is reached  
		for (int i = 0; i < strlen(next_word); i++) {
			int num = charToLetter(next_word[i]);
			if (current_pos -> next[num - 2] == NULL) {
				struct node* newNode = createNode();
				current_pos -> next[num - 2] = newNode;
			} else {
				current_pos = current_pos -> next[num-2];
			}
		}
		// add word into the current node unless a word already exists
		if (current_pos -> word == '') {
			current_pos -> word == next_word;
		} else {
			// start linked list for words
			if (current_pos -> wordList == NULL) {
				struct wordNode* word_list = (struct wordNode*) malloc(sizeof(struct wordNode));
				word_list -> word = next_word;
				word_list -> next_word = NULL;
				current_pos -> wordList == word_list;
			} else {
				struct wordNode* current_word = (struct wordNode*) malloc(sizeof(struct wordNode));
				current_word = current_pos -> wordList;
				while (current_word -> next_word != NULL) {
					current_word = current_word -> next_word;
				}
				current_word -> next_word = next_word;

			}
		}
	}
	free(next_word);
}

void deleteTrie ()