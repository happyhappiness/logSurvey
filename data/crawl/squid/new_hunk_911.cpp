            mustStop("pconn race");
            return;
        }

        break;

        // case Comm::COMM_ERROR:
    default: // no other flags should ever occur
        debugs(11, 2, io.conn << ": read failure: " << xstrerr(rd.xerrno));
        mustStop("unknown ICAP I/O read error");
        return;
    }

    handleCommRead(io.size);
