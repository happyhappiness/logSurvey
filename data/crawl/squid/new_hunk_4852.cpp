    mp_stats.items_idle = mp_total.tot_items_idle;
    mp_stats.overhead = mp_total.tot_overhead;

    PoolReport(&mp_stats, mp_total.TheMeter, stream);

    /* Cumulative */
    stream << "Cumulative allocated volume: "<< double_to_str(buf, 64, mp_total.TheMeter->gb_saved.bytes) << "\n";
    /* overhead */
    stream << "Current overhead: " << mp_total.tot_overhead << " bytes (" <<
    std::setprecision(3) << xpercent(mp_total.tot_overhead, mp_total.TheMeter->inuse.level) << "%%)\n";
    /* limits */
    stream << "Idle pool limit: " << std::setprecision(2) << toMB(mp_total.mem_idle_limit) << " MB\n";
    /* limits */
    stream << "Total Pools created: " << mp_total.tot_pools_alloc << "\n";
    stream << "Pools ever used:     " << mp_total.tot_pools_alloc - not_used << " (shown above)\n";
    stream << "Currently in use:    " << mp_total.tot_pools_inuse << "\n";
}
