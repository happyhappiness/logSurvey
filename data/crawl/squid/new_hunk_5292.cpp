                /* Found a set bit */
                fd = (j * FD_MASK_BITS) + k;

                if (FD_ISSET(fd, &readfds) && fd_table[fd].flags.read_pending) {
                    FD_SET(fd, &pendingfds);
                    pending++;
