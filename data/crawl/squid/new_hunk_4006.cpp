    if (Config.peers == NULL)
        return 0;

    assert(entry->swap_status == SWAPOUT_NONE);

    mem->start_ping = current_time;
