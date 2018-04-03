        /* fallthrough */

    case STREAM_FAILED:
        comm_close(fd);
        return;

    default:
