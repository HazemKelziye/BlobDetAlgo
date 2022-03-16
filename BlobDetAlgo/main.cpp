#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, const char * argv[]) {

    Mat Blob = imread("/Users/hazemkilzieh/Desktop/BlobDetAlgo/PartialBlob2.jpg",IMREAD_GRAYSCALE);
    
    for (int r = 0; r < Blob.rows; r++) {
        for (int c = 0; c < Blob.cols; c++) {
            if(Blob.at<uint8_t>(r,c)>50) Blob.at<uint8_t>(r,c) = 255;
            else Blob.at<uint8_t>(r,c) = 0;
        }
    }
    
    float u = 0, v = 0;
    float uTempNumerator = 0, uTempDenominator = 0;
    
    for (int r = 0; r < Blob.rows; r++) {
        for (int c = 0; c < Blob.cols; c++) {
            uTempNumerator += (r*Blob.at<uint8_t>(r,c));
            uTempDenominator += Blob.at<uint8_t>(r,c);
        }
    }
    
    u = uTempNumerator/uTempDenominator;
    
    /*imshow("Blob", Blob);
    waitKey();*/
    
    cout<<"\n\n"<<"This is the Whole Matrix of the image\n"<<Blob<<endl;
    cout<<"This is the 1st column\n"<<Blob.col(0)<<endl;
    cout<<"This is the u of Blob "<<u<<endl;
    
    return 0;
}
    
