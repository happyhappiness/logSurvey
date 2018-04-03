            /* Special case.. hex specification */
            value = strtol(option + 2, NULL, 16);
        } else {
            fatalf("Unknown TLS option '%s'", option);
            value = 0;      /* Keep GCC happy */
        }

