#include <iostream>
#include <iomanip>
using namespace std;


struct stack_t {
    int *arr;
    int N;
    int MAX_N;
};

void init(stack_t &, const int);
bool push(stack_t &, const int);
bool pop(stack_t &, int &);

typedef stack_t peg_t;

void move(peg_t &, peg_t &);
void hanoi(int, peg_t &, peg_t &, peg_t &);
void output_hanoi(const peg_t, const peg_t, const peg_t);


int main() {

    const int MAX_N = 5;    

    peg_t s, d, a;
    
    init(s, MAX_N);
    init(d, MAX_N);
    init(a, MAX_N);
    
    for(int i=MAX_N; i>0; i--) {
        push(s, i);
        d.arr[i-1] = a.arr[i-1] = 0;
    }

    output_hanoi(s, d, a);
    hanoi(MAX_N, s, d, a);
    output_hanoi(s, d, a);
    
    return 0;
    
}

void init(stack_t &stack, const int MAX_N) {
    stack.arr = new int[MAX_N];
    stack.MAX_N = MAX_N;
    stack.N = 0;
}

bool push(stack_t &stack, const int value) {
    int N = stack.N;
    int MAX_N = stack.MAX_N;
    if(N == MAX_N)
        return false;
    stack.arr[N] = value;
    stack.N++;
    return true;
}

bool pop(stack_t &stack, int &top_value) {
    int N = stack.N;
    if(N == 0)
        return false;
    top_value = stack.arr[N-1];
    stack.N--;
    return true;
}

void move(peg_t &s, peg_t &d) {
    int value;
    pop(s, value);
    s.arr[s.N] = 0;
    push(d, value);
}

void hanoi(int N, peg_t &s, peg_t &d, peg_t &a) {
    if(N == 1) {
        move(s, d);
        return;
    }
    hanoi(N-1, s, a, d);
    move(s, d);
    hanoi(N-1, a, d, s);
}

void output_hanoi(const peg_t s, const peg_t d, const peg_t a) {
    cout << setw(3) << 's';
    cout << setw(3) << 'd';
    cout << setw(3) << 'a';
    cout << endl;
    for(int i=s.MAX_N-1; i>=0; i--) {
        cout << setw(3) << s.arr[i];
        cout << setw(3) << d.arr[i];
        cout << setw(3) << a.arr[i];
        cout << endl;
    }
}