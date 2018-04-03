    } else {
        debug(79, 1) ("storeDiskdSend: msgsnd: %s\n", xstrerror());
        cbdataReferenceDone(M.callback_data);

        if (++send_errors > 100)
            fatal ("over 100 errors sending to the daemon - aborting\n");
    }

    /*
