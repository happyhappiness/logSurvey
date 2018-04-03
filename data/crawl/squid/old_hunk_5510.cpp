	break;

    default:
	fatalf("delayBytesWanted: Invalid class %d\n", class);
	break;
    }
    nbytes = XMAX(min, nbytes);
