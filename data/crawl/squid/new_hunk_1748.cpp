}

void
DelayTaggedBucket::stats(StoreEntry *entry) const
{
    storeAppendPrintf(entry, " " SQUIDSTRINGPH ":", SQUIDSTRINGPRINT(tag));
    theBucket.stats(entry);
}

DelayTagged::Id::Id(DelayTagged::Pointer aDelayTagged, String &aTag) : theTagged(aDelayTagged)