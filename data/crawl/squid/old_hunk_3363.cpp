                                 &rid);

        if (n < 0) {
            printf("ERROR %d\n", rfc1035_errno);
        } else if (rid != sid && rid != sidb) {
            printf("ERROR, ID mismatch (%#hx, %#hx)\n", sid, rid);
            printf("ERROR, ID mismatch (%#hx, %#hx)\n", sidb, rid);
