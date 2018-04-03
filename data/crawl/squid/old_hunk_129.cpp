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

