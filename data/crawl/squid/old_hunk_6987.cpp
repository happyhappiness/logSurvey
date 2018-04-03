{
    switch (var) {
    case ANONYMIZER_NONE:
	printf("off");
	break;
    case ANONYMIZER_STANDARD:
	printf("paranoid");
	break;
    case ANONYMIZER_PARANOID:
	printf("standard");
	break;
    }
}
