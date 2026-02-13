#include <Eigen/Dense>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    double K1 = 3.0 / 2.0;
    double K2 = 3.0 / 6.0;
    double K3 = 3.0;
    double theta = 0.3 * M_PI;
    double K22 = K2 * cos(theta) * cos(theta) + K3 * sin(theta) * sin(theta);
    double K33 = K3 * cos(theta) * cos(theta) + K2 * sin(theta) * sin(theta);
    double dK = (K3 - K2) * sin(theta) * cos(theta);
    Eigen::Matrix3d v;
    v << K1, 0, 0, 0, K22, -dK, 0, -dK, K33;
    Eigen::Matrix3d C3;
    C3 << -0.5, -0.5 * sqrt(3), 0, 0.5 * sqrt(3), -0.5, 0, 0, 0, 1;
    Eigen::Matrix3d v01 = C3.transpose() * v * C3;
    Eigen::Matrix3d v12 = C3 * v * C3.transpose();
    Eigen::Matrix3d v0 = v01 + v;
    Eigen::Matrix3d v1 = v12 + v01;
    Eigen::Matrix3d v2 = v + v12;

    ofstream outputfile("phonon.txt");
    outputfile
        << "#kz, 3 eigenvalues(m=0), 3 eigenvalues(m=1), 3 eigenvalues(m=-1)"
        << endl;
    double c = 1.0;
    double tz = c / 3.0;
    int Nz = 100;
    double dkz = M_PI / c / (double)Nz;

    complex<double> zeta = complex(-0.5, 0.5 * sqrt(3));
    // Pの固有ベクトル
    Eigen::Matrix3cd u;
    u << 1.0 / sqrt(3), 1.0 / sqrt(3), 1.0 / sqrt(3), 1.0 / sqrt(3),
        zeta / sqrt(3), conj(zeta) / sqrt(3), 1.0 / sqrt(3),
        conj(zeta) / sqrt(3), zeta / sqrt(3);
    // C_3の固有ベクトル
    Eigen::Matrix3cd w;
    w << 0.0, 1.0 / sqrt(2), 1.0 / sqrt(2), 0.0, complex(0.0, -1.0 / sqrt(2)),
        complex(0.0, 1.0 / sqrt(2)), 1.0, 0.0, 0.0;
    // m=0
    Eigen::MatrixXcd P0(9, 3);
    for(int i = 0; i < 9; i++)
        P0(i, 0) = u(i / 3, 0) * w(i % 3, 0);
    for(int i = 0; i < 9; i++)
        P0(i, 1) = u(i / 3, 1) * w(i % 3, 2);
    for(int i = 0; i < 9; i++)
        P0(i, 2) = u(i / 3, 2) * w(i % 3, 1);
    // m=1
    Eigen::MatrixXcd P1(9, 3);
    for(int i = 0; i < 9; i++)
        P1(i, 0) = u(i / 3, 0) * w(i % 3, 1);
    for(int i = 0; i < 9; i++)
        P1(i, 1) = u(i / 3, 1) * w(i % 3, 0);
    for(int i = 0; i < 9; i++)
        P1(i, 2) = u(i / 3, 2) * w(i % 3, 2);
    // m=-1
    Eigen::MatrixXcd P2(9, 3);
    for(int i = 0; i < 9; i++)
        P2(i, 0) = u(i / 3, 0) * w(i % 3, 2);
    for(int i = 0; i < 9; i++)
        P2(i, 1) = u(i / 3, 1) * w(i % 3, 1);
    for(int i = 0; i < 9; i++)
        P2(i, 2) = u(i / 3, 2) * w(i % 3, 0);

    for(int m = -Nz; m <= Nz; m++) {
        double kz = m * dkz;
        complex<double> gamma = exp(complex(0.0, 1.0) * kz * tz);

        Eigen::MatrixXcd VL1(9, 9);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                VL1(i, j) = v0(i, j);
                VL1(i, j + 3) = -gamma * v01(i, j);
                VL1(i, j + 6) = -conj(gamma) * v(i, j);
                VL1(i + 3, j) = -conj(gamma) * v01(i, j);
                VL1(i + 3, j + 3) = v1(i, j);
                VL1(i + 3, j + 6) = -gamma * v12(i, j);
                VL1(i + 6, j) = -gamma * v(i, j);
                VL1(i + 6, j + 3) = -conj(gamma) * v12(i, j);
                VL1(i + 6, j + 6) = v2(i, j);
            }
        }

        outputfile << kz;
        // m=0
        Eigen::SelfAdjointEigenSolver<Eigen::MatrixXcd> eigensolver0(
            P0.adjoint() * VL1 * P0);
        if(eigensolver0.info() != Eigen::Success)
            abort();
        for(int i = 0; i < 3; i++)
            outputfile << ", " << sqrt(eigensolver0.eigenvalues()[i]);
        // m=1
        Eigen::SelfAdjointEigenSolver<Eigen::MatrixXcd> eigensolver1(
            P1.adjoint() * VL1 * P1);
        if(eigensolver1.info() != Eigen::Success)
            abort();
        for(int i = 0; i < 3; i++)
            outputfile << ", " << sqrt(eigensolver1.eigenvalues()[i]);
        // m=-1
        Eigen::SelfAdjointEigenSolver<Eigen::MatrixXcd> eigensolver2(
            P2.adjoint() * VL1 * P2);
        if(eigensolver2.info() != Eigen::Success)
            abort();
        for(int i = 0; i < 3; i++)
            outputfile << ", " << sqrt(eigensolver2.eigenvalues()[i]);

        outputfile << endl;
    }
    outputfile.close();
}