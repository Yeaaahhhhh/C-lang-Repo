
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
  Dictionary of words: The words in a dictionary are SORTED in lexicographical order.

  To create a new dictionary:
    struct dictionary *dict = dict_create();

  To destroy the dictionary:
      dict_destroy(&dict);

  To add a word:
      dict_add(dict, "fall");

  A copy of the word is added to the dictionary; afterwards, if one modifies the
  contents of the original word that was added, the dictionary is not affected, e.g.
      char str[] = "fall";
      dict_add(dict, str);
      str[1] = 'i';          // dict still contains "fall", not "fill"

  Two words are duplicates only if every character is identical.
      dict_add(dict, "fall");
      dict_add(dict, "Fall");    // ADDED (different word, case-sensitive)
      dict_add(dict, "fall ");   // ADDED (different word)
      dict_add(dict, "fall");    // NO EFFECT

  To remove a word:
      dict_remove(dict, "winter"); // no effect if the word does not exist in dict

  To search for a word in dict: returns either the "position" of the word (position starting from 0) or -1 if it does not exist.
      int pos = dict_search(dict, "me");

  To determine how many words are in dict, call:
      int count = dict_count(dict);

  To retrieve a pointer to the word with a given position:
      char *dict_get(dict, pos);

  Afterwards, if one modifies the contents of the retrieved word, the dictionary is not affected, e.g.
      char *str = dict_get(dict, 3); // assuming the retrieved word is "fall";
      str[1] = 'i';          // dict still contains "fall", not "fill"

  To merge two dictionaries into one:
      dict_merge(dict1, &dict2);
*/

struct node {
	char *word; //must be dynamically allocated to store a string, i.e., not point to a string literal
	struct node *prec;
	struct node *succ;
};

struct dictionary {
	int length;
	struct node *head;
};


// dict_create() creates a new empty dictionary
struct dictionary *dict_create(void);

// dict_destroy(dict) destroys `dict`
// 1) requires: `dict` is valid (not NULL)
void dict_destroy(struct dictionary **dict);

// dict_add(dict, str) adds `str` to `dict` in the correct position (lexicographically)
// 1) requires: `dict` is valid (not NULL)
// 2) no effect if `str` already exists in `dict`
void dict_add(struct dictionary *dict, const char *str);

// dict_remove(dict, str) removes `str` from `dict` (if it exists in `dict`)
// 1) requires: `dict` is valid (not NULL)
// 2) no effect if `str` doesn't exist in `dict`
void dict_remove(struct dictionary *dict, const char *str);

// dict_search(dict, str) finds the position of `str` in `dict`, and return it
// 1) requires: `dict` is valid (not NULL)
// 2) position starts from 0 - the same as position/index in an array
// 3) return `-1` if `str` doesn't exist in `dict`
int dict_search(const struct dictionary *dict, const char *str);

// dict_count(dict) gets the number of words in `dict`, and return it
// 1) requires: `dict` is valid (not NULL)
int dict_count(const struct dictionary *dict);

// dict_get(dict, pos) retrieves a pointer to the word in `dict` at the given position `pos`
// 1) requires: `dict` is valid (not NULL)
// 2) return NULL if `pos` is out of range
char *dict_get(const struct dictionary *dict, int pos);

// dict_merge(dict1, dict2) merges `dict2` into `dict1`
// 1) requires: `dict1` and `dict2` are valid (not NULL)
// 2) `dict2` becomes NULL and memory deallocated properly
// 3) `dist1` contains all the distinct words
void dict_merge(struct dictionary *dict1, struct dictionary **dict2);

