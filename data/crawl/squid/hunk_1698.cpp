 #include "fatal.h"
 #include "globals.h"
 
-char *ConfigParser::lastToken = NULL;
-std::queue<std::string> ConfigParser::undo;
+int ConfigParser::RecognizeQuotedValues = true;
+std::stack<ConfigParser::CfgFile *> ConfigParser::CfgFiles;
+ConfigParser::TokenType ConfigParser::LastTokenType = ConfigParser::SimpleToken;
+char *ConfigParser::LastToken = NULL;
+char *ConfigParser::CfgLine = NULL;
+char *ConfigParser::CfgPos = NULL;
+std::queue<std::string> ConfigParser::Undo_;
+bool ConfigParser::AllowMacros_ = false;
 
 void
 ConfigParser::destruct()
 {
     shutting_down = 1;
-    fatalf("Bungled %s line %d: %s",
-           cfg_filename, config_lineno, config_input_line);
+    if (!CfgFiles.empty()) {
+        std::ostringstream message;
+        CfgFile *f = CfgFiles.top();
+        message << "Bungled " << f->filePath << " line " << f->lineNo <<
+        ": " << f->currentLine << std::endl;
+        CfgFiles.pop();
+        delete f;
+        while (!CfgFiles.empty()) {
+            f = CfgFiles.top();
+            message << " included from " << f->filePath << " line " <<
+            f->lineNo << ": " << f->currentLine << std::endl;
+            CfgFiles.pop();
+            delete f;
+        }
+        message << " included from " <<  cfg_filename << " line " <<
+        config_lineno << ": " << config_input_line << std::endl;
+        std::string msg = message.str();
+        fatalf("%s", msg.c_str());
+    } else
+        fatalf("Bungled %s line %d: %s",
+               cfg_filename, config_lineno, config_input_line);
 }
 
 void
-ConfigParser::strtokFileUndo()
+ConfigParser::TokenUndo()
 {
-    assert(lastToken);
-    undo.push(lastToken);
+    assert(LastToken);
+    Undo_.push(LastToken);
 }
 
 void
-ConfigParser::strtokFilePutBack(const char *tok)
+ConfigParser::TokenPutBack(const char *tok)
 {
     assert(tok);
-    undo.push(tok);
+    Undo_.push(tok);
 }
 
 char *
-ConfigParser::strtokFile(void)
+ConfigParser::Undo()
 {
+    LOCAL_ARRAY(char, undoToken, CONFIG_LINE_LIMIT);
+    if (!Undo_.empty()) {
+        strncpy(undoToken, Undo_.front().c_str(), sizeof(undoToken));
+        undoToken[sizeof(undoToken) - 1] = '\0';
+        Undo_.pop();
+        return undoToken;
+    }
+    return NULL;
+}
+
+char *
+ConfigParser::strtokFile()
+{
+    if (RecognizeQuotedValues)
+        return ConfigParser::NextToken();
+
     static int fromFile = 0;
     static FILE *wordFile = NULL;
-    LOCAL_ARRAY(char, undoToken, CONFIG_LINE_LIMIT);
 
-    char *t, *fn;
+    char *t;
     LOCAL_ARRAY(char, buf, CONFIG_LINE_LIMIT);
 
-    if (!undo.empty()) {
-        strncpy(undoToken, undo.front().c_str(), sizeof(undoToken));
-        undoToken[sizeof(undoToken) - 1] = '\0';
-        undo.pop();
-        return undoToken;
-    }
+    if ((LastToken = ConfigParser::Undo()))
+        return LastToken;
 
-    lastToken = NULL;
     do {
 
         if (!fromFile) {
-            t = (strtok(NULL, w_space));
-
-            if (!t || *t == '#') {
+            ConfigParser::TokenType tokenType;
+            t = ConfigParser::NextElement(tokenType, true);
+            if (!t) {
                 return NULL;
-            } else if (*t == '\"' || *t == '\'') {
+            } else if (tokenType == ConfigParser::QuotedToken) {
                 /* quote found, start reading from file */
-                fn = ++t;
-
-                while (*t && *t != '\"' && *t != '\'')
-                    ++t;
+                debugs(3, 8,"Quoted token found : " << t);
 
-                *t = '\0';
-
-                if ((wordFile = fopen(fn, "r")) == NULL) {
-                    debugs(28, DBG_CRITICAL, "strtokFile: " << fn << " not found");
-                    return (NULL);
+                if ((wordFile = fopen(t, "r")) == NULL) {
+                    debugs(3, DBG_CRITICAL, "Can not open file " << t << " for reading");
+                    return false;
                 }
 
 #if _SQUID_WINDOWS_
