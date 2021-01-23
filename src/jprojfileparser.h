#ifndef JPROJFILEPARSER_H
#define JPROJFILEPARSER_H

#include <projectexplorer/projectnodes.h>

namespace Hello {

class TitledFileNode : public ProjectExplorer::FileNode {
    QString m_title;
public:
    TitledFileNode(const Utils::FilePath& path, const QString& title)
        : ProjectExplorer::FileNode(path, ProjectExplorer::FileType::Unknown) {
        m_title = title;
    }
    virtual QString displayName() const override { return m_title; }
};


class JProjFileParser {
public:
    struct Result {
        std::unique_ptr<ProjectExplorer::ProjectNode> projectNode;
        Utils::FilePath entryPointFilePath;
        QString projectName;
    };

    JProjFileParser();

    /**
     * @brief parse
     * @param jsonData
     * @param projectRootDir
     * @return pair of Project node and entry point file path
     */
    Result parseData(const QByteArray &jsonData, const Utils::FilePath& projectRootDir, bool defaultDisplayManual = true);

    Result parseFile(const Utils::FilePath& projectFilePath, const Utils::FilePath& projectRootDir, bool defaultDisplayManual = true);
};

}

#endif // JPROJFILEPARSER_H
