    return;
}

CacheManager*
CacheManager::GetInstance(void)
{
    static CacheManager *instance = 0;
    if (!instance)
        instance = new CacheManager();
    return instance;
}
