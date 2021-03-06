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

    capture = cvCaptureFromCAM(cam);
    if(!capture) cout << "No camera detected" << endl;
    cvNamedWindow( "result", 1 );

    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 640);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 480);

    int frame_width = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
    int frame_height = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);

    if(capture) {
        cout << "We've got a camera!" << endl;
        // int FPS = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);

        char filename[100];
        sprintf(filename, "video-%ld.avi", time(0));

        CvVideoWriter *writer = 0;
        writer = cvCreateVideoWriter(filename, CV_FOURCC('D', 'I', 'V', 'X'),
                                        30, cvSize(frame_width,frame_height), 1);

        cout << "Saving frames to file " << filename << endl;
        while (1) {
            IplImage* iplImg = cvQueryFrame( capture );
            frame = iplImg;
            if(frame.empty())
                break;

            if(iplImg->origin == IPL_ORIGIN_TL)
                frame.copyTo(frameCopy);
            else
                flip(frame, frameCopy, 0);

            cvWriteFrame(writer, iplImg);
            imshow("result", frame);
            cvWaitKey(0);
        }
    }
    cvDestroyWindow("result");

    return 0;
}
