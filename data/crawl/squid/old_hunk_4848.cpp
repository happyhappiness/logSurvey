/* MemPoolMeter */

void
Mem::PoolReport(const MemPoolStats * mp_st, const MemPoolMeter * AllMeter, StoreEntry * e)
{
    int excess = 0;
    int needed = 0;
    MemPoolMeter *pm = mp_st->meter;

    storeAppendPrintf(e, "%-20s\t %4d\t ",
                      mp_st->label, mp_st->obj_size);

    /* Chunks */
    storeAppendPrintf(e, "%4d\t %4d\t ",
                      toKB(mp_st->obj_size * mp_st->chunk_capacity), mp_st->chunk_capacity);

    if (mp_st->chunk_capacity) {
        needed = mp_st->items_inuse / mp_st->chunk_capacity;
