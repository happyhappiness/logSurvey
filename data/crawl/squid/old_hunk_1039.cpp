Auth::User::BuildUserKey(const char *username, const char *realm)
{
    SBuf key;
    key.Printf("%s:%s", username, realm);
    return key;
}

