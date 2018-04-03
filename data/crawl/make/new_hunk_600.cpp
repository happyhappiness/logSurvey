		      0,
		      TRUE,
		      DUPLICATE_SAME_ACCESS) == FALSE) {
    fatal (NILF, _("windows32_openpipe(): DuplicateHandle(In) failed (e=%ld)\n"),
	   GetLastError());

  }
