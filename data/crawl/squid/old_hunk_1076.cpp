        exit(1);
}

int
manage_request()
{
    ntlmhdr *fast_header;
    char buf[HELPER_INPUT_BUFFER];
    char decoded[HELPER_INPUT_BUFFER];
    int decodedLen;
    char helper_command[3];
    int oversized = 0;
    char * ErrorMessage;
