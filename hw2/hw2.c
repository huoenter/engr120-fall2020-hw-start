/* Returns 1 when rator1 has higher precedence,
 *        -1 when rator2 has higher precedence,
 *         0 when they have equal precedence.
 * Example, precedence('!', '|') returns 1
 * Please refer to ALL the single character operators on page 53, table 2 - 1
 * except '*', '&', '+', '-' on the SECOND row
 *
 * Hint: Add a new function that takes in an operator and
 * returns a number to represent the precedence. Use a switch statement in it.
 */

int prec(char op)
{
    int p = 0;

    switch (op) {
        case '.': p = 14; break;
        case '!': case '~': p = 13; break;
        case '*': case '/': case '%': p = 12; break;
        case '+': case '-': p = 11; break;
        case '<': case '>': p = 9; break;
        case '&': p = 7; break;
        case '^': p = 6; break;
        case '|': p = 5; break;
        case '=': p = 1; break;
        case ',': p = 0; break;
    }

    return p;
}

int precedence(char rator1, char rator2) {
    int p1 = prec(rator1);
    int p2 = prec(rator2);

    if (p1 < p2)
        return -1;
    else if (p1 > p2)
        return 1;
    else
        return 0;
}

/* Rewrite strcat on page 48 using for loops only */
void mystrcat(char s[], char t[]) {
    int i, j;
    for (i = 0; s[i] != '\0'; i++) {}
    for (j = 0; (s[i++] = t[j++]) != '\0'; ) {}
}

/* This is an enhanced version of lower on page 43
 *
 * Converts all upper case letters in s to lower case.
 * Returns the number of converstions.
 *
 * Example: lower("abc") returns 0, s not changed
 * lower("HelL0") returns 2, s becomes "hell0", (last character is zero)
 * lower("+-*AbC") returns 2, s becomes "+-*abc"
 */
int lower(char s[]) {
    int cnt = 0;
    int i = 0;
    while (s[i] != '\0') {
        if ('A' < s[i] && s[i] < 'Z') {
            s[i] = s[i] + 32;
            cnt++;
        }
        i++;
    }
    return cnt;
}

/* Returns -1, 0 or 1 if s is lexicographically less than, equal to,
 * or greater than t. This is more specific than the standard version.
 *
 * s and t are equal if each character at the same position is equal.
 *
 * If the first n characters match and the n + 1th characters are the
 * first nonmatching ones, then
 *    if s[n] < t[n], s is less than t
 *    if s[n] > t[n], s is greater than t
 * e.g. "abc" is less than "abd"
 * e.g. "abcxxx" is less than "abd" even if the former string is longer
 *
 * Please watch the video about "strcmp" on D2L first.
 */
int mystrcmp(char s[], char t[]) {
    int i = 0;
    while (s[i] == t[i]) {
      if (s[i] == '\0') return 0;
      i++;
    }
    return s[i] - t[i] > 0 ? 1 : -1;
}

/* Read ch2.8.
 * The squeeze function is a little tricky for beginners since
 * it modifies the string in place. Here we implement an
 * easier squeeze:
 *
 * int squeeze(char s[], char t[], char c)
 *
 * which reads in a string s, and put the squeezed string in t.
 * Finally it returns number of squeezed characters.
 *
 * Example:
 * char t[10];
 * squeeze("hello", t, 'l') return 2 and t will be "heo".
 */
int squeeze(char s[], char t[], char c) {
    int i = 0, j = 0, cnt = 0;
    while (s[i] != '\0') {
        if (s[i] != c) {
            t[j] = s[i];
            j++;
        } else {
            cnt++;
        }
        i++;
    }
    t[j] = '\0';

    return cnt;
}

/* You should've read ch3.5.
 * Instead of reverse which reverses a whole string.
 * reverse_n will only reverse the first n characters.
 *
 * Example, reverse_n("abcdef", 3) will change s to "abc".
 * reverse("abc", 0) will not change s.
 *
 * Assume n will never be greater than the size of s.
 *
 * Take look at main.c to see how reverse_n is used.
 */
void reverse_n(char s[], int n) {
    int i = 0, j = n - 1, c;
    while (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }
}
