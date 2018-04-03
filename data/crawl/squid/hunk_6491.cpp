 	}
 	cur_seq_len++;
     }
-    stats->bit_count = bit_count;
+    stats->bit_count = cd->mask_size * 8;
     stats->bit_on_count = on_count;
     stats->bseq_len_sum = seq_len_sum;
     stats->bseq_count = seq_count;
 }
 
 void
-cacheDigestReport(CacheDigest * cd, const char *label, StoreEntry * e)
+cacheDigestGuessStatsUpdate(cd_guess_stats *stats, int real_hit, int guess_hit)
+{
+    assert(stats);
+    if (real_hit) {
+	if (guess_hit)
+	    stats->true_hits++;
+	else
+	    stats->false_misses++;
+    } else {
+	if (guess_hit)
+	    stats->false_hits++;
+	else
+	    stats->true_misses++;
+    }
+}
+
+void
+cacheDigestGuessStatsReport(const cd_guess_stats *stats, StoreEntry * sentry, const char *label)
+{
+    const int true_count = stats->true_hits + stats->true_misses;
+    const int false_count = stats->false_hits + stats->false_misses;
+    const int hit_count = stats->true_hits + stats->false_hits;
+    const int miss_count = stats->true_misses + stats->false_misses;
+    const int tot_count = true_count + false_count;
+    
+    assert(label);
+    assert(tot_count == hit_count + miss_count); /* paranoid */
+
+    storeAppendPrintf(sentry, "Digest guesses stats for %s:\n", label);
+    storeAppendPrintf(sentry, "guess\t hit\t\t miss\t\t total\t\t\n");
+    storeAppendPrintf(sentry, " \t #\t %%\t #\t %%\t #\t %%\t\n");
+
+    storeAppendPrintf(sentry, "true\t %d\t %.2f\t %d\t %.2f\t %d\t %.2f\n",
+	stats->true_hits, xpercent(stats->true_hits, tot_count),
+	stats->true_misses, xpercent(stats->true_misses, tot_count),
+	true_count, xpercent(true_count, tot_count));
+    storeAppendPrintf(sentry, "false\t %d\t %.2f\t %d\t %.2f\t %d\t %.2f\n",
+	stats->false_hits, xpercent(stats->false_hits, tot_count),
+	stats->false_misses, xpercent(stats->false_misses, tot_count),
+	false_count, xpercent(false_count, tot_count));
+    storeAppendPrintf(sentry, "all\t %d\t %.2f\t %d\t %.2f\t %d\t %.2f\n",
+	hit_count, xpercent(hit_count, tot_count),
+	miss_count, xpercent(miss_count, tot_count),
+	tot_count, xpercent(tot_count, tot_count));
+}
+
+void
+cacheDigestReport(CacheDigest *cd, const char *label, StoreEntry * e)
 {
     CacheDigestStats stats;
     assert(cd && e);
