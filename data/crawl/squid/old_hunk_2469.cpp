    max_size = static_cast<uint64_t>(i) << 20; // MBytes to Bytes
}

/// check the results of the configuration; only level-0 debugging works here
void
Rock::SwapDir::validateOptions()
