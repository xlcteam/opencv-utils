#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
using namespace cv;



int main(int argc, const char** argv)
{
    CvCapture* capture = 0;
    Mat frame, frameCopy, image;
    int cam = (argc > 1 ? atoi(argv[1]) : 0);
    int width = (argc > 2 ? atoi(argv[2]) : 640);
    int height = (argc > 3 ? atoi(argv[3]) : 480);

    capture = cvCaptureFromCAM(cam);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, width);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, height);

    if(!capture) cout << "No camera detected" << endl;

    if(capture) {
        cout << "We've got a camera!" << endl;
        int i = 0;
        time_t start = time(0);
        while (1) {
            IplImage* iplImg = cvQueryFrame( capture );
            frame = iplImg;
            if(frame.empty())
                break;

            if(iplImg->origin == IPL_ORIGIN_TL)
                frame.copyTo(frameCopy);
            else
                flip(frame, frameCopy, 0);

            if (time(0) - start == 2.0) {
                cout << "FPS: " << i/2.0 << endl;
                i = 0;
                start = time(0);
            }
        }
    }
    cvDestroyWindow("result");

    return 0;
}
