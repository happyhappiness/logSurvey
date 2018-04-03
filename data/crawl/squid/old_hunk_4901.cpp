
};

List<String> *ICAPOptions::parseExtFileList(const char *start, const char *end, transfer_type t_type)
{
    const String s = xstrndup(start, end - start - 1);
    const char *item;
    const char *pos = NULL;
    char *fext = NULL;
