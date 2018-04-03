    case SENT_EPSV_ALL: /* EPSV ALL resulted in a bad response. Try ther EPSV methods. */
        if (ctrl.conn->local.isIPv6()) {
            debugs(9, 5, "FTP Channel is IPv6 (" << ctrl.conn->remote << ") attempting EPSV 2 after EPSV ALL has failed.");
            mb.Printf("EPSV 2%s", Ftp::crlf);
            state = SENT_EPSV_2;
            break;
        }
