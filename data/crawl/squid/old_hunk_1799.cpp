            }
            break;
        case 'P':
            ::purgeMode = ( strtol( optarg, 0, 0 ) & 0x07 );
            break;
        case 's':