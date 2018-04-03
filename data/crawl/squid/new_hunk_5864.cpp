static void
storeCossDirParse(SwapDir * sd, int index, char *path)
{
    unsigned int i;
    unsigned int size;
    CossInfo *cs;

    i = GetInteger();
    size = i << 10;		/* Mbytes to Kbytes */
    if (size <= 0)
	fatal("storeCossDirParse: invalid size value");

    cs = xmalloc(sizeof(CossInfo));
    if (cs == NULL)
