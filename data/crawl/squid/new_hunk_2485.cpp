                char *name, *aliasname;

                if ((name = strtok(buff + 5, WS)) == NULL) {
                    std::cerr << "Error in input file\n";
                    exit(1);
                }

