
#include "lab10.h"

struct node;
struct dictionary;

// see "lab10.h" for requirements.
struct dictionary *dict_create(void) {
    struct *p = dict->head;
    p = malloc(sizeof(struct node));
    if(NULL == p){
        return NULL;
    }
    p ->word = NULL;
    p ->prec = NULL;
    p ->succ = NULL;
}

// see "lab10.h" for requirements.
void dict_destroy(struct dictionary **dict) {
    struct node *current = *dict;
    struct node *next;
    while(current !=NULL){
        next = current ->succ;
        free(current);
        current = next;
    }
    *dict = NULL;

	return;
}

// see "lab10.h" for requirements.
void dict_add(struct dictionary *dict, const char *str) {
    struct node *p = dict->head;
    struct node *newNode;
    newNode ->word = str;
    while(NULL != p->succ){
        p = p->succ;
    }
    if(newNode ->prec == str){
        return;
    }
    p ->succ = newNode;
    newNode ->prec = p;
	return;
}

// see "lab10.h" for requirements.
void dict_remove(struct dictionary *dict, const char *str) {
    struct node *p = dict->head;
    while (NULL != p->succ){
        p = p->succ;
        if (p->word == str){
            if(p->succ != NULL){
                p->succ ->prec = p->prec;
                p ->prec ->succ = p->succ;
                free(p);
            }
        }
            else{
                p->prec->succ=NULL;
                free(p);
            }
    }
	return;
}

// see "lab10.h" for requirements.
int dict_search(const struct dictionary *dict, const char *str) {
    int posi = 0;
    struct node*p = dict->head;
    while(NULL != p->succ){
        if(str == p->word){
            return posi;

        }
        p = p ->succ;
        posi++;
    }
    return -1;
}

// see "lab10.h" for requirements.
int dict_count(const struct dictionary *dict) {
    int len = 0;
    struct node *p = dict->head;
    while(NULL != p->succ){

        p = p->succ;
        len ++;
    }
    return len;

}

// see "lab10.h" for requirements.
char *dict_get(const struct dictionary *dict, int pos) {

    struct node *p = dict->head;
    char answer = p->word;
    int curPos = 0;
    while(NULL != p->succ){
        if(pos ==dict_count(dict)){  //out of range
            return NULL;
        }
        if(curPos == pos){
            return answer;
        p = p->succ;
        answer = p->word;
        curPos ++;

        }

    }

}

// see "lab10.h" for requirements.
void dict_merge(struct dictionary *dict1, struct dictionary **dict2) {
    if (dict1 == NULL || *dict2 == NULL){
        return;
    }
    struct node *mergeHead = dictionary->head;
    mergeHead = NULL;
    mergeHead = dict1->head;
    mergeHead ->succ = dict_merge(dict1->head,*dict2);
    mergeHead ->succ->succ->prec = mergeHead->succ;

	return;
}
