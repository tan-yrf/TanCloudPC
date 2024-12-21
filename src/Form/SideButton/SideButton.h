#ifndef SIDEBUTTON_H
#define SIDEBUTTON_H

/*
 * 这个类是自定义的侧边栏按钮，可以设置普通样式和高亮状态下的图标，以及按钮文字。
 */
#include <QWidget>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QLabel>
class SideButton : public QWidget
{
    Q_OBJECT
public:
    explicit SideButton(QWidget *parent = nullptr);
    void init(const QString& common, const QString& hight_light, const QString& text);
    void setWidthSize(int width, int height);
    void setIconSize(int width, int height);
protected:
    // 鼠标悬停，点击，离开事件。主要是样式改变。
    void mousePressEvent(QMouseEvent* event) override;
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event) override;

private:
    void setBtnIcon();

private:
    QPixmap m_common_icon;
    QPixmap m_high_light_icon;

    QVBoxLayout m_layout;
    QLabel m_btn;
    QLabel m_label;

    QString m_common_label;
    QString m_high_light_label;

    bool flag = false;
};

#endif // SIDEBUTTON_H
