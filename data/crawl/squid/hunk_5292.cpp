                 /* Found a set bit */
                 fd = (j * FD_MASK_BITS) + k;
 
-                switch (commDeferRead(fd)) {
-
-                case 0:
-                    break;
-
-                case 1:
-                    FD_CLR(fd, &readfds);
-                    break;
-#if DELAY_POOLS
-
-                case -1:
-                    FD_SET(fd, &slowfds);
-                    break;
-#endif
-
-                default:
-                    fatalf("bad return value from commDeferRead(FD %d)\n", fd);
-                }
-
                 if (FD_ISSET(fd, &readfds) && fd_table[fd].flags.read_pending) {
                     FD_SET(fd, &pendingfds);
                     pending++;
