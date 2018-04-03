      eta_min = eta / 60,   eta %= 60;
      eta_sec = eta;

      /* Pad until the end of screen.  The padding is dependent on the
	 hour value.  */
      if (eta_hrs == 0 || eta_hrs > 99)
	/* Hours not printed: pad with three spaces (two digits and
	   colon). */
	APPEND_LITERAL ("   ");
      else if (eta_hrs >= 10)
	/* Hours printed with one digit: pad with one space. */
	*p++ = ' ';
      else
	/* Hours printed with two digits: we're using maximum width,
	   don't pad. */
	;

      APPEND_LITERAL (" ETA ");

      if (eta_hrs > 99)
	/* Bogus value, probably due to a calculation overflow.  Print
	   something safe to avoid overstepping the buffer bounds. */
	sprintf (p, "--:--");
      else if (eta_hrs > 0)
	sprintf (p, "%d:%02d:%02d", eta_hrs, eta_min, eta_sec);
