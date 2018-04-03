            fprintf(stderr, "is followed to the top (e.g. if the group is a member of a group)\n");
            fprintf(stderr, "Group membership is determined with non AD servers through the users memberuid (assuming\n");
            fprintf(stderr, "PosixGroup) or primary group membership (assuming PosixAccount)\n");
            clean_args(&margs);
            exit(0);
        default:
