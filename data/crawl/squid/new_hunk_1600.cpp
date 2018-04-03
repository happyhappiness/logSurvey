                password = getpass("Proxy password: ");
#endif
            if (!password) {
                std::cerr << "ERROR: Proxy password missing" << std::endl;
                exit(1);
            }
            snprintf(buf, BUFSIZ, "%s:%s", user, password);
