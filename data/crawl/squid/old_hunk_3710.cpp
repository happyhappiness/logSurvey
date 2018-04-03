
bool Adaptation::Config::Enabled = false;
char *Adaptation::Config::masterx_shared_name = NULL;

void
Adaptation::Config::parseService()
{
    ServiceConfig *cfg = new ServiceConfig;
    cfg->parse();
    serviceConfigs.push_back(cfg);
}

