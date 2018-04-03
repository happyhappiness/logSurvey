        break;
    }

    memBufPrintf(&mb, "\r\n");
    EBIT_CLR(gopherState->entry->flags, ENTRY_FWD_HDR_WAIT);
    storeAppend(gopherState->entry, mb.buf, mb.size);
    memBufClean(&mb);
}

/* Parse a gopher request into components.  By Anawat. */
