#include <bits/stdc++.h>
using namespace std;
typedef struct Stack
{
    int value;
    int top;
    int *arr;
} Stack_Node;

Stack_Node *Create_stack(int value)
{
    Stack_Node *stack = new Stack;
    stack->value = value;
    stack->top = -1;
    stack->arr = new int[value];
    return stack;
}
 
bool CHECK_ISFull(Stack_Node *stack)
{
    if (stack->top == stack->value - 1)
        return true;
    else
        return false;
}

 
bool CHECK_EMPTY(Stack_Node *stack)
{
    if (stack->top == -1)
        return true;
    else
        return false;
}

void push(Stack_Node *stack, int element)
{
    if (CHECK_ISFull(stack))
        return;

    stack->arr[++stack->top] = element;
}
 
int pop(Stack_Node *stack)
{
    if (CHECK_EMPTY(stack))
        return -1;

    return (stack->arr[stack->top--]);
}

 
void MOVE_DISC(int disc, char from_Rod, char to_Rod)

{

    cout << "Move the disc " << disc << " "
         << "from Rod '" << from_Rod << "' to Rod '" << to_Rod << "'" << endl;
}

void MOVE_DISC_Helper(struct Stack *source, struct Stack *dest, char s, char d)
{
    int top1 = pop(source);
    int top2 = pop(dest);
    if (top1 == -1)
    {
        push(source, top2);
        MOVE_DISC(top2, d, s);
    }
    else if (top2 == -1)

    {
        push(dest, top1);
        MOVE_DISC(top1, s, d);
    }
    else if (top1 > top2)
    {
        push(source, top1);
        push(source, top2);
        MOVE_DISC(top2, d, s);
    }
    else
    {
        push(dest, top2);
        push(dest, top1);
        MOVE_DISC(top1, s, d);
    }
}

void TOWER_Of_HANOI(int number_of_discs, struct Stack *source, struct Stack *aux, struct Stack *dest)

{
    char s = 'S', d = 'D', a = 'A';

    //  if n is even swap aux and dest
    if (number_of_discs % 2 == 0)
    {
        char var = d;
        d = a;
        a = var;
    }

    int number_of_moves = pow(2, number_of_discs) - 1;
    for (int i = number_of_discs; i >= 1; i--)
    {
        push(source, i);
    }

    // iteration of each i upto number of moves
    for (int i = 1; i <= number_of_moves; i++)
    {
        if (i % 3 == 0)
            MOVE_DISC_Helper(aux, dest, a, d);
        else if (i % 3 == 2)
            MOVE_DISC_Helper(source, aux, s, a);
        else if (i % 3 == 1)
            MOVE_DISC_Helper(source, dest, s, d);
    }
}

int main()

{
    int number_of_discs;
    cin >> number_of_discs;

    Stack_Node *source;
    Stack_Node *dest;
    Stack_Node *aux;

    
    source = Create_stack(number_of_discs);
    aux = Create_stack(number_of_discs);
    dest = Create_stack(number_of_discs);

    TOWER_Of_HANOI(number_of_discs, source, aux, dest);

    
    delete source;
    delete aux;
    delete dest;
    return 0;
}
