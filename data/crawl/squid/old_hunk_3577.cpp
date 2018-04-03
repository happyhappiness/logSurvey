    case GOPHER_WWW:

    case GOPHER_CSO:
        mb.Printf("Content-Type: text/html\r\n");
        break;

    case GOPHER_GIF:

    case GOPHER_IMAGE:

    case GOPHER_PLUS_IMAGE:
        mb.Printf("Content-Type: image/gif\r\n");
        break;

    case GOPHER_SOUND:

    case GOPHER_PLUS_SOUND:
        mb.Printf("Content-Type: audio/basic\r\n");
        break;

    case GOPHER_PLUS_MOVIE:
        mb.Printf("Content-Type: video/mpeg\r\n");
        break;

    case GOPHER_MACBINHEX:
