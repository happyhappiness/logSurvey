	break;

    default:
	fatalf("delayBytesWanted: Invalid class %d\n", delay_class);
	break;
    }
    nbytes = XMAX(min, nbytes);
