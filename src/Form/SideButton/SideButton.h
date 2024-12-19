#ifndef SIDEBUTTON_H
#define SIDEBUTTON_H

/*
 * 这个类是自定义的侧边栏按钮，可以设置普通样式和高亮状态下的图标，以及按钮文字。
 */
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>
class SideButton : public QWidget
{
    Q_OBJECT
public:
    explicit SideButton(QWidget *parent = nullptr);
    void Init(const QString& common, const QString& hight_light, const QString& text);

protected:
    // 鼠标悬停，点击，离开事件。主要是样式改变。
    void mousePressEvent(QMouseEvent* event) override;
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event) override;

private:
    QIcon m_common_icon;
    QIcon m_high_light_icon;

    QVBoxLayout m_layout;
    QPushButton m_btn;
    QLabel m_label;

    QString m_common_label;
    QString m_high_light_label;

    bool flag = false;
};

#endif // SIDEBUTTON_H
