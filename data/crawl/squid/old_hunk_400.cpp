        return;
    case STREAM_COMPLETE:
        debugs(33, 3, "FTP reply data transfer successfully complete");
        writeCustomReply(226, "Transfer complete");
        break;
    case STREAM_UNPLANNED_COMPLETE:
        debugs(33, 3, "FTP reply data transfer failed: STREAM_UNPLANNED_COMPLETE");
        writeCustomReply(451, "Server error; transfer aborted");
        break;
    case STREAM_FAILED:
        debugs(33, 3, "FTP reply data transfer failed: STREAM_FAILED");
        writeCustomReply(451, "Server error; transfer aborted");
        break;
    default:
        fatal("unreachable code");
    }

    closeDataConnection();
}

void
