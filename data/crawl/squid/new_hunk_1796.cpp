            break;

        case 'd':
            if ( !optarg || !*optarg ) {
                fprintf( stderr, "%c expects a mask parameter. Debug disabled.\n", option );
                ::debugFlag = 0;
            } else
                ::debugFlag = (strtoul(optarg, NULL, 0) & 0xFFFFFFFF);
            break;

        case 'E':