#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, const char * argv[]) {

    Mat Blob = imread("/Users/hazemkilzieh/Desktop/BlobDetAlgo/Blob4.jpg",IMREAD_GRAYSCALE);
    
    
    for (int r = 0; r < Blob.rows; r++) {
        for (int c = 0; c < Blob.cols; c++) {
            if(Blob.at<uint8_t>(r,c)>50) Blob.at<uint8_t>(r,c) = 255;
            else Blob.at<uint8_t>(r,c) = 0;
        }
    }
    
    float u = 0, v = 0;
    float uTempNumerator = 0, TempDenominator = 0, vTempNumerator = 0;
    
    for (int r = 0; r < Blob.rows; r++) {
        for (int c = 0; c < Blob.cols; c++) {
            uTempNumerator += (r*Blob.at<uint8_t>(r,c));
            TempDenominator += Blob.at<uint8_t>(r,c);
            vTempNumerator += (c*Blob.at<uint8_t>(r,c));
        }
    }
    
    u = uTempNumerator/TempDenominator;
    v = vTempNumerator/TempDenominator;
    
    cout<<"\n\n"<<"This is the Whole Matrix of the image\n"<<Blob<<endl;
    cout<<"This is the 1st column\n"<<Blob.col(0)<<endl;
    cout<<"The sum of pixel values in 1st column: "<<sum(Blob.col(0))[0]<<endl;
    cout<<"The number of White pixels in 1st columns:"<<sum(Blob.col(0))[0]/255<<endl;
    cout<<"The number of Rows in the image:"<<Blob.rows<<endl;
    cout<<"This is the u of Blob "<<u<<endl<<endl;
    
    cout<<"The sum of pixel values in the 40th row: "<<sum(Blob.row(39))[0]<<endl;
    cout<<"The number of White pixels in 40th row:"<<sum(Blob.row(39))[0]/255<<endl;
    cout<<"The number of Columns in the image:"<<Blob.cols<<endl;
    cout<<"This is the v of Blob:"<<v<<endl<<"-----------------------------------------------------"<<endl;
    
    Blob.at<uint8_t>(u,v) = 0;
    
    namedWindow("Blob", WINDOW_FREERATIO);
    imshow("Blob", Blob);
    waitKey();
    
    return 0;
}
    
