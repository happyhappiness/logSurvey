 * Called when a *new* fs is being setup.
 */
void
UFSSwapDir::parse (int anIndex, char *aPath)
{
    parseSizeL1L2();

    index = anIndex;

    path = xstrdup(aPath);

    /* Initialise replacement policy stuff */
    repl = createRemovalPolicy(Config.replPolicy);

    parseOptions(0);
}

SwapDirOption *
UFSSwapDir::getOptionTree() const
{
    SwapDirOption *parentResult = SwapDir::getOptionTree();
    SwapDirOption *ioOptions = IO->getOptionTree();

    if (!ioOptions)
        return parentResult;

    SwapDirOptionVector *result = new SwapDirOptionVector();

    result->options.push_back(parentResult);

    result->options.push_back(ioOptions);

    return result;
}

/*
