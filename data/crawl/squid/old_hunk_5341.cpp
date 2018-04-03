    assert(asinfo->as_number);

    for (q = asinfo->as_number; q; q = q->next)
        storeAppendPrintf(sentry, " %d", q->i);

    storeAppendPrintf(sentry, "\n");

    return 0;
}
