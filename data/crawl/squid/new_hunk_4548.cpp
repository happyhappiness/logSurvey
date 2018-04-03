           " bytes");
        virginBodySending.progress(size);
        virginConsume();
        disableBypass("echoed content");
    }

    if (virginBodyEndReached(virginBodySending)) {
