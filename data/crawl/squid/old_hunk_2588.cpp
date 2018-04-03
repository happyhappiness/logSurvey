        packerToMemInit(&pck, &str);
        request->header.packInto(&pck);
        packerClean(&pck);
    } else if (request_hdrs) {
        p = request_hdrs;
    } else {
        p = "[none]";
    }

    str.Printf("\r\n");
