         break;
 
     case 'm':
-        p = authenticateAuthUserRequestMessage(err->auth_user_request) ? authenticateAuthUserRequestMessage(err->auth_user_request) : "[not available]";
+        p = err->auth_user_request->denyMessage("[not available]");
 
         break;
 
