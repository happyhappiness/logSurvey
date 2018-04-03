} intnode;

int
compareint(void const *a, void const *n)
{
    intnode *A = (intnode *)a;
    intnode *B = (intnode *)n;
    //((splayNode *)n)->data;
    return A->i - B->i;
}

void
printint(void *a, void *state)
{
    intnode *A = (intnode *)a;
    printf("%d\n", A->i);
}

int
main(int argc, char *argv[])
{
    int i;
    intnode *I;
    splayNode *top = NULL;
    srandom(time(NULL));
    for (i = 0; i < 100; i++) {
	I = (intnode *)xcalloc(sizeof(intnode), 1);
	I->i = random();
	top = splay_insert(I, top, compareint);
    }
    splay_walk(top, printint, NULL);
    return 0;
}