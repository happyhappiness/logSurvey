    dynamic_cast<SwapDir *>(INDEXSD(e->swap_dirn))->logEntry(*e, op);
}

void
SwapDir::updateSize(int64_t size, int sign)
{
