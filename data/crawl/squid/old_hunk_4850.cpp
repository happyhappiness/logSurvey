     *
     *    Fragm = (alloced - (inuse / obj_ch) ) / alloced
     */

    storeAppendPrintf(e,
                      "%d\t %ld\t %ld\t %.2f\t %.1f\t"	/* alloc */
                      "%d\t %ld\t %ld\t %.2f\t %.1f\t"	/* in use */
                      "%d\t %ld\t %ld\t"	/* idle */
                      "%.0f\t %.1f\t %.1f\t %.1f\n",	/* saved */
                      /* alloc */
                      mp_st->items_alloc,
                      (long) toKB(mp_st->obj_size * pm->alloc.level),
                      (long) toKB(mp_st->obj_size * pm->alloc.hwater_level),
                      (double) ((squid_curtime - pm->alloc.hwater_stamp) / 3600.),
                      xpercent(mp_st->obj_size * pm->alloc.level, AllMeter->alloc.level),
                      /* in use */
                      mp_st->items_inuse,
                      (long) toKB(mp_st->obj_size * pm->inuse.level),
                      (long) toKB(mp_st->obj_size * pm->inuse.hwater_level),
                      (double) ((squid_curtime - pm->inuse.hwater_stamp) / 3600.),
                      xpercent(pm->inuse.level, pm->alloc.level),
                      /* idle */
                      mp_st->items_idle,
                      (long) toKB(mp_st->obj_size * pm->idle.level),
                      (long) toKB(mp_st->obj_size * pm->idle.hwater_level),
                      /* saved */
                      pm->gb_saved.count,
                      xpercent(pm->gb_saved.count, AllMeter->gb_saved.count),
                      xpercent(pm->gb_saved.bytes, AllMeter->gb_saved.bytes),
                      xdiv(pm->gb_saved.count - pm->gb_osaved.count, xm_deltat));
    pm->gb_osaved.count = pm->gb_saved.count;
}

