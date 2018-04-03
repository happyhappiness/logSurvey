}

void
cacheDigestGuessStatsReport(const cd_guess_stats * stats, StoreEntry * sentry, const char *label)
{
    const int true_count = stats->true_hits + stats->true_misses;
    const int false_count = stats->false_hits + stats->false_misses;
    const int hit_count = stats->true_hits + stats->false_hits;
    const int miss_count = stats->true_misses + stats->false_misses;
    const int tot_count = true_count + false_count;

    assert(label);
    assert(tot_count == hit_count + miss_count);	/* paranoid */

    storeAppendPrintf(sentry, "Digest guesses stats for %s:\n", label);
    storeAppendPrintf(sentry, "guess\t hit\t\t miss\t\t total\t\t\n");
