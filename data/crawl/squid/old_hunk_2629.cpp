void
Rock::SwapDir::parseSize()
{
    max_size = GetInteger() << 10; // MBytes to KBytes
    if (max_size < 0)
        fatal("negative Rock cache_dir size value");
}

/// check the results of the configuration; only level-0 debugging works here
