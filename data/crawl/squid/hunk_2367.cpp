 }
 
 void
-AuthUserRequest::setDenyMessage(char const *aString)
+Auth::UserRequest::setDenyMessage(char const *aString)
 {
     safe_free(message);
     message = xstrdup(aString);
 }
 
 char const *
-AuthUserRequest::getDenyMessage()
+Auth::UserRequest::getDenyMessage()
 {
     return message;
 }
 
 char const *
-AuthUserRequest::denyMessage(char const * const default_message)
+Auth::UserRequest::denyMessage(char const * const default_message)
 {
     if (this == NULL || getDenyMessage() == NULL) {
         return default_message;
