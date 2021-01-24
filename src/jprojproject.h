#ifndef MYPROJECT_H
#define MYPROJECT_H

#include <projectexplorer/project.h>

namespace Hello {

class JProjProject : public ProjectExplorer::Project {
    Q_OBJECT
public:
    JProjProject(const Utils::FilePath &fileName);

    // Project interface
protected:
    virtual bool setupTarget(ProjectExplorer::Target *t) override;
};

}
#endif // MYPROJECT_H
