    case STREAM_UNPLANNED_COMPLETE:
	/* fallthrough */
    case STREAM_FAILED:
	comm_close(fd);
	return;
    default:
	fatal("Hit unreachable code in clientWriteComplete\n");
