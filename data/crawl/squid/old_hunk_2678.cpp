    return sfilenoMax;
}

int
Rock::DirMap::slotIdx(const cache_key *const key) const
{
    const uint64_t *const k = reinterpret_cast<const uint64_t *>(key);
    // TODO: use a better hash function
    return (k[0] + k[1]) % shared->limit;
}

Rock::Slot &
Rock::DirMap::slot(const cache_key *const key)
{
    return shared->slots[slotIdx(key)];
}

/// frees the slot if (b) it is waiting to be freed and (a) we can lock it
void
Rock::DirMap::freeIfNeeded(Slot &s)
{
    if (s.exclusiveLock()) {
        if (s.waitingToBeFreed == true)
            freeLocked(s);
        else
            s.releaseExclusiveLock();
    }
}

/// unconditionally frees the already exclusively locked slot and releases lock
void
Rock::DirMap::freeLocked(Slot &s)
{
    memset(s.key_, 0, sizeof(s.key_));
    memset(&s.seBasics, 0, sizeof(s.seBasics));
    s.waitingToBeFreed = false;
    s.state = Slot::Empty;
    s.releaseExclusiveLock();
    --shared->count;
    debugs(79, 5, HERE << " freed slot at " << (&s - shared->slots) <<
           " in map [" << path << ']');
}

int
Rock::DirMap::SharedSize(const int limit)
{
    return sizeof(Shared) + limit * sizeof(Slot);
}


/* Rock::Slot */

void
Rock::Slot::setKey(const cache_key *const aKey)
{
    memcpy(key_, aKey, sizeof(key_));
}

bool
Rock::Slot::checkKey(const cache_key *const aKey) const
{
    const uint32_t *const k = reinterpret_cast<const uint32_t *>(aKey);
    return k[0] == key_[0] && k[1] == key_[1] &&
           k[2] == key_[2] && k[3] == key_[3];
}


bool
Rock::Slot::sharedLock() const
{
    ++readers; // this locks new writers out
    if (state == Readable && !writers && !waitingToBeFreed)
        return true;
    --readers;
    return false;
}

bool
Rock::Slot::exclusiveLock()
{
    if (!writers++) { // we are the first writer (this locks new readers out)
        if (!readers) // there are no old readers
            return true;
	}
    --writers;
    return false;
}

void
Rock::Slot::releaseSharedLock() const
{
    assert(readers-- > 0);
}

void
Rock::Slot::releaseExclusiveLock()
{
    assert(writers-- > 0);
}

void
Rock::Slot::switchExclusiveToSharedLock()
{
    ++readers; // must be done before we release exclusive control
    releaseExclusiveLock();
}

void
Rock::Slot::updateStats(MapStats &stats) const
{
    switch (state) {
    case Readable:
        ++stats.readable;
        stats.readers += readers;
        break;
    case Writeable:
        ++stats.writeable;
        stats.writers += writers;
        break;
    case Empty:
        ++stats.empty;
        break;
    }

    if (waitingToBeFreed)
        ++stats.marked;
}


Rock::DirMap::Shared::Shared(const int aLimit): limit(aLimit), count(0)
{
}

void
Rock::StoreEntryBasics::set(const DbCellHeader &aHeader, const StoreEntry &from)
{
    assert(from.swap_file_sz > 0);
    memset(this, 0, sizeof(*this));
    header = aHeader;
    timestamp = from.timestamp;
    lastref = from.lastref;
    expires = from.expires;
    lastmod = from.lastmod;
    swap_file_sz = from.swap_file_sz;
    refcount = from.refcount;
    flags = from.flags;
}


/* MapStats */

Rock::MapStats::MapStats()
{
    memset(this, 0, sizeof(*this));
}
 
void
Rock::MapStats::dump(StoreEntry &e) const
{
    storeAppendPrintf(&e, "Available slots: %9d\n", capacity);

    if (!capacity)
        return;

    storeAppendPrintf(&e, "Readable slots:  %9d %6.2f%%\n",
        readable, (100.0 * readable / capacity));
    storeAppendPrintf(&e, "Filling slots:   %9d %6.2f%%\n",
        writeable, (100.0 * writeable / capacity));
    storeAppendPrintf(&e, "Empty slots:     %9d %6.2f%%\n",
        empty, (100.0 * empty / capacity));

    if (readers || writers) {
        const int locks = readers + writers;
        storeAppendPrintf(&e, "Readers:         %9d %6.2f%%\n",
            readers, (100.0 * readers / locks));
        storeAppendPrintf(&e, "Writers:         %9d %6.2f%%\n",
            writers, (100.0 * writers / locks));
    }

    if (readable + writeable) {
        storeAppendPrintf(&e, "Marked slots:    %9d %6.2f%%\n",
            marked, (100.0 * marked / (readable + writeable)));
    }
}
