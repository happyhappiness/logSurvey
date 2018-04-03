void
UFSSwapDir::parseSizeL1L2()
{
    int i;
    int size;

    i = GetInteger();
    size = i << 10;		/* Mbytes to kbytes */

    if (size <= 0)
        fatal("UFSSwapDir::parseSizeL1L2: invalid size value");

    /* just reconfigure it */
    if (reconfiguring) {
        if (size == max_size)
