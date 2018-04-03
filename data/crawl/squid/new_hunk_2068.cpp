        fatal("UFSSwapDir::parseSizeL1L2: invalid level 2 directories value");
}

void
Fs::Ufs::UFSSwapDir::reconfigure()
{
    parseSizeL1L2();
    parseOptions(1);
}

void
Fs::Ufs::UFSSwapDir::parse (int anIndex, char *aPath)
{
    index = anIndex;
    path = xstrdup(aPath);
