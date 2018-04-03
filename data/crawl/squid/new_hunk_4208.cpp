            exit(1);
        }

        /* Send the HTTP request */
        bytesWritten = mywrite(conn, msg, strlen(msg));

        if (bytesWritten < 0) {
            perror("client: ERROR: write");
            exit(1);
        } else if ((unsigned) bytesWritten != strlen(msg)) {
            fprintf(stderr, "client: ERROR: Cannot send request?: %s\n", msg);
            exit(1);
        }

        if (put_file) {
            int x;
            lseek(put_fd, 0, SEEK_SET);
#ifdef _SQUID_MSWIN_

            while ((x = read(put_fd, buf, sizeof(buf))) > 0) {
#else

            while ((x = myread(put_fd, buf, sizeof(buf))) > 0) {
#endif
                x = mywrite(conn, buf, x);

                total_bytes += x;

                if (x <= 0)
                    break;
            }

            if (x != 0)
                fprintf(stderr, "client: ERROR: Cannot send file.\n");
        }
        /* Read the data */

#ifdef _SQUID_MSWIN_
        setmode(1, O_BINARY);

#endif

        while ((len = myread(conn, buf, sizeof(buf))) > 0) {
            fsize += len;

            if (to_stdout)
                fwrite(buf, len, 1, stdout);
        }

#ifdef _SQUID_MSWIN_
        setmode(1, O_TEXT);

#endif

        (void) close(conn);	/* done with socket */

        if (interrupted)
            break;

        if (ping) {

            struct tm *tmp;
            time_t t2s;
            long elapsed_msec;

            (void) Now(&tv2);
            elapsed_msec = tvSubMsec(tv1, tv2);
            t2s = tv2.tv_sec;
            tmp = localtime(&t2s);
            fprintf(stderr, "%d-%02d-%02d %02d:%02d:%02d [%d]: %ld.%03ld secs, %f KB/s\n",
                    tmp->tm_year + 1900, tmp->tm_mon + 1, tmp->tm_mday,
                    tmp->tm_hour, tmp->tm_min, tmp->tm_sec, i + 1,
                    elapsed_msec / 1000, elapsed_msec % 1000,
                    elapsed_msec ? (double) fsize / elapsed_msec : -1.0);

            if (i == 0 || elapsed_msec < ping_min)
                ping_min = elapsed_msec;

            if (i == 0 || elapsed_msec > ping_max)
                ping_max = elapsed_msec;

            ping_sum += elapsed_msec;

            /* Delay until next "ping_int" boundary */
            if ((loops == 0 || i + 1 < loops) && elapsed_msec < ping_int) {

                struct timeval tvs;
                long msec_left = ping_int - elapsed_msec;

                tvs.tv_sec = msec_left / 1000;
                tvs.tv_usec = (msec_left % 1000) * 1000;
                select(0, NULL, NULL, NULL, &tvs);
            }
        }
    }

    if (ping && i) {
        ping_mean = ping_sum / i;
        fprintf(stderr, "%d requests, round-trip (secs) min/avg/max = "
                "%ld.%03ld/%ld.%03ld/%ld.%03ld\n", i,
                ping_min / 1000, ping_min % 1000, ping_mean / 1000, ping_mean % 1000,
                ping_max / 1000, ping_max % 1000);
    }
    exit(0);
    /*NOTREACHED */
    return 0;
}

static int
client_comm_bind(int sock, const IPAddress &addr) {

    int res;

