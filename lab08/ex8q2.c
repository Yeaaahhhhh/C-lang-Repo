
#include "lab08.h"

int main(int argc, char *argv[]) {
	if (argc != 3)
		return 0;
	check_validate(argv[1], __LINE__, __FILE__);
	check_validate(argv[2], __LINE__, __FILE__);
    check_add(argv[1], argv[2], __LINE__, __FILE__);
    check_gt(argv[1], argv[2], __LINE__, __FILE__);
    check_eq(argv[1], argv[2], __LINE__, __FILE__);
    check_diff(argv[1], argv[2], __LINE__, __FILE__);
    check_multiply(argv[1], argv[2], __LINE__, __FILE__);
    check_divide(argv[1], argv[2], __LINE__, __FILE__);
    check_modulo(argv[1], argv[2], __LINE__, __FILE__);
	return 0;
}

//the following function validates whether the string `p` represents a non-negative integer
//complete the function definition:
// 1) `p` is valid (not NULL);
// 2) a valid non-negative integer representation is either "0" or a sequence of digits w/o leading zeros
//    examples: "5678" corresponds to the integer 5678
//           "0" corresponds to the integer 0 (zero)
//           "005678" is invalid
//           "00" is invalid
//           "-1" is invalid
//           "123abc45" is invalid
// 3) return true iff `p` represents a non-negative integer
bool validate(const char *p) {
    if (strlen(p) > 1 && p[0] == '0'){
        return false;
    }
    for (int i = 0; p[i] != '\0';i++){
        if (p[i] < '0' || p[i]>'9'){
            return false;
        }
    }
    return true;
}

//the following function returns a new string representing m + n
//complete the function definition:
// 1) you can assume both m and n represent non-negative integers
// 2) you do not need to free the dynamically allocate memory for the new string
char *add(const char *m, const char *n) {
    int lens1 = strlen(m),lens2 = strlen(n);
    if(lens1 < lens2){
        return add(n,m);
    }
    int i = len1 -1;j = lens2-1,k=len1+1,carry = 0;
    char *result = calloc(k+1,sizeof(char));
    while(i>=0){
        int term = 0;
        if (j>0){
            t= n[j--];
        }
        int s = (m[i--]+t+carry)% '0';
        result[--k] = s % 10 +'0';
        carry = s/10;
    }
    if(carry >0){
        result[0] = '1';
        return result;
    }
    return result+1;
}

//the following function validates whether m > n
//complete the function definition:
// 1) you can assume both m and n represent non-negative integers
// 2) return true if m > n
bool gt(const char *m, const char *n) {
    if(strlen(m) == strlen(n)){
        for(int i = 0;i<strlen(m);i++){
            if (m[i]<n[i]){
                return false;
            }else if (m[i]>n[i]){
                return true;
            }
        }
        return false;
    }
    else if (strlen(m) > strlen(n)){
        return true;
    }
    else{
        return false;
    }
}

//the following function validates whether m == n
//complete the function definition:
// 1) you can assume both m and n represent non-negative integers
// 2) return true if m == n
bool eq(const char *m, const char *n) {
    if (strlen(m) == strlen(n)){
        for (int i = 0; i < strlen(m);i++){
            if (m[i] != n[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

//the following function returns a new string representing |m - n|
//complete the function definition:
// 1) you can assume both m and n represent non-negative integers
// 2) you do not need to free the dynamically allocate memory for the new string
char *diff(const char *m, const char *n) {
    if (eq(m,n)){
        return '';
    }
    if (gt(m.n)){
        int lens1 = strlen(m),lens2 = strlen(n);
        char *result = calloc(k+1,sizeof(char));

        char *newM = strrev(m);
        char *newN = strrev(n);

        int carry = 0;
        for (int i = 0; i< lens2;i++){
            int sub = (newM[i]-'0')- ((newN[i]-'0')-carry);

            if (sub<0){
                sub += 10;
                carry = 1;
            }
            else{
                carry = 0
            }
            result +=  (sub +'0')
        }
        for (int j = lens2,j<lens1;j++){
            int sub = (int (newM[i]-'0')-carry);

            if (sub < 0){
                sub+= 10;
                carry = 1;

            }
            else{
                carry = 0;
            }
            result += (sub+'0');
        }
        for (int i = lens2; i < lens1;i++){
            int sub = ((newM[i]-'0')-carry)
            if (sub < 0){
                sub+= 10;
                carry = 1;

            }
            else{
                carry = 0;
            }
            result += (sub+'0');
        }
        return result;
    }

}

//the following function returns a new string representing m * n
//complete the function definition:
// 1) you can assume both m and n represent non-negative integers
// 2) you do not need to free the dynamically allocate memory for the new string
char *multiply(const char *m, const char *n) {
    // this part of code(function) helped by Junzhuo Huang to complete.
    int lens1 = strlen(m),lens2 = strlen(n);
    char* result = malloc(sizeof(char) * (lens1 + lens2 + 3));
    memset(result,0,sizeof(char) * (lens1 + lens2 + 3));
    if((lens1 == 1 && m[0] == '0') || (lens2 == 1 && n[0] == '0')){
        result[0] = '0',result[1] = 0;
        return result; // 0 in the multiplication returns 0
    }
    int* ansArr = malloc(sizeof(int) * (lens1 + lens2 + 3));
    memset(ansArr,0,sizeof(int) * (lens1 + lens2 + 3));
    for(int i = lens1 - 1;i >= 0;i--){
        int x = m[i] - '0';
        for(int j = lens2 - 1;j >= 0;j--){
            int y = n[j] - '0';
            ansArr[i + j + 1] += x * y;
        }
    }
    for(int i = lens1 + lens2 - 1;i > 0;i--){
        ansArr[i - 1] += ansArr[i] / 10;
        ansArr[i] %= 10;
    }
    int pos = ansArr[0] == 0 ? 1 : 0;
    int ansLen = 0;
    while(pos < lens1 + lens2){
        result[ansLen++] = ansArr[pos];
        pos++;
    }
    for(int i = 0;i < ansLen;i++)
        result[i] += '0';
    return result;
}

//the following function returns a new string representing m / n
//complete the function definition:
// 1) you can assume both m and n represent non-negative integers
// 2) return NULL if n == 0;
// 3) you do not need to free the dynamically allocate memory for the new string
char *divide(const char *m, const char *n) {

}

//the following function returns a new string representing m % n
//complete the function definition:
// 1) you can assume both m and n represent non-negative integers
// 2) return NULL if n == 0;
// 3) you do not need to free the dynamically allocate memory for the new string
char *modulo(const char *m, const char *n) {

}

