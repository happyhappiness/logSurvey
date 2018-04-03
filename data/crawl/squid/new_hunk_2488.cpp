                curr->type = xstrdup(ptr);
            } else if (!strncmp(buff, "IFDEF:", 6)) {
                if ((ptr = strtok(buff + 6, WS)) == NULL) {
                    std::cerr << "Error on line " << linenum << std::endl;
                    exit(1);
                }

