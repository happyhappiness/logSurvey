}

void
DelayUserBucket::operator delete(void *address)
{
    DelayPools::MemoryUsed -= sizeof(DelayUserBucket);
    ::operator delete(address);
}

DelayUserBucket::DelayUserBucket(AuthUser::Pointer aUser) : authUser(aUser)
{
    debugs(77, 3, "DelayUserBucket::DelayUserBucket");
}

DelayUserBucket::~DelayUserBucket()
{
    authUser = NULL;
    debugs(77, 3, "DelayUserBucket::~DelayUserBucket");
}

void
DelayUserBucket::stats (StoreEntry *entry) const
{
    storeAppendPrintf(entry, " %s:", authUser->username());
    theBucket.stats(entry);
}

DelayUser::Id::Id(DelayUser::Pointer aDelayUser, AuthUser::Pointer aUser) : theUser(aDelayUser)
{
    theBucket = new DelayUserBucket(aUser);
    DelayUserBucket::Pointer const *existing = theUser->buckets.find(theBucket, DelayUserCmp);
