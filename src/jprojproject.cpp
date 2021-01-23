#include "jprojproject.h"
#include <QDebug>
#include "buildsystem.h"
#include "helloconstants.h"
#include "jprojprojectimporter.h"
#include <projectexplorer/target.h>

Hello::JProjProject::JProjProject(const Utils::FilePath &fileName)
    : ProjectExplorer::Project(Constants::JPROJ_MIMETYPE, fileName) {
    setId(Constants::JPROJ_PROJECT_ID);
    setDisplayName(fileName.toFileInfo().baseName());
    setCanBuildProducts();
    setKnowsAllBuildExecutables(false);
    setHasMakeInstallEquivalent(true);
    setBuildSystemCreator(Hello::BuildSystem::creater());

}

Hello::JProjProject::~JProjProject() {
    if(m_projectImporter)
        delete m_projectImporter;
}


ProjectExplorer::Tasks Hello::JProjProject::projectIssues(const ProjectExplorer::Kit *k) const {
    const auto result = Project::projectIssues(k);
    return result;
}

ProjectExplorer::ProjectImporter *Hello::JProjProject::projectImporter() const {
    if (!m_projectImporter)
        m_projectImporter = new JProjProjectImporter(projectFilePath());
    return m_projectImporter;
}

ProjectExplorer::DeploymentKnowledge Hello::JProjProject::deploymentKnowledge() const {
    return !files([](const ProjectExplorer::Node *n) {
                return n->filePath().fileName() == "QtCreatorDeployment.txt";
            })
                   .isEmpty()
               ? ProjectExplorer::DeploymentKnowledge::Approximative
               : ProjectExplorer::DeploymentKnowledge::Bad;
}

ProjectExplorer::MakeInstallCommand Hello::JProjProject::makeInstallCommand(const ProjectExplorer::Target *target, const QString &installRoot) {
    qDebug() << __PRETTY_FUNCTION__ << target->activeBuildKey();
    return {};
}


bool Hello::JProjProject::setupTarget(ProjectExplorer::Target *t) {
    t->updateDefaultBuildConfigurations();
    if (t->buildConfigurations().isEmpty())
        return false;
    t->updateDefaultDeployConfigurations();
    return true;
}
