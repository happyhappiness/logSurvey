    return s;
}

int
parseConfigFile(const char *file_name, CacheManager & manager)
{
    FILE *fp = NULL;
    char *token = NULL;
    char *tmp_line = NULL;
    int tmp_line_len = 0;
    int err_count = 0;
    int is_pipe = 0;
    configFreeMemory();
    default_all();

    if (file_name[0] == '!' || file_name[0] == '|') {
        fp = popen(file_name + 1, "r");
