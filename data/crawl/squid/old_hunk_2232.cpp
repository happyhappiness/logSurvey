    }

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        /*
         * The above writeReplyBody() call could ABORT this entry,
         * in that case, the server FD should already be closed.
         * there's nothing for us to do.
         */
        (void) 0;
    } else
        switch (persistentConnStatus()) {
        case INCOMPLETE_MSG: {
