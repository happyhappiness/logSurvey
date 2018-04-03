            fprintf(stderr, "group   - In this case group can be used for all keberised and non kerberised ldap servers\n");
            fprintf(stderr, "group@  - In this case group can be used for all keberised ldap servers\n");
            fprintf(stderr, "group@domain  - In this case group can be used for ldap servers of domain domain\n");
            fprintf(stderr, "group1@domain1:group2@domain2:group3@:group4  - A list is build with a colon as seperator\n");
            fprintf(stderr, "Group membership is determined with AD servers through the users memberof attribute which\n");
            fprintf(stderr, "is followed to the top (e.g. if the group is a member of a group)\n");
            fprintf(stderr, "Group membership is determined with non AD servers through the users memberuid (assuming\n");
