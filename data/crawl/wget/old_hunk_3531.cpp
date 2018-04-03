{
  long timer_value = wtimer_elapsed (dp->timer);
  logprintf (LOG_VERBOSE, " %s",
	     rate (bytes, timer_value - dp->last_timer_value, 1));
  dp->last_timer_value = timer_value;
}

