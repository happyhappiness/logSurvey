/* MemPoolMeter */

void
Mem::PoolReport(const MemPoolStats * mp_st, const MemPoolMeter * AllMeter, std::ostream &stream)
{
    int excess = 0;
    int needed = 0;
    MemPoolMeter *pm = mp_st->meter;

    stream << std::setw(20) << std::left << mp_st->label;
    stream << "\t " << std::setw(4) << std::right;
    stream << mp_st->obj_size;

    /* Chunks */
    stream << "\t " << std::setw(4);
    stream << toKB(mp_st->obj_size * mp_st->chunk_capacity);
    stream << "\t " << std::setw(4) << mp_st->chunk_capacity;
    stream << "\t ";

    if (mp_st->chunk_capacity) {
        needed = mp_st->items_inuse / mp_st->chunk_capacity;
