    return NULL;
}

ACL *
ACL::clone()const
{
    fatal ("Cannot clone base class");
    return NULL;
}
