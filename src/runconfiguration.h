#ifndef HELLO_RUNCONFIGURATION_H
#define HELLO_RUNCONFIGURATION_H

#include <projectexplorer/runconfiguration.h>
#include <projectexplorer/runcontrol.h>


namespace Hello {



class RunConfiguration : public ProjectExplorer::RunConfiguration {
    Utils::FilePath m_entryPointFilePath;
    bool m_isEnabled = false;
    ProjectExplorer::Runnable m_runnable;
    void setEnabled(bool value);
public:
    static inline Utils::Id id = "Hello.RunConfiguration";

    RunConfiguration(ProjectExplorer::Target *target);

    Utils::FilePath entryPointFilePath() const;
    void setEntryPointFilePath(const Utils::FilePath &entryPointFilePath);

    // RunConfiguration interface
public:
    virtual bool isEnabled() const override;
    virtual ProjectExplorer::Runnable runnable() const override;
};

} // namespace Hello

#endif // HELLO_RUNCONFIGURATION_H
