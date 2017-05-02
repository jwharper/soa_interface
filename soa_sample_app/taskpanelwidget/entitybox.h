#ifndef ENTITYBOX_H
#define ENTITYBOX_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QGroupBox>
#include <QGridLayout>



class EntityBox : public QGroupBox
{
    Q_OBJECT

public:
    EntityBox(QWidget * parent = 0);
    Q_SLOT QString boxInfo2();
    Q_SLOT void resetMe();
    QStringList boxInfo();
    QStringList m_Entities;

private:
    QComboBox * m_pUGVBox;
    QComboBox * m_pUAVBox;
    QComboBox * m_pHumanBox;
};

#endif // ENTITYBOX_H
