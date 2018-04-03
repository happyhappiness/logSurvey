    else if (http->request->auth_user_request != NULL)
        proxy_auth_msg = http->request->auth_user_request->denyMessage("<null>");

    if (answer != ACCESS_ALLOWED) {
        /* Send an error */
        debug(85, 5) ("Access Denied: %s\n", http->uri);
        debug(85, 5) ("AclMatchedName = %s\n",
                      AclMatchedName ? AclMatchedName : "<null>");
