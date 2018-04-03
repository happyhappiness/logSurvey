            /*
             *  Return dummy token AA. May need an extra return tag then AF
             */
            user=xmalloc(output_token.length+1);
            if (user == NULL) {
               if (debug)
                  fprintf(stderr, "%s| %s: Not enough memory\n", LogTime(), PROGRAM);
               fprintf(stdout, "BH Not enough memory\n");
               goto cleanup;
            }
            memcpy(user,output_token.value,output_token.length);
            user[output_token.length]='\0';
            if (norealm && (p=strchr(user,'@')) != NULL) {
                *p='\0';
            }
            fprintf(stdout, "AF %s %s\n","AA==",user);
            if (debug)
                fprintf(stderr, "%s| %s: AF %s %s\n", LogTime(), PROGRAM, "AA==", user);
            if (log)
                fprintf(stderr, "%s| %s: User %s authenticated\n", LogTime(), PROGRAM, user);

cleanup:
            gss_release_buffer(&minor_status, &input_token);
