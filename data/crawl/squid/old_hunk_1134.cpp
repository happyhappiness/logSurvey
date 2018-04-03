    const int tot_count = true_count + false_count;

    assert(label);
    assert(tot_count == hit_count + miss_count);	/* paranoid */

    if (!tot_count) {
        storeAppendPrintf(sentry, "no guess stats for %s available\n", label);
