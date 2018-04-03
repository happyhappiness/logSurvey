
    case SENT_EPSV_1: /* EPSV options exhausted. Try PASV now. */
        debugs(9, 5, "FTP Channel (" << ctrl.conn->remote << ") rejects EPSV connection attempts. Trying PASV instead.");
        mb.appendf("PASV%s", Ftp::crlf);
        state = SENT_PASV;
        break;

