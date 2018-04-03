        packerToMemInit(&pck, &str);
        request->header.packInto(&pck);
        packerClean(&pck);
    }

    str.Printf("\r\n");
