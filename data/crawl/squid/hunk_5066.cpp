 
 #include "squid.h"
 #include "ESIParser.h"
-#include "ESILibxml2Parser.h"
-#include "ESIExpatParser.h"
-#include "ESICustomParser.h"
 
 char *ESIParser::Type = NULL;
+ESIParser::Register *ESIParser::Parsers = NULL;
 
 ESIParser::Pointer
 ESIParser::NewParser(ESIParserClient *aClient)
 {
-    if (!strcasecmp("libxml2", Type))
-        return new ESILibxml2Parser (aClient);
+    if (Parser == NULL) {
+        Parser = Parsers;
 
-    if (!strcasecmp("expat", Type))
-        return new ESIExpatParser (aClient);
+        while (Parser != NULL && strcasecmp(Parser->name, Type) != 0)
+            Parser = Parser->next;
 
-    if (!strcasecmp("custom", Type))
-        return new ESICustomParser (aClient);
+        if (Parser == NULL)
+            fatal ("Unknown ESI Parser type");
+    }
 
-    fatal ("Unknown ESI Parser type");
-
-    return NULL;
+    return (Parser->newParser)(aClient);
 }
