                                     &answers,
                                     &rid);
            if (n < 0) {
                printf("ERROR %d\n", rfc1035_errno);
            } else if (rid != sid) {
                printf("ERROR, ID mismatch (%#hx, %#hx)\n", sid, rid);
            } else {
