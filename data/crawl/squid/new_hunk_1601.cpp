                password = getpass("WWW password: ");
#endif
            if (!password) {
                std::cerr << "ERROR: WWW password missing" << std::endl;
                exit(1);
            }
            snprintf(buf, BUFSIZ, "%s:%s", user, password);
