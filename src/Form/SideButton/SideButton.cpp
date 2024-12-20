#include "SideButton.h"

SideButton::SideButton(QWidget *parent)
    : QWidget{parent} {

    // 设置布局
    m_layout.addWidget(&m_btn);
    m_layout.addWidget(&m_label);
    setLayout(&m_layout);

    m_layout.setContentsMargins(5, 5, 5, 5);
    m_layout.setSpacing(5);

    // 设置对齐方式为居中
    m_layout.setAlignment(Qt::AlignCenter);  // 使按钮和标签居中

    // 设置初始大小
    m_btn.setFixedSize(30, 30);
    m_label.setFixedSize(30, 30);

    m_common_label = "font-size: 14px; color: black;";
    m_high_light_label = "font-size: 14px; color: #0078D4;";

    m_btn.setStyleSheet("background-color: transparent;");
    m_label.setStyleSheet(m_common_label);
    m_label.setAlignment(Qt::AlignCenter);
}

void SideButton::init(const QString& common, const QString& hight_light, const QString &text) {
    m_common_icon = QPixmap(common);
    m_high_light_icon = QPixmap(hight_light);
    m_label.setText(text);
    flag = false;
    setBtnIcon();
}

void SideButton::setWidthSize(int width, int height)
{

}

void SideButton::setIconSize(int width, int height)
{
    m_btn.setFixedWidth(width);
    m_btn.setFixedHeight(height);
    setBtnIcon();
}


// 处理鼠标点击事件,点击区域内就相当于点击按钮
void SideButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (flag) {
            flag = false;
            setBtnIcon();
            m_label.setStyleSheet(m_common_label);
        } else {
            flag = true;
            setBtnIcon();
            m_label.setStyleSheet(m_high_light_label);
        }
    }
}

void SideButton::enterEvent(QEvent *event)
{
    setStyleSheet("background-color: #EBEDF1;");
}

void SideButton::leaveEvent(QEvent *event)
{
    setStyleSheet("background-color: transparent;");
}

void SideButton::setBtnIcon()
{
    QSize buttonSize = m_btn.size(); // 获取 QLabel 的尺寸

    if (flag) {
        QPixmap scaledPixmap = m_high_light_icon.scaled(buttonSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        m_btn.setPixmap(scaledPixmap); // 设置缩放后的图片
    } else {
        QPixmap scaledPixmap = m_common_icon.scaled(buttonSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        m_btn.setPixmap(scaledPixmap); // 设置缩放后的图片
    }
}

