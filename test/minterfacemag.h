#ifndef MINTERFACEMAG_H
#define MINTERFACEMAG_H

#include <QObject>
#include "core.h"

class MInterfaceMag : public QObject
{
    Q_OBJECT
public:
    explicit MInterfaceMag(QObject *parent = nullptr);
    Q_INVOKABLE void test();
    
private:
     Core *m_core;
};

#endif // MINTERFACEMAG_H
