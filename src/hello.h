#ifndef HELLOPLUGIN_H
#define HELLOPLUGIN_H

#include "hello_global.h"

#include <extensionsystem/iplugin.h>

namespace Hello {
namespace Internal {

class HelloPlugin : public ExtensionSystem::IPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "Hello.json")

public:
    static void registerMimeType(const QString &id, const QString &url);

    HelloPlugin();
    ~HelloPlugin() override;

    bool initialize(const QStringList &arguments, QString *errorString) override;
    void extensionsInitialized() override;
    ShutdownFlag aboutToShutdown() override;

private:
    void triggerAction();
};

} // namespace Internal
} // namespace Hello

#endif // HELLOPLUGIN_H
