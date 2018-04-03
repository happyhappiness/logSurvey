            break;
#endif
        case 'd':
            debug_mode++;
            break;
        default:
            fprintf(stderr, PROGRAM_NAME ": ERROR: Unknown command line option '%c'\n", option);
