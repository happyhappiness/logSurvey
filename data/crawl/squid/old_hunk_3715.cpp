        debugs(93,5, HERE << "echoed " << size << " out of " << sizeMax <<
               " bytes");
        virginBodySending.progress(size);
        virginConsume();
        disableRepeats("echoed content");
        disableBypass("echoed content");
    }

    if (virginBodyEndReached(virginBodySending)) {
