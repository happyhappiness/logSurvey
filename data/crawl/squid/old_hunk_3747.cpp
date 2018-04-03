            /*
             *  Return dummy token AA. May need an extra return tag then AF
             */
            fprintf(stdout, "AF %s %s\n","AA==",(char *)output_token.value);
            if (debug)
                fprintf(stderr, "%s| %s: AF %s %s\n", LogTime(), PROGRAM, "AA==", (char *)output_token.value);
            if (log)
                fprintf(stderr, "%s| %s: User %s authenticated\n", LogTime(), PROGRAM, (char *)output_token.value);

cleanup:
            gss_release_buffer(&minor_status, &input_token);
