        }

        /* we're finished, release the helper */
        auth_user_request->user()->username(userNote->values[0]->value.termedBuf());
        auth_user_request->denyMessage("Login successful");
        safe_free(lm_request->server_blob);
        lm_request->server_blob = xstrdup(tokenNote->values[0]->value.termedBuf());
        lm_request->releaseAuthServer();

        /* connection is authenticated */
