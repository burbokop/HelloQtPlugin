#ifndef HELLO_BUILDSYSTEM_H
#define HELLO_BUILDSYSTEM_H

#include "jprojfileparser.h"

#include <projectexplorer/buildsystem.h>


namespace Hello {

class BuildSystem : public ProjectExplorer::BuildSystem {
    JProjFileParser m_parser;
public:
    explicit BuildSystem(ProjectExplorer::Target *target);

    // BuildSystem interface
public:
    virtual void triggerParsing() override;

    void updateProjectData();


    void updateQmlJSCodeModel();

    void updateRunConfigurations(const Utils::FilePath& entryPointFilePath);


    static auto creater() {
        return [](ProjectExplorer::Target *target) -> ProjectExplorer::BuildSystem* {
            return new Hello::BuildSystem(target);
        };
    }
};

} // namespace Hello

#endif // HELLO_BUILDSYSTEM_H
