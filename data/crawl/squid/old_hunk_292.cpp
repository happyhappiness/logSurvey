        /* yes, fall through, we do not want to loose the first line */

        case isBody:
            /* interpret [and reformat] cache response */

            if (parse_menu)
                fputs(munge_menu_line(buf, req), stdout);
            else
                fputs(munge_other_line(buf, req), stdout);

            break;

        case isForward:
            /* forward: no modifications allowed */