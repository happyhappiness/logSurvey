                curr->loc = xstrdup("none");
                state = sDOC;
            } else {
                printf("Error on line %d\n", linenum);
                printf("--> %s\n", buff);
                exit(1);
            }

