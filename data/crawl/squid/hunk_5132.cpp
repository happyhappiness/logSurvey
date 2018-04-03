     return auth_user;
 }
 
-/* C bindings */
-/* UserNameCacheAdd: add a auth_user structure to the username cache */
-void
-authenticateUserNameCacheAdd(auth_user_t * auth_user)
-{
-    auth_user->usernamehash = new AuthUserHashPointer (auth_user);
-}
-
-auth_user_t*
-authUserHashPointerUser (auth_user_hash_pointer *aHashEntry)
-{
-    return aHashEntry->user();
-}
-
-void *
-AuthUserRequestState::operator new (size_t)
-{
-    fatal ("unusable\n");
-    return (void *)1;
-}
 
-void
-AuthUserRequestState::operator delete (void *)
-{
-    fatal ("unusable\n");
-}
