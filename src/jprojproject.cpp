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
    setBuildSystemCreator(Hello::BuildSystem::creater());
}


bool Hello::JProjProject::setupTarget(ProjectExplorer::Target *t) {
    t->updateDefaultBuildConfigurations();
    if (t->buildConfigurations().isEmpty())
        return false;
    t->updateDefaultDeployConfigurations();
    return true;
}
