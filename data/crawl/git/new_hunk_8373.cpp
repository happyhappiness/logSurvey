		case -2: /* ok but a single level -- that is fine for
			  * a match pattern.
			  */
		case -3: /* ok but ends with a pattern-match character */
			continue;
		}
		die("remote part of refspec is not a valid name in %s",