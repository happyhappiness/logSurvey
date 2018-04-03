        break;

    case STREAM_COMPLETE:
        debugs(33, 5, HERE << conn << " Keeping Alive");
        keepaliveNextRequest();
        return;

    case STREAM_UNPLANNED_COMPLETE: