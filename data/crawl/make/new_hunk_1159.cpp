	     because there was no preceding target, and the line
	     might have been usable as a variable definition.
	     But now it is definitely lossage.  */
	  fatal(&fileinfo, _("commands commence before first target"));
	}
      else
	{
