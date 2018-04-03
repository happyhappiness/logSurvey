void
CossSwapDir::reconfigure(int index, char *path)
{
    const int i = GetInteger();
    if (i <= 0)
        fatal("storeCossDirParse: invalid size value");

    const uint64_t size = static_cast<uint64_t>(i) << 20; // MBytes to Bytes

    if (size == maxSize())
        debugs(3, 1, "Cache COSS dir '" << path << "' size remains unchanged at " << i << " MB");
    else {
        debugs(3, 1, "Cache COSS dir '" << path << "' size changed to " << i << " MB");
        max_size = size;
    }

