a_file_read(async_queue_t *q, int fd, void *buf, int req_len, off_t offset,
  DRCB *callback, void *data)
{
	assert(q->aq_state == AQ_STATE_SETUP);

#if 0
	file_read(fd, buf, req_len, offset, callback, data);
#endif
	/* Find a free slot */
		/* No free slot? Callback error, and return */

	/* Mark slot as ours */
	/* Initiate aio */
}


