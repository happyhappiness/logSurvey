 */

#include "squid.h"
#include "Store.h"

StoreIoStats store_io_stats;

void
StoreEntry::swapOutFileClose()
{
    fatal ("Not implemented");
}

bool
StoreEntry::swapOutAble() const
{
    fatal ("Not implemented");
    return false;
}

void
StoreEntry::swapOut()
{
    fatal ("Not implemented");
}

/* wrong stub file... */
void
