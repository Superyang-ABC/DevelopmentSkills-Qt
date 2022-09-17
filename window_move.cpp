//重写鼠标事件,实现除去标题栏后任然能实现窗口移动
void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mousePress = true;
    }
    //窗口移动距离
    movePoint = event->globalPos() - pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    mousePress = false;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(mousePress)
    {
        QPoint movePos = event->globalPos();//窗口初始位置
        move(movePos - movePoint);
    }
}