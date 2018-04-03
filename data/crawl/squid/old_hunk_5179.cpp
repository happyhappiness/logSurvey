    } else {
        debug(79, 1) ("storeDiskdSend: msgsnd: %s\n", xstrerror());
        cbdataReferenceDone(M.callback_data);
        assert(++send_errors < 100);
    }

    /*
