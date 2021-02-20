#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    Ui::Widget *ui;
    bool sex = true;//性别选择
    bool hun = true;//婚否选择
    int eat;//吃饭选择状态
    int play;//玩游戏状态
    int sleep;//睡觉状态
    QString AiHao;
};

#endif // WIDGET_H
