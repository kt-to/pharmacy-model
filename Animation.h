//
// Created by Владислав Отвагин on 07.10.2024.
//

#ifndef ANIMATION_H
#define ANIMATION_H

#include <QtWidgets>
#include <QObject>
#include <QThread>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

class Animation : public QObject {
    Q_OBJECT

public:
    explicit Animation(QObject *parent = nullptr) : QObject(parent) {}
    Animation(std::vector <QPoint>& v, QObject *parent = nullptr) : QObject(parent) {
            points = v;
    }
    public slots:
        void startAnimation(QLabel *&targetObject, std::vector <QGraphicsItem*> &item) {
            QSequentialAnimationGroup *animationGroup = new QSequentialAnimationGroup;
                for(int i = 1; i < points.size(); ++i){
                    animation = new QPropertyAnimation(targetObject, "pos");
                    int dur = (int) (fmax(abs(points[i-1].x() - points[i].x()), abs(points[i-1].y() - points[i].y())));
                    animation->setDuration(dur * 2);
                    animation->setStartValue(points[i-1]);
                    animation->setEndValue(points[i]);
                    animationGroup->addAnimation(animation);
                }
            animationGroup->start();

            // animationGroup->deleteLater();

        connect(animation, &QSequentialAnimationGroup::finished, this, &Animation::animationFinished);
    }
    signals:
        void animationFinished();

private:
    std::vector <QPoint> points;
    QPropertyAnimation *animation;
    QPropertyAnimation *process;

//ура
};



#endif //ANIMATION_H
