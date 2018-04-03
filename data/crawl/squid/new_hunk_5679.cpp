	return xfree;
    }
}

/* MemPoolMeter */

static void
memPoolReport(const MemPoolStats * mp_st, const MemPoolMeter * AllMeter, StoreEntry * e)
{
    int excess;
    int needed = 0;
    MemPoolMeter *pm = mp_st->meter;

    storeAppendPrintf(e, "%-20s\t %4d\t ",
	mp_st->label, mp_st->obj_size);

    /* Chunks */
    storeAppendPrintf(e, "%4d\t %4d\t ",
	toKB(mp_st->obj_size * mp_st->chunk_capacity), mp_st->chunk_capacity);

    if (mp_st->chunk_capacity) {
	needed = mp_st->items_inuse / mp_st->chunk_capacity;
	if (mp_st->items_inuse % mp_st->chunk_capacity)
	    needed++;
	excess = mp_st->chunks_inuse - needed;
    }
    storeAppendPrintf(e, "%4d\t %4d\t %4d\t %4d\t %.1f\t ",
	mp_st->chunks_alloc, mp_st->chunks_inuse, mp_st->chunks_free, mp_st->chunks_partial,
	xpercent(excess, needed));
/*
 *  Fragmentation calculation:
 *    needed = inuse.level / chunk_capacity
 *    excess = used - needed
 *    fragmentation = excess / needed * 100%
 *
 *    Fragm = (alloced - (inuse / obj_ch) ) / alloced
 */

    storeAppendPrintf(e,
	"%d\t %d\t %d\t %.2f\t %.1f\t"	/* alloc */
	"%d\t %d\t %d\t %.1f\t"	/* in use */
	"%d\t %d\t %d\t"	/* idle */
	"%.0f\t %.1f\t %.1f\t %.1f\n",	/* saved */
    /* alloc */
	mp_st->items_alloc,
	toKB(mp_st->obj_size * pm->alloc.level),
	toKB(mp_st->obj_size * pm->alloc.hwater_level),
	(double) ((squid_curtime - pm->alloc.hwater_stamp) / 3600.),
	xpercent(mp_st->obj_size * pm->alloc.level, AllMeter->alloc.level),
    /* in use */
	mp_st->items_inuse,
	toKB(mp_st->obj_size * pm->inuse.level),
	toKB(mp_st->obj_size * pm->inuse.hwater_level),
	xpercent(pm->inuse.level, pm->alloc.level),
    /* idle */
	mp_st->items_idle,
	toKB(mp_st->obj_size * pm->idle.level),
	toKB(mp_st->obj_size * pm->idle.hwater_level),
    /* saved */
	pm->gb_saved.count,
	xpercent(pm->gb_saved.count, AllMeter->gb_saved.count),
	xpercent(pm->gb_saved.bytes, AllMeter->gb_saved.bytes),
	xdiv(pm->gb_saved.count - pm->gb_osaved.count, xm_deltat));
    pm->gb_osaved.count = pm->gb_saved.count;
}

void
memReport(StoreEntry * e)
{
    static char buf[64];
    static MemPoolStats mp_stats;
    static MemPoolGlobalStats mp_total;
    int not_used = 0;
    MemPoolIterator *iter;
    MemPool *pool;

    /* caption */
    storeAppendPrintf(e, "Current memory usage:\n");
    /* heading */
    storeAppendPrintf(e,
	"Pool\t Obj Size\t"
	"Chunks\t\t\t\t\t\t\t"
	"Allocated\t\t\t\t\t"
	"In Use\t\t\t\t"
	"Idle\t\t\t"
	"Allocations Saved\t\t\t"
	"Hit Rate\t"
	"\n"
	" \t (bytes)\t"
	"KB/ch\t obj/ch\t"
	"(#)\t used\t free\t part\t %%Frag\t "
	"(#)\t (KB)\t high (KB)\t high (hrs)\t %%Tot\t"
	"(#)\t (KB)\t high (KB)\t %%alloc\t"
	"(#)\t (KB)\t high (KB)\t"
	"(#)\t %%cnt\t %%vol\t"
	"(#) / sec\t"
	"\n");
    xm_deltat = current_dtime - xm_time;
    xm_time = current_dtime;

    /* Get stats for Totals report line */
    memPoolGetGlobalStats(&mp_total);

    /* main table */
    iter = memPoolIterate();
    while ((pool = memPoolIterateNext(iter))) {
	memPoolGetStats(&mp_stats, pool);
	if (!mp_stats.pool)	/* pool destroyed */
	    continue;
	if (mp_stats.pool->meter.gb_saved.count > 0)	/* this pool has been used */
	    memPoolReport(&mp_stats, mp_total.TheMeter, e);
	else
	    not_used++;
    }
    memPoolIterateDone(&iter);

    mp_stats.pool = NULL;
    mp_stats.label = "Total";
    mp_stats.meter = mp_total.TheMeter;
    mp_stats.obj_size = 1;
    mp_stats.chunk_capacity = 0;
    mp_stats.chunk_size = 0;
    mp_stats.chunks_alloc = mp_total.tot_chunks_alloc;
    mp_stats.chunks_inuse = mp_total.tot_chunks_inuse;
    mp_stats.chunks_partial = mp_total.tot_chunks_partial;
    mp_stats.chunks_free = mp_total.tot_chunks_free;
    mp_stats.items_alloc = mp_total.tot_items_alloc;
    mp_stats.items_inuse = mp_total.tot_items_inuse;
    mp_stats.items_idle = mp_total.tot_items_idle;
    mp_stats.overhead = mp_total.tot_overhead;

    memPoolReport(&mp_stats, mp_total.TheMeter, e);

    /* Cumulative */
    storeAppendPrintf(e, "Cumulative allocated volume: %s\n", double_to_str(buf, 64, mp_total.TheMeter->gb_saved.bytes));
    /* overhead */
    storeAppendPrintf(e, "Current overhead: %d bytes (%.3f%%)\n",
	mp_total.tot_overhead, xpercent(mp_total.tot_overhead, mp_total.TheMeter->inuse.level));
    /* limits */
    storeAppendPrintf(e, "Idle pool limit: %.2f MB\n", toMB(mp_total.mem_idle_limit));
    /* limits */
    storeAppendPrintf(e, "Total Pools created: %d\n", mp_total.tot_pools_alloc);
    storeAppendPrintf(e, "Pools ever used:     %d (shown above)\n",mp_total.tot_pools_alloc - not_used);
    storeAppendPrintf(e, "Currently in use:    %d\n", mp_total.tot_pools_inuse);
}
