{
    switch (var) {
    case ANONYMIZER_NONE:
	storeAppendPrintf(entry, "%s off\n", name);
	break;
    case ANONYMIZER_STANDARD:
	storeAppendPrintf(entry, "%s paranoid\n", name);
	break;
    case ANONYMIZER_PARANOID:
	storeAppendPrintf(entry, "%s standard\n", name);
	break;
    }
}
