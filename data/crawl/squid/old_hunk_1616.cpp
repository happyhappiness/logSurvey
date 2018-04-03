        CBDataDumper::operator()(x);
        storeAppendPrintf(where, "\n");
        storeAppendPrintf(where, "Action\tFile\tLine\n");
        for_each (x.calls,callDumper);
        storeAppendPrintf(where, "\n");
    }
