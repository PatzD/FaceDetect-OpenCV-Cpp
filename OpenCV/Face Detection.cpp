#include <opencv2/imgcodecs.hpp> 
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
#include <opencv2/objdetect.hpp>
#include <iostream> 

using namespace std;
using namespace cv;


void main() {

	VideoCapture cap(0);
	Mat img;

	while (true) {
		cap.read(img);
		CascadeClassifier faceCascade;
		faceCascade.load("Resources/haarcascade_frontalface_default.xml");
		if (faceCascade.empty())cout << "Xml file not loaded" << endl;

		vector<Rect> faces;
		faceCascade.detectMultiScale(img, faces, 1.1, 10);

		for (int i = 0; i < faces.size(); i++)
		{
			putText(img, "Face", faces[i].tl(), FONT_HERSHEY_PLAIN, 1, Scalar(256, 0, 0), 2);
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 2);
		}

		imshow("Image", img);
		waitKey(1);
	}

}

