		default:
		    fatalf("bad return value from commDeferRead(FD %d)\n", fd);
		}
		if (FD_ISSET(fd, &readfds) && fd_table[fd].flags.read_pending) {
		    FD_SET(fd, &pendingfds);
		    pending++;
		}
	    }
	}
#if DEBUG_FDBITS
