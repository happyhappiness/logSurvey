    storeAppendPrintf(e, "%2s\t %-25s\t %5s\t %6s\t %6s\n",
                      "id", "name", "#alive", "%err", "%repeat");

    // scan heaaderTable and output
    for (int j = 0; headerTable[j].name != nullptr; ++j) {
        auto stats = headerStatsTable[j];
