/* You are keeping score for a basketball game with some new rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the operation you must apply to the record, with the following rules:

A non-negative integer x (from 0 to 9) - record a new score of x
'+' - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
'D' - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
'C' - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
Finally, return the sum of all scores in the record.

For example:

ops = "52CD+"

'5' - add to the record. Record now is [5]
'2' - add to the record. Record now is [5,2]
'C' - invalid the previous score (2). Record now is [5]
'D' - Record new score that is double of previous score (5*2). Record now is [5,10]
'+' - Record a new score that is the sum of the previous two scores. Record now is [5,10,15]
Return the sum: 5+10+15 = 30


For example:

Test	Result
cout << baseballScore("52CD+");
30
cout << baseballScore("524CD9++");
55
*/

#include <iostream>
#include <string>
#include <stack>


using namespace std;

int baseballScore(string ops) {
    // // Initialize an empty stack to keep track of the scores
    // stack<int> scores;
    stack<int> scores;

    // // Iterate through each character in the ops string
    // for each character in ops:
    //     if character is a digit:
    //         // Convert character to integer and push it onto the stack
    //         push the integer value onto the stack
    //     else if character is '+':
    //         // Pop the top two elements from the stack, sum them, and push the result back onto the stack
    //         pop the top two elements from the stack
    //         calculate their sum
    //         push both elements back onto the stack
    //         push the sum onto the stack
    //     else if character is 'D':
    //         // Pop the top element from the stack, double it, and push the result back onto the stack
    //         pop the top element from the stack
    //         calculate its double
    //         push the original element back onto the stack
    //         push the doubled value onto the stack
    //     else if character is 'C':
    //         // Pop the top element from the stack to invalidate the previous score
    //         pop the top element from the stack
    for (char op : ops) {
        if (isdigit(op)) {
            // Convert character to integer and push it onto the stack
            scores.push(op - '0');
        } else if (op == '+') {
            // Pop the top two elements from the stack, sum them, and push the result back onto the stack
            int top1 = scores.top(); scores.pop();
            int top2 = scores.top();
            scores.push(top1); // Push the first element back
            scores.push(top1 + top2); // Push the sum
        } else if (op == 'D') {
            // Pop the top element from the stack, double it, and push the result back onto the stack
            int top = scores.top();
            scores.push(top * 2);
        } else if (op == 'C') {
            // Pop the top element from the stack to invalidate the previous score
            scores.pop();
        }
    }

    // // Calculate the sum of all elements in the stack
    // initialize sum to 0
    // while stack is not empty:
    //     pop an element from the stack and add it to the sum

    int sum = 0;
    while (!scores.empty()) {
        sum += scores.top();
        scores.pop();
    }

    // Return the sum
    return sum;
}

int main() {
    // Test cases
    cout << "Test 1: " << baseballScore("52CD+") << endl; // Expected output: 30
    cout << "Test 2: " << baseballScore("524CD9++") << endl; // Expected output: 55

    return 0;
}