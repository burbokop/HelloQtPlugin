#ifndef HELLO_RUNCONFIGURATION_H
#define HELLO_RUNCONFIGURATION_H

#include <projectexplorer/runconfiguration.h>
#include <projectexplorer/runcontrol.h>


namespace Hello {

template<typename T>
class WidgetAspect : public Utils::BaseAspect {
public:
    template<typename ...Args>
    WidgetAspect(const QRect& geometry, Args&&... args) {
        setConfigWidgetCreator([geometry, args...]{
            auto w = new T(args...);
            w->setGeometry(geometry);
            return w;
        });
    }

    // ISettingsAspect interface
protected:
    virtual void toMap(QVariantMap &) const override {};
    virtual void fromMap(const QVariantMap &) override {};
};


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
