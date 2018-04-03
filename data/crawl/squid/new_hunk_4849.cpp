        excess = mp_st->chunks_inuse - needed;
    }

    stream << std::setw(4) << mp_st->chunks_alloc << "\t ";
    stream << std::setw(4) << mp_st->chunks_inuse << "\t ";
    stream << std::setw(4) << mp_st->chunks_free << "\t ";
    stream << std::setw(4) << mp_st->chunks_partial << "\t ";
    stream << std::setprecision(1) << xpercent(excess, needed) << "\t ";
    /*
     *  Fragmentation calculation:
     *    needed = inuse.level / chunk_capacity
