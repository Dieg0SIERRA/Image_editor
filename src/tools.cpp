
#include "tools.h"

template class Tools<uint8_t>;
template class Tools<uint16_t>;

template <typename T>
Tools<T>::Tools()
{}

template <typename T>
void Tools<T>::saveImgFile(std::vector<T> input, std::string nameFile, int columns)
{
    std::ofstream file(nameFile);

    if (!file.is_open()) {
        std::cout << "Error to open file." << std::endl;
    }

    int j=0;
    for(int i=0; i<input.size(); ++i){
        if(j == columns){
            j = 0;
            file << "\n";
        }
        file << " " << int(input[i]);
        ++j;
    }
    file.close();
}

template <typename T>
Matrix_uint16 Tools<T>::convertVectToMatrix(Vect_uint16 vectInput, int rows, int columns)
{
    int count = 0;
    Matrix_uint16 output(rows, Vect_uint16(columns));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            output[i][j] = vectInput[count++];
        }
    }
    return output;
}

template <typename T>
std::vector<T> Tools<T>::convertMatrixToVect(std::vector<std::vector<T>> MatrixInput, int rows, int columns)
{
    std::vector<T> output;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            //for (int j = 0; j < columns; j +=16) {
            //Chargement simultané de 8 éléments en utilisant SSE2
            //__m128i simdData = _mm_loadu_si128((__m128i*)(&MatrixInput[j][i]));
            //_mm_storeu_si128((__m128i*)(&output[j * columns + i]), simdData);

            output.push_back(MatrixInput[i][j]);
        }
    }
    return output;
}

template <typename T>
T Tools<T>::arithmeticAverage4Pxl(T val_1, T val_2, T val_3, T val_4)
{
    return (val_1 + val_2 + val_3 + val_4)/4;
}

template <typename T>
T Tools<T>::geometricAverage4Pxl(T val_1, T val_2, T val_3, T val_4)
{
    return std::sqrt(val_1 + val_2 + val_3 + val_4);
}

template <typename T>
T Tools<T>::median4Pxl(T val_1, T val_2, T val_3, T val_4)
{
    std::vector<T> input;
    std::vector<T> output;

    input.push_back(val_1);
    input.push_back(val_2);
    input.push_back(val_3);
    input.push_back(val_4);

    std::sort(input.begin(), input.end());

    return (input[1] + input[2])/2;
}



