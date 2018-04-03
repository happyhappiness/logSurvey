            ::no_fork = ! ::no_fork;
            break;
        case 'p':
            colon = strchr( optarg, ':' );
            if ( colon == 0 ) {
                // no colon, only look at host
