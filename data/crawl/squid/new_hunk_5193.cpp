        /* fallthrough */

    case STREAM_FAILED:
        initiateClose();
        return;

    default:
