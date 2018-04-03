		fd_table[fd].bytes_read, fd_table[fd].bytes_written);
	    storeAppendPrintf(s, "\tFD desc: %s\n", fd_table[fd].desc);
	    storeAppendPrintf(s, "\tin: buf %p, offset %ld, size %ld\n",
		conn->in.buf, (long int) conn->in.notYetUsed, (long int) conn->in.allocatedSize);
	    storeAppendPrintf(s, "\tpeer: %s:%d\n",
		inet_ntoa(conn->peer.sin_addr),
		ntohs(conn->peer.sin_port));
