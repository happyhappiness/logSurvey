      eta_min = eta / 60,   eta %= 60;
      eta_sec = eta;

      /*printf ("\neta: %d, %d %d %d\n", eta, eta_hrs, eta_min, eta_sec);*/
      /*printf ("\n%ld %f %ld %ld\n", dltime, tm_sofar, bytes_remaining, bp->count);*/

      *p++ = ' ';
      *p++ = 'E';
      *p++ = 'T';
      *p++ = 'A';
      *p++ = ' ';

      if (eta_hrs > 99)
	/* Bogus value, for whatever reason.  We must avoid overflow. */
	sprintf (p, "--:--");
      else if (eta_hrs > 0)
	sprintf (p, "%d:%02d:%02d", eta_hrs, eta_min, eta_sec);
