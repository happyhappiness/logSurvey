a_file_write(async_queue_t *q, int fd, off_t offset, void *buf, int len,
  DWCB *callback, void *data, FREE *freefunc)
{
	assert(q->aq_state == AQ_STATE_SETUP);

	file_write(fd, offset, buf, len, callback, data, freefunc);
	/* Find a free slot */
		/* No free slot? Callback error, and return */
	/* Mark slot as ours */
	/* Initiate aio */
}


