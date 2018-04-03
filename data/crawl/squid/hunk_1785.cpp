 #include "tests/STUB.h"
 
 #include "ssl/Config.h"
-Ssl::Config::Config() { printf("Ssl::Config::Config No implemented\n"); }
-Ssl::Config::~Config() { printf("Ssl::Config::Config No implemented\n"); }
+Ssl::Config::~Config() STUB_NOP
 Ssl::Config Ssl::TheConfig;
 
 #include "ssl/context_storage.h"
