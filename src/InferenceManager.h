#ifndef INFERENCEMANAGER_H
#define INFERENCEMANAGER_H

#include <QObject>
#include <QThread>
#include "AsyncCameraCapture.h"
#include "InferenceWorker.h"

class InferenceManager : public QObject {
Q_OBJECT
    Q_PROPERTY(AsyncCameraCapture *camera READ camera WRITE setCamera)
    Q_PROPERTY(QAbstractVideoSurface *videoSurface READ videoSurface WRITE setVideoSurface)
    Q_PROPERTY(bool mirror READ mirror WRITE setMirror)
    Q_PROPERTY(bool virtualCamera READ virtualCamera WRITE setVirtualCamera)

public:
    ~InferenceManager() override;

    AsyncCameraCapture *camera();

    void setCamera(AsyncCameraCapture *camera);

    QAbstractVideoSurface *videoSurface();

    void setVideoSurface(QAbstractVideoSurface *videoSurface);

    bool mirror() const;

    void setMirror(bool mirror);

    bool virtualCamera() const;

    void setVirtualCamera(bool virtualCamera);

    void startWorkerIfReady();

private:
    AsyncCameraCapture *m_camera = nullptr;
    QAbstractVideoSurface *m_videoSurface = nullptr;
    bool m_mirror = false;
    bool m_virtualCamera = false;
    QScopedPointer<InferenceWorker> worker;
};


#endif //INFERENCEMANAGER_H