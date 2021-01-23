#ifndef JPROJPROJECTIMPORTER_H
#define JPROJPROJECTIMPORTER_H

#include <projectexplorer/projectimporter.h>

namespace Hello {

class JProjProjectImporter : public ProjectExplorer::ProjectImporter {
    Q_OBJECT
public:
    JProjProjectImporter(const Utils::FilePath &path);

    // ProjectImporter interface
public:
    virtual QStringList importCandidates() override;

protected:
    virtual QList<void *> examineDirectory(const Utils::FilePath &importPath) const override;
    virtual bool matchKit(void *directoryData, const ProjectExplorer::Kit *k) const override;
    virtual ProjectExplorer::Kit *createKit(void *directoryData) const override;
    virtual const QList<ProjectExplorer::BuildInfo> buildInfoList(void *directoryData) const override;
    virtual void deleteDirectoryData(void *directoryData) const override;
};

}

#endif // JPROJPROJECTIMPORTER_H
