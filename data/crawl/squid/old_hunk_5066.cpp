
#include "squid.h"
#include "ESIParser.h"
#include "ESILibxml2Parser.h"
#include "ESIExpatParser.h"
#include "ESICustomParser.h"

char *ESIParser::Type = NULL;

ESIParser::Pointer
ESIParser::NewParser(ESIParserClient *aClient)
{
    if (!strcasecmp("libxml2", Type))
        return new ESILibxml2Parser (aClient);

    if (!strcasecmp("expat", Type))
        return new ESIExpatParser (aClient);

    if (!strcasecmp("custom", Type))
        return new ESICustomParser (aClient);

    fatal ("Unknown ESI Parser type");

    return NULL;
}
