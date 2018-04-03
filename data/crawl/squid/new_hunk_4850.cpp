     *
     *    Fragm = (alloced - (inuse / obj_ch) ) / alloced
     */
    /* allocated */
    stream << mp_st->items_alloc << "\t ";
    stream << toKB(mp_st->obj_size * pm->alloc.level) << "\t ";
    stream << toKB(mp_st->obj_size * pm->alloc.hwater_level) << "\t ";
    stream << std::setprecision(2) << ((squid_curtime - pm->alloc.hwater_stamp) / 3600.);
    stream << "\t " << std::setprecision(1) << xpercent(mp_st->obj_size * pm->alloc.level, AllMeter->alloc.level);
    /* in use */
    stream << "\t" << mp_st->items_inuse << "\t ";
    stream << toKB(mp_st->obj_size * pm->inuse.level) << "\t ";
    stream << toKB(mp_st->obj_size * pm->inuse.hwater_level) << "\t ";
    stream << std::setprecision(2) << ((squid_curtime - pm->inuse.hwater_stamp) / 3600.);
    stream << "\t " << std::setprecision(1) << xpercent(pm->inuse.level, pm->alloc.level);
    /* idle */
    stream << "\t" << mp_st->items_idle << "\t " << toKB(mp_st->obj_size * pm->idle.level);
    stream << "\t " << toKB(mp_st->obj_size * pm->idle.hwater_level) << "\t";
    /* saved */
    stream << std::setprecision(0) << pm->gb_saved.count << "\t ";
    stream << std::setprecision(1) << xpercent(pm->gb_saved.count, AllMeter->gb_saved.count);
    stream << "\t " << xpercent(pm->gb_saved.bytes, AllMeter->gb_saved.bytes) << "\t ";
    stream << xdiv(pm->gb_saved.count - pm->gb_osaved.count, xm_deltat) << "\n";
    pm->gb_osaved.count = pm->gb_saved.count;
}

