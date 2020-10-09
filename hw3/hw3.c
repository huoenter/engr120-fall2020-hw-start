#include <stdio.h>

/* Returns the number of occurrences of string t in s
 *
 * Example:
 * substring_n("hello", "el") => 1
 * substring_n("", "ab") => 0
 * substring_n("utilities", "ti") => 2
 *
 */
int substring_n(char *s, char *t)
{
    int cnt = 0, i = 0;

    while (*(s + i) != '\0') {
        int j = 0;
        while (*(s + i + j) == *(t + j) && *(s + i + j) != '\0')
            j++;
        if (*(t + j) == '\0')
            cnt++;
        i++;
    }

    return cnt;
}

/* Changes all occurrences of t in s to u, result stored in v
 *
 * Example:
 *
 * char v[100];
 * replace("hello", "el", "abc", v) => v becomes "habclo"
 * replace("", "el", "abc", v) => v becomes "" (no change)
 * replace("hello", "abc", "def", v) => v becomes "hello"  (no change)
 * replace("utilities", "ti", "def", v) => v becomes "udeflidefes"
 *
 */

void replace(char *s, char *t, char *u, char *v)
{
    int i = 0, k = 0;
    while (*(s + i) != '\0') {
        int j = 0;
        while (*(s + i + j) == *(t + j) && *(s + i + j) != '\0')
            j++;
        if (*(t + j) == '\0') {
            int n = 0;
            while (*(u + n) != '\0')
                v[k++] = u[n++];
            i += j;
        } else
            v[k++] = s[i++];
    }

    v[k] = '\0';
}

/*
A barcode scanner for Universal Product Codes (UPCs) verifies the 12 digit code
scanned by comparing the code’s last digit (called a check digit) to its own
computation of the check digit from the first 11 digits as follows:

1. Calculate the sum of the digits in the odd numbered positions (the first,
third, ..., eleventh digits) and multiply this sum by 3.

2. Calculate the sum of the digits in the even numbered positions (the second,
fourth, ..., tenth digits) and add this to the previous result.

3. If the last digit of the result from step 2 is 0, then 0 is the check digit.
Otherwise, subtract the last digit from 10 to calculate the check digit.

4. If the check digit matches the final digit of the 12 digit UPC, the UPC is
assumed correct.

Write a function that takes in the 12 digits of a barcode as an integer array.
The function should calculate the check digit, and compare it to the final
barcode digit. If the digits match, the function returns -1. If not, return the
value of the check digit.  Note that the "first" digit of the barcode will be
stored in element 0 of the array. For the first example, the result from step 2
is 79      (0 + 9 + 0 + 8 + 4 + 0) * 3 + (7 + 4 + 0 + 0 + 5).

For example

int code1[] = {0, 7, 9, 4, 0, 0, 8, 0, 4, 5, 0, 1};
validate(code);      =>  return -1  (valid)

int code2[] = {0, 2, 4, 0, 0, 0, 1, 6, 2, 8, 6, 0};
validate(code);      =>  return 5   (invalid, check digit is 5 instead of 0)

Make use of even_sum and odd_sum for summing up odd and even digits from the
code and return the sum.
*/

#define N 12

int oddSum(int code[]) {
  int sum = 0;
  for (int i = 0; i< N - 1; i += 2) {
    sum += code[i];
  }

  return sum;
}

int evenSum(int code[]) {
  int sum = 0;
  for (int i = 1; i< N - 1; i += 2) {
    sum += code[i];
  }

  return sum;
}

int validate(int code[]) {
  int check_digit = 0;

  int sum = 3 * oddSum(code) + evenSum(code);

  if (sum % 10 == 0)
    check_digit = 0;
  else
    check_digit = 10 - (sum % 10);

  if (code[N - 1] == check_digit)
    return -1;

  return check_digit;
}

/*

Develop a collection of functions to solve simple conduction problems using
various forms of the formula

         kA(T2 - T1)
    H = -------------
              X

where H is the rate of heat transfer in watts, k is the coefficient of thermal
conductivity for the particular substance, A is the cross sectional area in m^2
(square meters), T2 and T1 are the kelvin temperatures on the two sides of the
conductor, and X is the thickness of the conductor in meters.

Define a function for each variable in the formula. For example, function
calc_h would compute the rate of heat transfer, calc_k would figure the
coefficient of thermal conductivity, calc_a would find the cross sectional
area, and so on.


You will read in a line with 6 coefficients from a file. One of the coefficient
is missing and represented by a question mark. The file pointer is given.

Example:

The line in the file is shown below:
755.0 0.8 0.12 298 ? 0.003

This means:
H = 755.0
k = 0.8
A = 0.12
T2 = 298
T1 is unknown
X = 0.003

File *in = fopen("values.txt");
int values[6];
heat_transfer(values, in);

values will become:
755.0 0.8 0.12 298 274 0.003

Notice that T1 is calculated.

Hint: Input of the question mark when looking for a number will cause scanf to
return a value of 0. Be sure to check for this, and then scan the question mark
into a character variable before proceeding with the remaining prompts

*/
void calc_h(double values[]) {
  double h = values[0], k = values[1], a = values[2],
         t2 = values[3], t1 = values[4], X = values[5];
  values[0] =  k * a * (t2 - t1) / X;
}

void calc_k(double values[]) {
  double h = values[0], a = values[2],
         t2 = values[3], t1 = values[4], X = values[5];
  values[1] = h * X / (a * (t2 - t1));
}

void calc_a(double values[]) {
  double h = values[0], k = values[1],
         t2 = values[3], t1 = values[4], X = values[5];
  values[2] = h * X / (k * (t2 - t1));
}

void calc_t2(double values[]) {
  double h = values[0], k = values[1], a = values[2],
         t1 = values[4], X = values[5];
  values[3] = (h * X / (k * a)) + t1;
}

void calc_t1(double values[]) {
  double h = values[0], k = values[1], a = values[2],
         t2 = values[3], X = values[5];
  values[4] = t2 - (h * X / (k * a));
}

void calc_X(double values[]) {
  double h = values[0], k = values[1], a = values[2],
         t2 = values[3], t1 = values[4];
  values[5] = k * a * (t2 - t1) / h;
}

void heat_transfer(double values[], FILE *input)
{
    int statuses[6] = {0};

    char dummy; /* used to discard the question mark */

    int missing = -1;

    for (int i = 0; i < 6; i++) {
        statuses[i] = fscanf(input, "%lf", values + i);
        if (statuses[i] == 0) {
            fscanf(input, "%c", &dummy);
            missing = i;
        }
    }

    switch (missing) {
        case 0: calc_h(values); break;
        case 1: calc_k(values); break;
        case 2: calc_a(values); break;
        case 3: calc_t2(values); break;
        case 4: calc_t1(values); break;
        case 5: calc_X(values); break;
        default: break;
    }
}
