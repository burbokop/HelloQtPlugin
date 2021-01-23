#include "jprojprojectimporter.h"
#include <QDebug>
#include <projectexplorer/buildinfo.h>


Hello::JProjProjectImporter::JProjProjectImporter(const Utils::FilePath &path)
    : ProjectExplorer::ProjectImporter(path) {
    qDebug() << __PRETTY_FUNCTION__;
}


QStringList Hello::JProjProjectImporter::importCandidates() {
    qDebug() << __PRETTY_FUNCTION__;
    return {};
}

QList<void *> Hello::JProjProjectImporter::examineDirectory(const Utils::FilePath &importPath) const {
    qDebug() << __PRETTY_FUNCTION__ << importPath;
    return {};
}

bool Hello::JProjProjectImporter::matchKit(void *directoryData, const ProjectExplorer::Kit *k) const {
    qDebug() << __PRETTY_FUNCTION__ << directoryData << k;
    return false;
}

ProjectExplorer::Kit *Hello::JProjProjectImporter::createKit(void *directoryData) const {
    qDebug() << __PRETTY_FUNCTION__ << directoryData;
    return nullptr;
}

const QList<ProjectExplorer::BuildInfo> Hello::JProjProjectImporter::buildInfoList(void *directoryData) const {
    qDebug() << __PRETTY_FUNCTION__ << directoryData;
    return {};
}

void Hello::JProjProjectImporter::deleteDirectoryData(void *directoryData) const {
    qDebug() << __PRETTY_FUNCTION__ << directoryData;
}
