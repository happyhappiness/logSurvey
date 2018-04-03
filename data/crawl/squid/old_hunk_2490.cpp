            assert(0);		/* should never get here */
            break;
        }
    }

    if (state != sEXIT) {
        printf("Error unexpected EOF\n");
        exit(1);
    } else {
        /* reverse order of entries */
