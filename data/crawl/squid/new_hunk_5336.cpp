    return NULL;
}

ACL *
ACL::Factory (char const *type)
{
    ACL *result = Prototype::Factory (type);

    if (!result)
        fatal ("Unknown acl type in ACL::Factory");

    return result;
}

ACL::ACL () {}

void
ACL::ParseAclLine(acl ** head)
