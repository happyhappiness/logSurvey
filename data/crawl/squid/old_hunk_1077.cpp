        exit(1);
}

int
manage_request()
{
    char buf[HELPER_INPUT_BUFFER];
    char decoded[HELPER_INPUT_BUFFER];
    int decodedLen;
    char helper_command[3];
    char *c;
    int status;
