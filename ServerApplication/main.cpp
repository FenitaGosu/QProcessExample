#include <iostream>
#include <memory>

#include <QCoreApplication>
#include <QProcess>
#include <QTimer>

class ServerTask : public QObject
{
	Q_OBJECT

public:
	ServerTask(QObject* parent = 0)
		: QObject(parent)
	{
	}

public slots:
	void Run()
	{
		const std::unique_ptr<QProcess> ptrProcess = std::make_unique<QProcess>();

		ptrProcess->start("ClientApplication.exe", QProcess::Unbuffered | QProcess::ReadWrite);
		
		ptrProcess->waitForReadyRead(-1);
		std::cout << "[Server] Message received: " << ptrProcess->readAllStandardOutput().toStdString() << std::endl;

		ptrProcess->write(QByteArray::fromStdString("Hellow world!"));

		ptrProcess->waitForBytesWritten();
		ptrProcess->closeWriteChannel();

		ptrProcess->waitForReadyRead(-1);
		std::cout << "[Server] Message received: " << ptrProcess->readAllStandardOutput().toStdString() << std::endl;

		ptrProcess->waitForFinished(-1);

		emit finished();
	}

signals:
	void finished();
};

#include "main.moc"

int main(int argc, char* argv[])
{
	QCoreApplication app(argc, argv);

	ServerTask* pTask = new ServerTask(&app);

	QTimer::singleShot(0, pTask, &ServerTask::Run);

	QObject::connect(pTask, &ServerTask::finished, &app, &QCoreApplication::quit);

	return app.exec(); 
}
