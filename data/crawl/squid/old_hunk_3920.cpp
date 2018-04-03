void
DelayTaggedBucket::stats (StoreEntry *entry) const
{
    storeAppendPrintf(entry, " %s:", tag.buf());
    theBucket.stats (entry);
}

