 }
 
 char const *
-Auth::UserRequest::getDenyMessage()
+Auth::UserRequest::getDenyMessage() const
 {
     return message;
 }
 
 char const *
-Auth::UserRequest::denyMessage(char const * const default_message)
+Auth::UserRequest::denyMessage(char const * const default_message) const
 {
     if (getDenyMessage() == NULL)
         return default_message;