#include "minterfacemag.h"

MInterfaceMag::MInterfaceMag(QObject *parent) : QObject(parent)
{
    m_core = new Core();
}

void MInterfaceMag::test()
{
    m_core->sortTest();
}
