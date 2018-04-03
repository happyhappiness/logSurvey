#include "fatal.h"
#include "globals.h"

char *ConfigParser::lastToken = NULL;
std::queue<std::string> ConfigParser::undo;

void
ConfigParser::destruct()
{
    shutting_down = 1;
    fatalf("Bungled %s line %d: %s",
           cfg_filename, config_lineno, config_input_line);
}

void
ConfigParser::strtokFileUndo()
{
    assert(lastToken);
    undo.push(lastToken);
}

void
ConfigParser::strtokFilePutBack(const char *tok)
{
    assert(tok);
    undo.push(tok);
}

char *
ConfigParser::strtokFile(void)
{
    static int fromFile = 0;
    static FILE *wordFile = NULL;
    LOCAL_ARRAY(char, undoToken, CONFIG_LINE_LIMIT);

    char *t, *fn;
    LOCAL_ARRAY(char, buf, CONFIG_LINE_LIMIT);

    if (!undo.empty()) {
        strncpy(undoToken, undo.front().c_str(), sizeof(undoToken));
        undoToken[sizeof(undoToken) - 1] = '\0';
        undo.pop();
        return undoToken;
    }

    lastToken = NULL;
    do {

        if (!fromFile) {
            t = (strtok(NULL, w_space));

            if (!t || *t == '#') {
                return NULL;
            } else if (*t == '\"' || *t == '\'') {
                /* quote found, start reading from file */
                fn = ++t;

                while (*t && *t != '\"' && *t != '\'')
                    ++t;

                *t = '\0';

                if ((wordFile = fopen(fn, "r")) == NULL) {
                    debugs(28, DBG_CRITICAL, "strtokFile: " << fn << " not found");
                    return (NULL);
                }

#if _SQUID_WINDOWS_
