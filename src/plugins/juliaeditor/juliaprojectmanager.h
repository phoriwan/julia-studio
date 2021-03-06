#ifndef JULIAPROJECTMANAGER_H
#define JULIAPROJECTMANAGER_H

#include "juliadummyproject.h"

#include <projectexplorer/iprojectmanager.h>

namespace JuliaPlugin {

class JuliaProjectManager : public ProjectExplorer::IProjectManager
{
  Q_OBJECT
public:
  explicit JuliaProjectManager()  {}

  virtual QString mimeType() const  { return "text/julia"; }
  virtual ProjectExplorer::Project* openProject(const QString &fileName, QString *errorString = 0)
  {
    Q_UNUSED( fileName );
    Q_UNUSED( errorString );
    return new JuliaDummyProject();
  }

signals:
  
public slots:
  
};

}

#endif // JULIAPROJECTMANAGER_H
