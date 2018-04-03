    sd->freeSlots->push(pageId);
}

/// freeSlot() for never-been-mapped slots
void
Rock::Rebuild::freeUnusedSlot(const SlotId slotId, const bool invalid)
{
    LoadingSlot slot = loadingSlot(slotId);
    // mapped slots must be freed via freeBadEntry() to keep the map in sync
    assert(!slot.mapped());
    freeSlot(slotId, invalid);
}

/// adds slot to the entry chain in the map
void
Rock::Rebuild::mapSlot(const SlotId slotId, const DbCellHeader &header)
{
    LoadingSlot slot = loadingSlot(slotId);
    assert(!slot.mapped());
    assert(!slot.freed());
    slot.mapped(true);

    Ipc::StoreMapSlice slice;
    slice.next = header.nextSlot;
    slice.size = header.payloadSize;
    sd->map->importSlice(slotId, slice);
}

template <class SlotIdType> // accommodates atomic and simple SlotIds.
void
Rock::Rebuild::chainSlots(SlotIdType &from, const SlotId to)
{
    LoadingSlot slot = loadingSlot(to);
    assert(slot.more < 0);
    slot.more = from; // may still be unset
    from = to;
}

/// adds slot to an existing entry chain; caller must check that the slot
/// belongs to the chain it is being added to
void
Rock::Rebuild::addSlotToEntry(const sfileno fileno, const SlotId slotId, const DbCellHeader &header)
{
    LoadingEntry le = loadingEntry(fileno);
    Ipc::StoreMapAnchor &anchor = sd->map->writeableEntry(fileno);

    debugs(47,9, "adding " << slotId << " to entry " << fileno);
    // we do not need to preserve the order
    if (le.anchored()) {
        LoadingSlot inode = loadingSlot(anchor.start);
        chainSlots(inode.more, slotId);
    } else {
        chainSlots(anchor.start, slotId);
    }

    le.size += header.payloadSize; // must precede freeBadEntry() calls

    if (header.firstSlot == slotId) {
        debugs(47,5, "added inode");

        if (le.anchored()) { // we have already added another inode slot
            freeBadEntry(fileno, "inode conflict");
            ++counts.clashcount;
            return;
        }

        le.anchored(true);

        if (!importEntry(anchor, fileno, header)) {
            freeBadEntry(fileno, "corrupted metainfo");
            return;
        }

        // set total entry size and/or check it for consistency
        if (const uint64_t totalSize = header.entrySize) {
            assert(totalSize != static_cast<uint64_t>(-1));
            if (!anchor.basics.swap_file_sz) {
                anchor.basics.swap_file_sz = totalSize;
                assert(anchor.basics.swap_file_sz != static_cast<uint64_t>(-1));
            } else if (totalSize != anchor.basics.swap_file_sz) {
                freeBadEntry(fileno, "size mismatch");
                return;
            }
        }
    }

    const uint64_t totalSize = anchor.basics.swap_file_sz; // may be 0/unknown

    if (totalSize > 0 && le.size > totalSize) { // overflow
        debugs(47, 8, "overflow: " << le.size << " > " << totalSize);
        freeBadEntry(fileno, "overflowing");
        return;
    }

    mapSlot(slotId, header);
    if (totalSize > 0 && le.size == totalSize)
        finalizeOrFree(fileno, le); // entry is probably fully loaded now
}

/// initialize housekeeping information for a newly accepted entry
