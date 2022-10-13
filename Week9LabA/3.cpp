#include <bits/stdc++.h>

struct node
{
    char info;
    struct node *l;
    struct node *r;
    struct node *nxt;
};
struct node *head = NULL;

struct node *newnode(char data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->info = data;
    node->l = NULL;
    node->r = NULL;
    node->nxt = NULL;
    return (node);
}
void Inorder(struct node *node)
{
    if (node == NULL)
        return;
    else
    {

        Inorder(node->l);

        printf("%c ", node->info);

        Inorder(node->r);
    }
}

void push(struct node *x)
{
    if (head == NULL)
        head = x;
    else
    {
        (x)->nxt = head;
        head = x;
    }
}
struct node *pop()
{

    struct node *n = head;
    head = head->nxt;
    return n;
}
int main()
{
    char t[] = {'X', 'Y', 'Z', '*', '+', 'W', '/'};
    int n = sizeof(t) / sizeof(t[0]);
    int i;
    struct node *p, *q, *s;
    for (i = 0; i < n; i++)
    {

        if (t[i] == '+' || t[i] == '-' || t[i] == '*' || t[i] == '/' || t[i] == '^')
        {
            s = newnode(t[i]);
            p = pop();
            q = pop();
            s->l = q;
            s->r = p;
            push(s);
        }
        else
        {
            s = newnode(t[i]);
            push(s);
        }
    }
    printf(" The Inorder Traversal of Expression Tree: ");
    Inorder(s);
    return 0;
}