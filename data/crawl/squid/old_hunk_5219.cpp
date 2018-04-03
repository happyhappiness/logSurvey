
    return stack[0].value.integral ? 1 : 0;
}

#if TESTING
int
main ()
{
    char const *expressions[] = {
                                    "!(1==1)", "!(1!=1)", "1!=1", "!1==1", "1==1",
                                    "1 <=1","2<=1", "1 < 1", "1 < 2", "-1 < 1","!-1<1",
                                    "1>2","2>1","2>=2", "2>3", "1==1&1==1","1==1&1==0",
                                    "!('a'<='c')",
                                    "(1==1)|('abc'=='def')",
                                    "(4!=5)&(4==5)",
                                    "(1==1)|(2==3)&(3==4)",	/* should be true because of precedence */
                                    "(1 & 4)",
                                    "(\"abc\" | \"edf\")", "1==1==1",
                                };

    int i = 0;

    while (strlen (expressions[i])) {
        printf("Expr '%s' = '%s'\n", expressions[i],
               expreval (expressions[i]) ? "true" : "false");
        ++i;
    }

    return 0;
}

#endif
