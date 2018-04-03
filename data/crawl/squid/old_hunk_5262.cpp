    return a->i - b->i;
}

void
printintvoid(void * const &a, void *state)
{
    intnode *A = (intnode *)a;
    printf("%d\n", A->i);
}

void
printint (intnode * const &a, void *state)
{
    printf("%d\n",a->i);
}

void
