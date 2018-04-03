      */
 
     storeAppendPrintf(e,
-                      "%d\t %d\t %d\t %.2f\t %.1f\t"	/* alloc */
-                      "%d\t %d\t %d\t %.1f\t"	/* in use */
-                      "%d\t %d\t %d\t"	/* idle */
+                      "%d\t %ld\t %ld\t %.2f\t %.1f\t"	/* alloc */
+                      "%d\t %ld\t %ld\t %.1f\t"	/* in use */
+                      "%d\t %ld\t %ld\t"	/* idle */
                       "%.0f\t %.1f\t %.1f\t %.1f\n",	/* saved */
                       /* alloc */
                       mp_st->items_alloc,
-                      toKB(mp_st->obj_size * pm->alloc.level),
-                      toKB(mp_st->obj_size * pm->alloc.hwater_level),
+                      (long) toKB(mp_st->obj_size * pm->alloc.level),
+                      (long) toKB(mp_st->obj_size * pm->alloc.hwater_level),
                       (double) ((squid_curtime - pm->alloc.hwater_stamp) / 3600.),
                       xpercent(mp_st->obj_size * pm->alloc.level, AllMeter->alloc.level),
                       /* in use */
                       mp_st->items_inuse,
-                      toKB(mp_st->obj_size * pm->inuse.level),
-                      toKB(mp_st->obj_size * pm->inuse.hwater_level),
+                      (long) toKB(mp_st->obj_size * pm->inuse.level),
+                      (long) toKB(mp_st->obj_size * pm->inuse.hwater_level),
                       xpercent(pm->inuse.level, pm->alloc.level),
                       /* idle */
                       mp_st->items_idle,
-                      toKB(mp_st->obj_size * pm->idle.level),
-                      toKB(mp_st->obj_size * pm->idle.hwater_level),
+                      (long) toKB(mp_st->obj_size * pm->idle.level),
+                      (long) toKB(mp_st->obj_size * pm->idle.hwater_level),
                       /* saved */
                       pm->gb_saved.count,
                       xpercent(pm->gb_saved.count, AllMeter->gb_saved.count),
