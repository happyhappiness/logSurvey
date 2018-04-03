
    case GOPHER_BIN:
        /* Rightnow We have no idea what it is. */
        gopher_mime_content(&mb, gopherState->request, def_gopher_bin);
        break;

    case GOPHER_FILE:

    default:
        gopher_mime_content(&mb, gopherState->request, def_gopher_text);
        break;
    }

    mb.Printf("\r\n");
    EBIT_CLR(gopherState->entry->flags, ENTRY_FWD_HDR_WAIT);
    gopherState->entry->append(mb.buf, mb.size);
    mb.clean();
}

/**
