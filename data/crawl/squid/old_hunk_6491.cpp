	}
	cur_seq_len++;
    }
    stats->bit_count = bit_count;
    stats->bit_on_count = on_count;
    stats->bseq_len_sum = seq_len_sum;
    stats->bseq_count = seq_count;
}

void
cacheDigestReport(CacheDigest * cd, const char *label, StoreEntry * e)
{
    CacheDigestStats stats;
    assert(cd && e);
