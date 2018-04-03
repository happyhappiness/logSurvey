{
    if (top->left)
	splay_walk(top->left, walkee, state);
    if (top->right)
	splay_walk(top->right, walkee, state);
    walkee(top->data, state);
}



#ifdef DRIVER

void
splay_print(splayNode * top, void (*printfunc) ())
{
    if (top == NULL)
	return;
    splay_print(top->left, printfunc);
    printfunc(top->data);
    splay_print(top->right, printfunc);
}

typedef struct {
    int i;
} intnode;
