
    mb.Printf("\r\n");
    EBIT_CLR(gopherState->entry->flags, ENTRY_FWD_HDR_WAIT);
    gopherState->entry->append(mb.buf, mb.size);
    mb.clean();
}

