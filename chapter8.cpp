#if 1
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
#include <opencv2/objdetect.hpp>
using namespace std;
using namespace cv;
/////////////////   Image    ////////////////////
void main() {
	string path = "face.png";
	Mat img,imge = imread(path);
	resize(imge, img, Size(), 0.6, 0.6);

	CascadeClassifier faceCascade;
	faceCascade.load("haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) {
		cout << "XML file not loaded" << endl;
	}

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);
	
	for (int i = 0; i< faces.size(); i++) {
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}

	imshow("Image", img);
	waitKey(0);
}

#endif

