                                     &answers,
                                     &rid);
            if (n < 0) {
                printf("ERROR %d\n", -n);
            } else if (rid != sid) {
                printf("ERROR, ID mismatch (%#hx, %#hx)\n", sid, rid);
            } else {
