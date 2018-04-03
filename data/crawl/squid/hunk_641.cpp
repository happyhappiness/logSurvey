         if ( *line == '\0' || *line == '\n' ) continue;
 
         // test line
-        if ( (result=regexec( &rexp, line, 7, subs, 0 )) != 0 ) {
-            // error or no match
-            if ( result != REG_NOMATCH ) {
-                char buffer[256];
-                regerror( result, &rexp, buffer, sizeof(buffer) );
-                fprintf( stderr, "while matching \"%s\" against %s%s\n",
-                         expression, line, buffer );
-                regfree(&rexp);
-                cfgin.close();
-                return -1;
-            }
+        std::string tmpLine(line);
+        if (!std::regex_search(tmpLine, subs, rexp))
+            continue;
+
+        // match, please record
+        memset( &cd, 0, sizeof(cd) );
+        if ( debug ) fprintf( debug, "# match '%s' on line %s", subs[0].str().c_str(), line);
+
+        // extract information. If 6th parenthesis is filled, this is
+        // a new squid with disk types, otherwise it is an older version
+        int offset = 2;
+        if (subs[6].str().empty()) {
+            // old version, disk type at position 2 is always UFS
+            cd.type = CacheDir::CDT_UFS;
         } else {
-            // match, please record
-            memset( &cd, 0, sizeof(cd) );
-            if ( debug ) fprintf( debug, "# match from %d-%d on line %s",
-                                      (int)subs[0].rm_so, (int)subs[0].rm_eo,
-                                      line );
-
-            // terminate line after matched expression
-            line[ subs[0].rm_eo ] = '\0';
-
-            // extract information. If 6th parenthesis is filled, this is
-            // a new squid with disk types, otherwise it is an older version
-            int offset = 2;
-            if ( subs[6].rm_so == -1 ) {
-                // old version, disk type at position 2 is always UFS
+            // new version, disk type at position 2
+            if ( debug ) fprintf( debug, "# match '%s' in \"%s\"\n", subs[offset].str().c_str(), subs[0].str().c_str());
+            static const std::string ufsDir("ufs",3);
+            static const std::string aufsDir("aufs",4);
+            static const std::string asyncUfsDir("asyncufs",8);
+            static const std::string diskdDir("diskd",5);
+            if (subs[offset] == ufsDir)
                 cd.type = CacheDir::CDT_UFS;
-            } else {
-                // new version, disk type at position 2
-                line[ subs[offset].rm_eo ] = '\0';
-                if ( debug ) fprintf( debug, "# match from %d-%d on \"%s\"\n",
-                                          (int)subs[offset].rm_so,
-                                          (int)subs[offset].rm_eo,
-                                          line+subs[offset].rm_so );
-                if ( strcmp( line + subs[offset].rm_so, "ufs" ) == 0 )
-                    cd.type = CacheDir::CDT_UFS;
-                else if ( strcmp( line + subs[offset].rm_so, "asyncufs" ) == 0 )
-                    cd.type = CacheDir::CDT_AUFS;
-                else if ( strcmp( line + subs[offset].rm_so, "diskd" ) == 0 )
-                    cd.type = CacheDir::CDT_DISKD;
-                else
-                    cd.type = CacheDir::CDT_OTHER;
-                ++offset;
-            }
-
-            // extract base directory
-            line[ subs[offset].rm_eo ] = '\0';
-            if ( debug ) fprintf( debug, "# match from %d-%d on \"%s\"\n",
-                                      (int)subs[offset].rm_so,
-                                      (int)subs[offset].rm_eo,
-                                      line+subs[offset].rm_so );
-            cd.base = xstrdup( line+subs[offset].rm_so );
+            else if (subs[offset] == aufsDir || subs[offset] == asyncUfsDir)
+                cd.type = CacheDir::CDT_AUFS;
+            else if (subs[offset] == diskdDir)
+                cd.type = CacheDir::CDT_DISKD;
+            else
+                cd.type = CacheDir::CDT_OTHER;
             ++offset;
+        }
 
-            // extract size information
-            line[ subs[offset].rm_eo ] = '\0';
-            if ( debug ) fprintf( debug, "# match from %d-%d on \"%s\"\n",
-                                      (int)subs[offset].rm_so,
-                                      (int)subs[offset].rm_eo,
-                                      line+subs[offset].rm_so );
-            cd.size = strtoul( line+subs[offset].rm_so, 0, 10 );
-            ++offset;
+        // extract base directory
+        if ( debug ) fprintf( debug, "# match '%s' in \"%s\"\n", subs[offset].str().c_str(), subs[0].str().c_str());
+        cd.base = xstrdup(subs[offset].str().c_str());
+        ++offset;
 
-            // extract 1st level directories
-            line[ subs[offset].rm_eo ] = '\0';
-            if ( debug ) fprintf( debug, "# match from %d-%d on \"%s\"\n",
-                                      (int)subs[offset].rm_so,
-                                      (int)subs[offset].rm_eo,
-                                      line+subs[offset].rm_so );
-            cd.level[0] = strtoul( line+subs[offset].rm_so, 0, 10 );
-            ++offset;
+        // extract size information
+        if ( debug ) fprintf( debug, "# match '%s' in \"%s\"\n", subs[offset].str().c_str(), subs[0].str().c_str());
+        cd.size = strtoul(subs[offset].str().c_str(), 0, 10);
+        ++offset;
 
-            // extract 2nd level directories
-            line[ subs[offset].rm_eo ] = '\0';
-            if ( debug ) fprintf( debug, "# match from %d-%d on \"%s\"\n",
-                                      (int)subs[offset].rm_so,
-                                      (int)subs[offset].rm_eo,
-                                      line+subs[offset].rm_so );
-            cd.level[1] = strtoul( line+subs[offset].rm_so, 0, 10 );
-            ++offset;
+        // extract 1st level directories
+        if ( debug ) fprintf( debug, "# match '%s' in \"%s\"\n", subs[offset].str().c_str(), subs[0].str().c_str());
+        cd.level[0] = strtoul(subs[offset].str().c_str(), 0, 10);
+        ++offset;
 
-            cachedir.push_back( cd );
-        }
+        // extract 2nd level directories
+        if ( debug ) fprintf( debug, "# match '%s' in \"%s\"\n", subs[offset].str().c_str(), subs[0].str().c_str());
+        cd.level[1] = strtoul(subs[offset].str().c_str(), 0, 10);
+        ++offset;
+
+        cachedir.push_back( cd );
     }
 
     cfgin.close();
-    regfree(&rexp);
     return cachedir.size();
 }
 