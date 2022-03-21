#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    string fileString = "SD.bmp";

    FILE* picture;
    picture = fopen(fileString.c_str(), "rb");

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, picture);

    int fileSize = *(int*)&header[2];
    int reserved = *(int*)&header[6];
    int fileOffset = *(int*)&header[10];

    int infoSize = *(int*)&header[14];
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    short int planes = *(short int*) &header[26];
    short int bitPerPixel = *(short int*) &header[28];

    int compression = *(int*) &header[30];
    int compressedSize = *(int*) &header[34];
    int xPixelsPerM = *(int*) &header[38];
    int yPixelsPerM = *(int*) &header[42];
    int colorsUsed = *(int*) &header[46];
    int importantColors = *(int*) &header[50];

    cout << "BMP Header Info For : " << fileString << endl;

    cout << endl;

    //Basic Header//
    cout << "Signature: " << header[0] << header[1] << endl;
    cout << "FileSize: " << fileSize << endl;
    cout << "Reserved: " << reserved << endl;
    cout << "DataOffset: " << fileOffset << endl;

    //Info Header//
    cout << endl;

    cout << "Info Size: " << infoSize << endl;
    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Planes: " << planes << endl;

    cout << "BitsPerPixel: " << bitPerPixel << endl;
    cout << "Compression Type: " << compression << endl;

    cout << "Compressed Image Size: " << compressedSize << endl;
    cout << "XpixelsPerM: " << xPixelsPerM << endl;
    cout << "YpixelsPerM: " << yPixelsPerM << endl;
    cout << "Colors Used: " << colorsUsed << endl;
    cout << "Important Colors: " << importantColors << endl;

}
