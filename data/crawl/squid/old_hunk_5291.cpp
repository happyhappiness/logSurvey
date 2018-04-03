            events = 0;
            /* Check each open socket for a handler. */

            if (fd_table[i].read_handler) {
                switch (commDeferRead(i)) {

                case 0:
                    events |= POLLRDNORM;
                    break;

                case 1:
                    break;
#if DELAY_POOLS

                case -1:
                    events |= POLLRDNORM;
                    FD_SET(i, &slowfds);
                    break;
#endif

                default:
                    fatalf("bad return value from commDeferRead(FD %d)\n", i);
                }
            }

            if (fd_table[i].write_handler)
                events |= POLLWRNORM;
