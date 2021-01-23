#include "jprojfileparser.h"

#include <QJsonDocument>
#include "helloconstants.h"

Hello::JProjFileParser::JProjFileParser() {}

Hello::JProjFileParser::Result Hello::JProjFileParser::parseData(const QByteArray &jsonData, const Utils::FilePath& projectRootDir, bool defaultDisplayManual) {
    Utils::FilePath entryPoint;
    QString projectName;
    const auto doc = QJsonDocument::fromJson(jsonData);
    if(doc.isNull())
        return { nullptr, entryPoint, projectName };

    const auto object = doc.toVariant().toMap();
    auto rootProjectNode = std::make_unique<ProjectExplorer::ProjectNode>(projectRootDir);
    rootProjectNode->setIcon(QIcon(Constants::JPROJ_ICON));

    {
        const auto it = object.find("files");
        if(it != object.end()) {
            const auto fileNames = it.value().toList();
            std::vector<std::unique_ptr<ProjectExplorer::FileNode>> files;
            for(const auto& fn : fileNames) {
                const auto path = projectRootDir / fn.toString();
                files.push_back(std::make_unique<ProjectExplorer::FileNode>(path, ProjectExplorer::FileType::Unknown));
            }
            rootProjectNode->addNestedNodes(std::move(files), projectRootDir);
        }
    } {
        const auto it = object.find("subProjects");
        if(it != object.end()) {
            const auto fileNames = it.value().toList();
            for(const auto& fn : fileNames) {
                const auto path = projectRootDir / fn.toString();
                auto subr = parseFile(path, path.parentDir(), false);
                if(subr.projectNode) {
                    rootProjectNode->addNode(std::move(subr.projectNode));
                }
            }
        }
    } {
        const auto it = object.find("displayManual");
        bool yes = defaultDisplayManual;
        if(it != object.end())
            yes = it.value().toBool();

        if(yes) {
            auto manualNode = std::make_unique<TitledFileNode>(Utils::FilePath::fromString(":/resources/rtfm.md"), "RTFM");
            manualNode->setPriority(0);
            rootProjectNode->addNode(std::move(manualNode));
        }
    } {
        const auto it = object.find("projectName");
        if(it != object.end()) {
            projectName = it.value().toString();
        }
    } {
        const auto it = object.find("entryPoint");
        if(it != object.end()) {
            entryPoint = Utils::FilePath::fromString(it->toString());
        }
    }

    if(!projectName.isEmpty()) {
        rootProjectNode->setDisplayName(projectName);
    }

    return { std::move(rootProjectNode), entryPoint, projectName };
}

Hello::JProjFileParser::Result Hello::JProjFileParser::parseFile(const Utils::FilePath &projectFilePath, const Utils::FilePath &projectRootDir, bool defaultDisplayManual) {
    QFile file(projectFilePath.toString());
    if(file.open(QIODevice::ReadOnly)) {
        auto result = parseData(file.readAll(), projectRootDir, defaultDisplayManual);
        if(result.projectNode) {
            auto projectFileNode = std::make_unique<ProjectExplorer::FileNode>(projectFilePath, ProjectExplorer::FileType::Unknown);
            projectFileNode->setPriority(std::numeric_limits<int>::max());
            result.projectNode->addNestedNode(std::move(projectFileNode));
            return { std::move(result.projectNode), result.entryPoint, result.projectName };
        }
    }
    return {};
}
