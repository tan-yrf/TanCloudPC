#include "SideButton.h"

SideButton::SideButton(QWidget *parent)
    : QWidget{parent} {

    // 设置布局
    m_layout.addWidget(&m_btn);
    m_layout.addWidget(&m_label);
    setLayout(&m_layout);

    m_layout.setContentsMargins(5, 5, 5, 5);
    m_layout.setSpacing(5);

    m_common_label = "font-size: 14px; color: black;";
    m_high_light_label = "font-size: 14px; color: #0078D4;";

    m_btn.setStyleSheet("background-color: transparent;");
    m_label.setStyleSheet(m_common_label);
    m_label.setAlignment(Qt::AlignCenter);
}

void SideButton::Init(const QString& common, const QString& hight_light, const QString &text) {
    m_common_icon = QIcon(common);
    m_high_light_icon = QIcon(hight_light);

    qDebug() << "common size" << QPixmap(common).size();
    qDebug() << "high light size " << QPixmap(hight_light).size();
    m_label.setText(text);
    m_btn.setIcon(m_common_icon);
}

// 处理鼠标点击事件,点击区域内就相当于点击按钮
void SideButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (flag) {
            m_btn.setIcon(m_common_icon);
            m_label.setStyleSheet(m_common_label);
            flag = false;
        } else {
            m_btn.setIcon(m_high_light_icon);
            m_label.setStyleSheet(m_high_light_label);
            flag = true;
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

