#ifndef TABPANELWIDGET_H
#define TABPANELWIDGET_H

#include <QWidget>

namespace Ui {
class TabPanelWidget;
}

class TabPanelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TabPanelWidget(QWidget *parent = 0);
    ~TabPanelWidget();

    void initialize();
    Q_SLOT void summarize();

private:
    Ui::TabPanelWidget *ui;
};

#endif // TABPANELWIDGET_H
