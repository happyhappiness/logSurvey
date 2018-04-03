    FD_ENTRY *fde = &fd_table[fd];
    if (len < 0)
	return;
    assert (type == FD_READ || type == FD_WRITE);
    if (type == FD_READ)
	fde->bytes_read += len;
    else
	fde->bytes_written += len;
}

void
