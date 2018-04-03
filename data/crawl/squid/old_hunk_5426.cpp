

#endif

#ifdef DRIVER

typedef struct {
    int i;
} intnode;

int
compareint(void *a, splayNode * n)
{
    intnode *A = a;
    intnode *B = n->data;
    return A->i - B->i;
}

void
printint(void *a, void *state)
{
    intnode *A = a;
    printf("%d\n", "", A->i);
}

main(int argc, char *argv[])
{
    int i;
    intnode *I;
    splayNode *top = NULL;
    srandom(time(NULL));
    for (i = 0; i < 100; i++) {
	I = xcalloc(sizeof(intnode), 1);
	I->i = random();
	top = splay_insert(I, top, compareint);
    }
    splay_walk(top, printint, NULL);
    return 0;
}
#endif /* DRIVER */
