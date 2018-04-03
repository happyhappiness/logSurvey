#include "Store.h"

DelaySpec::DelaySpec() : restore_bps(-1), max_bytes (-1)
{}

void
DelaySpec::stats (StoreEntry * sentry, char const *label) const
{
    if (restore_bps == -1) {
        storeAppendPrintf(sentry, "\t%s:\n\t\tDisabled.\n\n", label);
        return;
    }

    storeAppendPrintf(sentry, "\t%s:\n", label);
    storeAppendPrintf(sentry, "\t\tMax: %d\n", max_bytes);
    storeAppendPrintf(sentry, "\t\tRestore: %d\n", restore_bps);
