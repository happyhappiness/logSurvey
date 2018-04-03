        case 'L':
            if (buf[1] != '\0') {
                fprintf(fp, "%s", buf + 1);
            }
            if (!do_buffer)
                fflush(fp);
