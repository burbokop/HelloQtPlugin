#include "hello.h"
#include "helloconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/settingsdatabase.h>
#include <coreplugin/fileiconprovider.h>
#include <utils/mimetypes/mimedatabase.h>

#include <projectexplorer/projectmanager.h>

#include <src/jprojproject.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

namespace Hello {
namespace Internal {

void HelloPlugin::registerMimeType(const QString &id, const QString &url) {
    QFile mimeTypeFile(url);
    if(mimeTypeFile.open(QIODevice::ReadOnly)) {
        Utils::addMimeTypes(id, mimeTypeFile.readAll());
    } else {
        QMessageBox::information(Core::ICore::mainWindow(), "Error message", mimeTypeFile.errorString());
    }
}

HelloPlugin::HelloPlugin() {}

HelloPlugin::~HelloPlugin() {}

bool HelloPlugin::initialize(const QStringList &arguments, QString *errorString) {
    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    registerMimeType(Constants::JPROJ_MIMETYPE, Constants::JPROJ_MIMETYPE_FILE);
    //Core::FileIconProvider::registerIconOverlayForSuffix(Constants::JPROJ_FILE_OVERLAY, Constants::JPROJ_FILE_SUFFIX);
    ProjectExplorer::ProjectManager::registerProjectType<JProjProject>(Constants::JPROJ_MIMETYPE);




    //auto action = new QAction(tr("Hello Action"), this);
    //Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
    //                                                         Core::Context(Core::Constants::C_GLOBAL));
    //cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+X")));
    //connect(action, &QAction::triggered, this, &HelloPlugin::triggerAction);
    //
    //Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    //menu->menu()->setTitle(tr("Hello2361"));
    //menu->addAction(cmd);
    //Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);


//    QObject::connect(
//                Core::EditorManager::instance(),
//                &Core::EditorManager::documentOpened,
//                this,
//                [](Core::IDocument *doc) {
//        //const auto &c = doc->contents();
//
//
//
//        //QMessageBox::information(Core::ICore::mainWindow(),
//        //                         tr("File Opened"),
//        //                         doc->filePath().toString());
//    });


    return true;
}

void HelloPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag HelloPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void HelloPlugin::triggerAction() {

    //Core::NavigationView::

    //const auto e = Core::EditorManager::instance()->openEditor("/home/boris/Documents/narko_protocol");


    QMessageBox::information(Core::ICore::mainWindow(),
                             tr("Action Triggered"),
                             tr("This is an action from Hello."));
}

} // namespace Internal
} // namespace Hello
