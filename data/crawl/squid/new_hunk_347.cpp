    } else {
        // A new from-network entry is occupying our map slot; let it be, but
        // save us from the trouble of going through the above motions again.
        LoadingEntry le = loadingEntry(fileno);
        le.state(LoadingEntry::leIgnored);
        freeUnusedSlot(slotId, false);
    }
}

/// does the header belong to the fileno entry being loaded?
bool
Rock::Rebuild::sameEntry(const sfileno fileno, const DbCellHeader &header) const
{
    // Header updates always result in multi-start chains and often
    // result in multi-version chains so we can only compare the keys.
    const Ipc::StoreMap::Anchor &anchor = sd->map->writeableEntry(fileno);
    return anchor.sameKey(reinterpret_cast<const cache_key*>(header.key));
}

/// handle freshly loaded (and validated) db slot header
void
Rock::Rebuild::useNewSlot(const SlotId slotId, const DbCellHeader &header)
{
    const cache_key *const key =
        reinterpret_cast<const cache_key*>(header.key);
    const sfileno fileno = sd->map->fileNoByKey(key);
    assert(0 <= fileno && fileno < dbEntryLimit);

    LoadingEntry le = loadingEntry(fileno);
    debugs(47,9, "entry " << fileno << " state: " << le.state() << ", inode: " <<
           header.firstSlot << ", size: " << header.payloadSize);

    switch (le.state()) {

    case LoadingEntry::leEmpty: {
        startNewEntry(fileno, slotId, header);
        break;
    }

    case LoadingEntry::leLoading: {
        if (sameEntry(fileno, header)) {
            addSlotToEntry(fileno, slotId, header); // may fail
        } else {
            // either the loading chain or this slot is stale;
            // be conservative and ignore both (and any future ones)
            freeBadEntry(fileno, "duplicated");
            freeUnusedSlot(slotId, true);
            ++counts.dupcount;
        }
        break;
