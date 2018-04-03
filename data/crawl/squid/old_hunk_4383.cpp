{
    int error_count = 0;
    char* saveptr = NULL;
    char* file = strwordtok(files, &saveptr);
    while (file != NULL) {
        error_count += parseOneConfigFile(file, depth);
        file = strwordtok(NULL, &saveptr);
    }
    return error_count;
}

