	    storeAppendPrintf(s, "\tFD %d, read %d, wrote %d\n", fd,
		fd_table[fd].bytes_read, fd_table[fd].bytes_written);
	    storeAppendPrintf(s, "\tFD desc: %s\n", fd_table[fd].desc);
	    storeAppendPrintf(s, "\tin: buf %p, offset %d, size %d\n",
		conn->in.buf, conn->in.offset, conn->in.size);
	    storeAppendPrintf(s, "\tpeer: %s:%d\n",
		inet_ntoa(conn->peer.sin_addr),
		ntohs(conn->peer.sin_port));
