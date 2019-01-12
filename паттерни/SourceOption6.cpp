#include<iostream>
#include<string>
using namespace std;

class Phone
{
public:
	virtual void makeCall() = 0;
	virtual void endCall() = 0;
};

class VideoCamera
{
public:
	void turnOn()
	{
		cout << "Video camera turn on" << endl;
	}
	void turnOff()
	{
		cout << "Video camera turn off" << endl;
	}
};

class Skype
{
private:
	VideoCamera* videoCamera;
public:
	Skype(VideoCamera* videoCamera)
	{
		this->videoCamera = videoCamera;
	}
	void videoCallStart()
	{
		cout << "Video call start" << endl;
		videoCamera->turnOn();
	}
	void videoCallEnd()
	{
		videoCamera->turnOff();
		cout << "Video call end" << endl;
	}
	~Skype()
	{
		delete videoCamera;
	}
};

class PhoneAdapter : public Phone, private Skype
{
public:
	PhoneAdapter(VideoCamera* videoCamera) : Skype(videoCamera) {}
	void makeCall()
	{
		videoCallStart();
	}
	void endCall()
	{
		videoCallEnd();
	}
};

void main()
{
	VideoCamera* videoCamera = new VideoCamera;
	Phone* phone = new PhoneAdapter(videoCamera);
	phone->makeCall();
	phone->endCall();
	system("pause");
}