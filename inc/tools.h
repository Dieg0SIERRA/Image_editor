#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <QDebug>
#include <QImage>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QBuffer>

using Vect_uint8 = std::vector<uint8_t>;
using Vect_uint16 = std::vector<uint16_t>;
using Matrix_uint8 = std::vector<Vect_uint8>;
using Matrix_uint16 = std::vector<std::vector<uint16_t>>;

// Estructura para almacenar metadatos de la imagen
struct metadata {
    int width;
    int height;
    int depth;  // Profundidad de bits por píxel
};

template <typename T>
class Tools{
public:

    Tools();

    Matrix_uint16   convertVectToMatrix(Vect_uint16 vectInput, int rows, int columns);
    std::vector<T> convertMatrixToVect(std::vector<std::vector<T>> MatrixInput, int rows, int columns);

    void saveImgFile(std::vector<T> input, std::string nameFile, int columns);
    T arithmeticAverage4Pxl(T val_1, T val_2, T val_3, T val_4);
    T geometricAverage4Pxl(T val_1, T val_2, T val_3, T val_4);
    T median4Pxl(T val_1, T val_2, T val_3, T val_4);
};

#endif // TOOLS_H

