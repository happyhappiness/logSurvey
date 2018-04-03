    dup2(t, 2);

    while (fgets(buf, LOGFILE_BUF_LEN, stdin)) {
        /* First byte indicates what we're logging! */
        switch (buf[0]) {
        case 'L':
            if (buf[1] != '\0') {
                fprintf(fp, "%s", buf + 1);
            }
            if (!do_buffer)
                fflush(fp);
            break;
        case 'R':
            fclose(fp);
            rotate(argv[1], rotate_count);
            fp = fopen(argv[1], "a");
            if (fp == NULL) {
                perror("fopen");
                exit(1);
            }
            break;
        case 'T':
            break;
        case 'O':
            break;
        case 'r':
            //fprintf(fp, "SET ROTATE: %s\n", buf + 1);
            rotate_count = atoi(buf + 1);
            break;
        case 'b':
            //fprintf(fp, "SET BUFFERED: %s\n", buf + 1);
            do_buffer = (buf[1] == '1');
            break;
        case 'F':
            fflush(fp);
            break;
        default:
            /* Just in case .. */
            fprintf(fp, "%s", buf);
            break;
        }
    }
    fclose(fp);
    fp = NULL;
