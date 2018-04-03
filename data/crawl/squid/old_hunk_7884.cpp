	0,
	"Ascii Port");
    if (theAsciiConnection < 0) {
	fatal("Cannot open ascii Port\n");
    }
    fdstat_open(theAsciiConnection, Socket);
    fd_note(theAsciiConnection, "HTTP (Ascii) socket");
