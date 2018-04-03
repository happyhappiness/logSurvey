            }
            break;
        case 'c':
            if ( !optarg || !*optarg ) {
                fprintf( stderr, "%c requires a regex pattern argument!\n", option );
                exit(1);
            }
            if ( *conffile ) xfree((void*) conffile);
            conffile = xstrdup(optarg);
            assert(conffile);
            break;

        case 'd':
            ::debugFlag = optarg ? 0 : strtoul( optarg, 0, 0 );
            break;

        case 'E':
        case 'e':
            if ( !optarg || !*optarg ) {
                fprintf( stderr, "%c requires a regex pattern argument!\n", option );
                exit(1);
            }
            if ( head == 0 )
                tail = head = new REList( optarg, option=='E' );
            else {
                tail->next = new REList( optarg, option=='E' );
                tail = tail->next;
            }
            break;

        case 'f':
            if ( !optarg || !*optarg ) {
                fprintf( stderr, "%c requires a filename argument!\n", option );
                exit(1);
            }
            if ( (rfile = fopen( optarg, "r" )) != NULL ) {
                unsigned long lineno = 0;
#define LINESIZE 512
