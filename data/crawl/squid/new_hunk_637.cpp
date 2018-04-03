                fprintf( stderr, "%c requires a regex pattern argument!\n", option );
                exit(1);
            }
            try { // std::regex constructor throws on pattern errors
                if (!head)
                    tail = head = new REList( optarg, option=='E' );
                else {
                    tail->next = new REList( optarg, option=='E' );
                    tail = tail->next;
                }
            } catch (std::regex_error &e) {
                fprintf(stderr, "%c contains invalid regular expression: %s\n", option, optarg);
                exit(1);
            }
            break;

