#ifndef BYTASKPANEL_H
#define BYTASKPANEL_H

#include <QWidget>

namespace Ui {
class ByTaskPanel;
}

class ByTaskPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ByTaskPanel(QWidget *parent = 0);
    ~ByTaskPanel();

private:
    Ui::ByTaskPanel *ui;
};

#endif // BYTASKPANEL_H
