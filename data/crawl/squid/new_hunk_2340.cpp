
    *var = xstrdup((char *) token);
}
#endif

void parse_wordlist(wordlist ** list) STUB
#if 0
{
    char *token;
    char *t = strtok(NULL, "");

    while ((token = strwordtok(NULL, &t)))
        wordlistAdd(list, token);
}
#endif

void requirePathnameExists(const char *name, const char *path) STUB_NOP
void parse_time_t(time_t * var) STUB
char * strtokFile(void) STUB_RETVAL(NULL)
void ConfigParser::ParseUShort(unsigned short *var) STUB
void dump_acl_access(StoreEntry * entry, const char *name, acl_access * head) STUB
YesNoNone::operator void*() const { STUB_NOP; return NULL; }
