int
a_file_callback(async_queue_t *q)
{
	assert(q->aq_state == AQ_STATE_SETUP);

	/* Loop through all slots */
		/* Active, get status */
			/* Ready? Grab the state locally */
			/* Free the state */
			/* Call callback */


	return 0;
}


