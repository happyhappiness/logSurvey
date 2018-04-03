            auth_user_request->user()->credentials(Auth::Failed);
            auth_user_request->denyMessage("NTLM authentication requires a persistent connection");
        }
    } else if (strncasecmp(reply, "AF ", 3) == 0 && arg != NULL) {
        /* we're finished, release the helper */

        if (arg) {
            *arg = '\0';
            ++arg;
        }

        auth_user_request->user()->username(arg);
        auth_user_request->denyMessage("Login successful");
        safe_free(lm_request->server_blob);
