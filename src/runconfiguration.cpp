#include "runconfiguration.h"


void Hello::RunConfiguration::setEnabled(bool value) {
    if(m_isEnabled != value) {
        m_isEnabled = value;
        emit enabledChanged();
    }
}

Hello::RunConfiguration::RunConfiguration(ProjectExplorer::Target *target)
    : ProjectExplorer::RunConfiguration(target, id) {
    qDebug() << "rc create";
    setDefaultDisplayName("hello empty configuration");
}


Utils::FilePath Hello::RunConfiguration::entryPointFilePath() const {
    return m_entryPointFilePath;
}

void Hello::RunConfiguration::setEntryPointFilePath(const Utils::FilePath &entryPointFilePath) {    
    m_entryPointFilePath = entryPointFilePath;
    m_runnable.setCommandLine(Utils::CommandLine(entryPointFilePath));
    m_runnable.workingDirectory = entryPointFilePath.parentDir().toString();
    setDisplayName(entryPointFilePath.fileName());
    setEnabled(entryPointFilePath.exists());
    update();
}

bool Hello::RunConfiguration::isEnabled() const {
    return m_isEnabled;
}

ProjectExplorer::Runnable Hello::RunConfiguration::runnable() const {
    return m_runnable;
}
