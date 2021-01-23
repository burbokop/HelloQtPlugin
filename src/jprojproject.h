#ifndef MYPROJECT_H
#define MYPROJECT_H

#include <projectexplorer/project.h>

namespace Hello {

class JProjProject : public ProjectExplorer::Project {
    Q_OBJECT
    mutable ProjectExplorer::ProjectImporter *m_projectImporter = nullptr;
public:
    JProjProject(const Utils::FilePath &fileName);
    ~JProjProject();

    // Project interface
public:
    virtual ProjectExplorer::ProjectImporter *projectImporter() const override;
    virtual ProjectExplorer::DeploymentKnowledge deploymentKnowledge() const override;
    virtual ProjectExplorer::MakeInstallCommand makeInstallCommand(const ProjectExplorer::Target *target, const QString &installRoot) override;



    void updateQmlJSCodeModel();




    // Project interface
protected:
    virtual bool setupTarget(ProjectExplorer::Target *t) override;
};

}
#endif // MYPROJECT_H
