        /* yes, fall through, we do not want to loose the first line */

        case isBody:
        {
            /* interpret [and reformat] cache response */
            MemBuf out;
            out.init();
            if (parse_menu)
                munge_menu_line(out, buf, req);
            else
                munge_other_line(out, buf, req);

            fputs(out.buf, stdout);
        }
        break;

        case isForward:
            /* forward: no modifications allowed */