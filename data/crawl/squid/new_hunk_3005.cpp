void
UFSSwapDir::parseSizeL1L2()
{
    int i = GetInteger();
    if (i <= 0)
        fatal("UFSSwapDir::parseSizeL1L2: invalid size value");

    size_t size = i << 10;		/* Mbytes to kbytes */

    /* just reconfigure it */
    if (reconfiguring) {
        if (size == max_size)
