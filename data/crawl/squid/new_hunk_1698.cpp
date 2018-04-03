#include "fatal.h"
#include "globals.h"

int ConfigParser::RecognizeQuotedValues = true;
std::stack<ConfigParser::CfgFile *> ConfigParser::CfgFiles;
ConfigParser::TokenType ConfigParser::LastTokenType = ConfigParser::SimpleToken;
char *ConfigParser::LastToken = NULL;
char *ConfigParser::CfgLine = NULL;
char *ConfigParser::CfgPos = NULL;
std::queue<std::string> ConfigParser::Undo_;
bool ConfigParser::AllowMacros_ = false;

void
ConfigParser::destruct()
{
    shutting_down = 1;
    if (!CfgFiles.empty()) {
        std::ostringstream message;
        CfgFile *f = CfgFiles.top();
        message << "Bungled " << f->filePath << " line " << f->lineNo <<
        ": " << f->currentLine << std::endl;
        CfgFiles.pop();
        delete f;
        while (!CfgFiles.empty()) {
            f = CfgFiles.top();
            message << " included from " << f->filePath << " line " <<
            f->lineNo << ": " << f->currentLine << std::endl;
            CfgFiles.pop();
            delete f;
        }
        message << " included from " <<  cfg_filename << " line " <<
        config_lineno << ": " << config_input_line << std::endl;
        std::string msg = message.str();
        fatalf("%s", msg.c_str());
    } else
        fatalf("Bungled %s line %d: %s",
               cfg_filename, config_lineno, config_input_line);
}

void
ConfigParser::TokenUndo()
{
    assert(LastToken);
    Undo_.push(LastToken);
}

void
ConfigParser::TokenPutBack(const char *tok)
{
    assert(tok);
    Undo_.push(tok);
}

char *
ConfigParser::Undo()
{
    LOCAL_ARRAY(char, undoToken, CONFIG_LINE_LIMIT);
    if (!Undo_.empty()) {
        strncpy(undoToken, Undo_.front().c_str(), sizeof(undoToken));
        undoToken[sizeof(undoToken) - 1] = '\0';
        Undo_.pop();
        return undoToken;
    }
    return NULL;
}

char *
ConfigParser::strtokFile()
{
    if (RecognizeQuotedValues)
        return ConfigParser::NextToken();

    static int fromFile = 0;
    static FILE *wordFile = NULL;

    char *t;
    LOCAL_ARRAY(char, buf, CONFIG_LINE_LIMIT);

    if ((LastToken = ConfigParser::Undo()))
        return LastToken;

    do {

        if (!fromFile) {
            ConfigParser::TokenType tokenType;
            t = ConfigParser::NextElement(tokenType, true);
            if (!t) {
                return NULL;
            } else if (tokenType == ConfigParser::QuotedToken) {
                /* quote found, start reading from file */
                debugs(3, 8,"Quoted token found : " << t);

                if ((wordFile = fopen(t, "r")) == NULL) {
                    debugs(3, DBG_CRITICAL, "Can not open file " << t << " for reading");
                    return false;
                }

#if _SQUID_WINDOWS_
