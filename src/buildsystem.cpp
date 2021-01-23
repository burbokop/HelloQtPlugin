#include "buildsystem.h"

#include <QTimer>

#include <projectexplorer/projectnodes.h>
#include <coreplugin/editormanager/editormanager.h>




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

    setRootProjectNode(std::move(parsingResult.projectNode));
}
