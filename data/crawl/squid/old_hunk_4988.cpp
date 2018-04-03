    case GOPHER_WWW:

    case GOPHER_CSO:
        memBufPrintf(&mb, "Content-Type: text/html\r\n");
        break;

    case GOPHER_GIF:

    case GOPHER_IMAGE:

    case GOPHER_PLUS_IMAGE:
        memBufPrintf(&mb, "Content-Type: image/gif\r\n");
        break;

    case GOPHER_SOUND:

    case GOPHER_PLUS_SOUND:
        memBufPrintf(&mb, "Content-Type: audio/basic\r\n");
        break;

    case GOPHER_PLUS_MOVIE:
        memBufPrintf(&mb, "Content-Type: video/mpeg\r\n");
        break;

    case GOPHER_MACBINHEX:
