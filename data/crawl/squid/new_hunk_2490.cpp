            assert(0);		/* should never get here */
            break;
        }

    }

    if (state != sEXIT) {
        std::cerr << "Error: unexpected EOF\n";
        exit(1);
    } else {
        /* reverse order of entries */
