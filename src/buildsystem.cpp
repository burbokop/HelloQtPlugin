#include "buildsystem.h"
#include "runconfiguration.h"

#include <QTimer>

#include <projectexplorer/projectnodes.h>
#include <projectexplorer/target.h>
#include <coreplugin/editormanager/editormanager.h>
#include <projectexplorer/runconfiguration.h>



Hello::BuildSystem::BuildSystem(ProjectExplorer::Target *target)
    : ProjectExplorer::BuildSystem(target) {
    qDebug() << __PRETTY_FUNCTION__;

    connect(Core::EditorManager::instance(), &Core::EditorManager::documentStateChanged, this, [this](Core::IDocument *document){
        if(document->filePath() == projectFilePath() && !document->isModified())
            updateProjectData();
    });
    updateProjectData();
}

void Hello::BuildSystem::triggerParsing() {
    qDebug() << __PRETTY_FUNCTION__;
}

void Hello::BuildSystem::updateProjectData() {
    auto parsingResult = m_parser.parseFile(projectFilePath(), projectDirectory());
    auto p = project();
    if(p && !parsingResult.projectName.isEmpty())
        p->setDisplayName(parsingResult.projectName);

    updateRunConfigurations(parsingResult.entryPointFilePath);
    setRootProjectNode(std::move(parsingResult.projectNode));
}

void Hello::BuildSystem::updateRunConfigurations(const Utils::FilePath &entryPointFilePath) {
    auto t = target();
    if(t) {
        RunConfiguration *currentConf = nullptr;

        const auto cc = t->runConfigurations();
        for(auto&& c : cc) {
            if(c->id() == RunConfiguration::id) {
                currentConf = dynamic_cast<RunConfiguration*>(c);
                break;
            }
        }

        if(!currentConf) {
            currentConf = new RunConfiguration(t);
            t->addRunConfiguration(currentConf);
        }

        currentConf->setEntryPointFilePath(entryPointFilePath);
        currentConf->setToolTip("my tool tip");
        t->setActiveRunConfiguration(currentConf);
    }
}
