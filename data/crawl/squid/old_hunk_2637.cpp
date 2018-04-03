    dynamic_cast<SwapDir *>(INDEXSD(e->swap_dirn))->logEntry(*e, op);
}

void
StoreController::updateSize(int64_t size, int sign)
{
    fatal("StoreController has no independent size\n");
}

void
SwapDir::updateSize(int64_t size, int sign)
{
